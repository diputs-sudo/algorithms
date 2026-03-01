export function* quickSort(input) {
    const arr = [...input];
    function* partition(low, high) {
        const pivot = arr[high];
        let i = low;
        for (let j = low; j < high; j++) {
            yield {
                type: "compare",
                indices: [j, high],
                array: [...arr]
            };
            if (arr[j] < pivot) {
                [arr[i], arr[j]] = [arr[j], arr[i]];
                yield {
                    type: "swap",
                    indices: [i, j],
                    array: [...arr]
                };
                i++;
            }
        }
        [arr[i], arr[high]] = [arr[high], arr[i]];
        yield {
            type: "swap",
            indices: [i, high],
            array: [...arr]
        };
        return i;
    }
    function* sort(low, high) {
        if (low < high) {
            const pivotIndex = yield* partition(low, high);
            yield* sort(low, pivotIndex - 1);
            yield* sort(pivotIndex + 1, high);
        }
    }
    yield* sort(0, arr.length - 1);
    yield {
        type: "done",
        array: [...arr]
    };
}
