"use strict";
const sortSelect = document.getElementById("sortSelect");
const grid = document.getElementById("algorithmGrid");
const searchInput = document.getElementById("searchInput");
function getCards() {
    return Array.from(grid.querySelectorAll(".card"));
}
function sortCards(criteria) {
    const cards = getCards();
    const sorted = cards.sort((a, b) => {
        if (criteria === "name") {
            const nameA = a.dataset.name?.toLowerCase() || "";
            const nameB = b.dataset.name?.toLowerCase() || "";
            return nameA.localeCompare(nameB);
        }
        if (criteria === "speed") {
            return Number(a.dataset.speed) - Number(b.dataset.speed);
        }
        if (criteria === "memory") {
            return Number(a.dataset.memory) - Number(b.dataset.memory);
        }
        if (criteria === "difficulty") {
            return Number(a.dataset.difficulty) - Number(b.dataset.difficulty);
        }
        return 0;
    });
    sorted.forEach(card => grid.appendChild(card));
}
sortSelect.addEventListener("change", () => {
    sortCards(sortSelect.value);
});
sortCards("name");
searchInput.addEventListener("input", () => {
    const query = searchInput.value.toLowerCase();
    const cards = getCards();
    cards.forEach(card => {
        const name = card.dataset.name?.toLowerCase() || "";
        const tags = card.textContent?.toLowerCase() || "";
        if (name.includes(query) || tags.includes(query)) {
            card.style.display = "";
        }
        else {
            card.style.display = "none";
        }
    });
});
