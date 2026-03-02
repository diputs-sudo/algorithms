import { extractHeaderComment } from "../parsers/headerParser.js";
export function initCodeLoader(category, algorithmName) {
    const codeDisplay = document.getElementById("codeDisplay");
    const langButtons = document.querySelectorAll(".lang-btn");
    if (!codeDisplay || langButtons.length === 0)
        return;
    async function loadCode(language) {
        try {
            const path = buildPath(language, category, algorithmName);
            const response = await fetch(path);
            if (!response.ok) {
                codeDisplay.textContent = "File not found.";
                return;
            }
            const text = await response.text();
            const { header, body } = extractHeaderComment(text, language);
            injectHeaderIntoMoreInfo(header);
            codeDisplay.innerHTML = highlightCode(body);
        }
        catch {
            codeDisplay.textContent = "Error loading file.";
        }
    }
    langButtons.forEach(btn => {
        btn.addEventListener("click", () => {
            langButtons.forEach(b => b.classList.remove("active"));
            btn.classList.add("active");
            const lang = btn.getAttribute("data-lang");
            loadCode(lang);
        });
    });
    loadCode("python");
    initCopyButton();
}
function toPascalCase(name) {
    return name
        .split("_")
        .map(word => word.charAt(0).toUpperCase() + word.slice(1))
        .join("");
}
function buildPath(language, category, algorithmName) {
    const extension = getExtension(language);
    let fileName = algorithmName;
    if (language === "java") {
        fileName = toPascalCase(algorithmName);
    }
    return new URL(`../../${language}/${category}/algorithm/${fileName}.${extension}`, window.location.href).href;
}
function getExtension(language) {
    const extensions = {
        python: "py",
        cpp: "cpp",
        java: "java",
        c: "c"
    };
    return extensions[language];
}
function injectHeaderIntoMoreInfo(header) {
    const moreInfo = document.querySelector(".more-info-content");
    if (!moreInfo)
        return;
    if (!header) {
        moreInfo.innerHTML = "";
        return;
    }
    const cleaned = header
        .replace(/\/\*|\*\//g, "")
        .replace(/"""/g, "")
        .trim();
    moreInfo.textContent = cleaned;
}
function highlightCode(code) {
    const keywords = new Set([
        "for", "while", "if", "else", "return",
        "def", "class", "public", "private",
        "static", "import", "from", "include",
        "using", "void", "new", "try", "catch"
    ]);
    const types = new Set([
        "int", "float", "double", "char",
        "bool", "String", "vector",
        "List", "ArrayList"
    ]);
    const lines = code.split("\n");
    return lines.map(line => {
        let result = "";
        let i = 0;
        while (i < line.length) {
            if (line[i] === '"' || line[i] === "'") {
                const quote = line[i];
                let j = i + 1;
                while (j < line.length && line[j] !== quote)
                    j++;
                const str = line.slice(i, j + 1);
                result += `<span class="code-string">${escapeHTML(str)}</span>`;
                i = j + 1;
                continue;
            }
            if (line.slice(i).startsWith("//") || line.slice(i).startsWith("#")) {
                const comment = line.slice(i);
                result += `<span class="code-comment">${escapeHTML(comment)}</span>`;
                break;
            }
            if (/[a-zA-Z_]/.test(line[i])) {
                let j = i;
                while (j < line.length && /[a-zA-Z0-9_]/.test(line[j]))
                    j++;
                const word = line.slice(i, j);
                if (keywords.has(word)) {
                    result += `<span class="code-keyword">${word}</span>`;
                }
                else if (types.has(word)) {
                    result += `<span class="code-type">${word}</span>`;
                }
                else if (line[j] === "(") {
                    result += `<span class="code-function">${word}</span>`;
                }
                else {
                    result += `<span class="code-variable">${word}</span>`;
                }
                i = j;
                continue;
            }
            if (/\d/.test(line[i])) {
                let j = i;
                while (j < line.length && /\d/.test(line[j]))
                    j++;
                const num = line.slice(i, j);
                result += `<span class="code-number">${num}</span>`;
                i = j;
                continue;
            }
            result += escapeHTML(line[i]);
            i++;
        }
        return result;
    }).join("\n");
}
function escapeHTML(text) {
    return text
        .replace(/&/g, "&amp;")
        .replace(/</g, "&lt;")
        .replace(/>/g, "&gt;");
}
function initCopyButton() {
    const copyBtn = document.getElementById("copyCodeBtn");
    const codeDisplay = document.getElementById("codeDisplay");
    if (!copyBtn || !codeDisplay)
        return;
    copyBtn.addEventListener("click", async () => {
        const text = codeDisplay.innerText;
        await navigator.clipboard.writeText(text);
        const tooltip = copyBtn.querySelector(".tooltip");
        tooltip.setAttribute("data-text-initial", "Copied!");
        setTimeout(() => {
            tooltip.setAttribute("data-text-initial", "Copy to clipboard");
        }, 1500);
    });
}
