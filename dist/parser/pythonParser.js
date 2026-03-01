export function parsePythonFile(code) {
    const result = {
        docstring: "",
        imports: [],
        constants: [],
        standardFunctions: [],
        verboseFunctions: []
    };
    // extract docstring
    const docMatch = code.match(/^\s*("""[\s\S]*?""")/);
    if (docMatch) {
        result.docstring = docMatch[1];
        code = code.slice(docMatch[0].length);
    }
    // extract imports
    const importMatches = code.match(/^import .*|^from .*$/gm);
    if (importMatches) {
        result.imports = importMatches;
    }
    // extract constants (simple uppercase vars)
    const constantMatches = code.match(/^[A-Z_]+\s*=.*$/gm);
    if (constantMatches) {
        result.constants = constantMatches;
    }
    // extract functions
    const functionBlocks = code.split(/(?=^def\s+)/gm);
    functionBlocks.forEach(block => {
        const nameMatch = block.match(/^def\s+([a-zA-Z0-9_]+)/);
        if (!nameMatch)
            return;
        const functionName = nameMatch[1];
        if (functionName.endsWith("_verbose")) {
            result.verboseFunctions.push(block.trim());
        }
        else {
            result.standardFunctions.push(block.trim());
        }
    });
    return result;
}
