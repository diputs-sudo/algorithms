import { Step } from "./types.js";
import { Graph } from "./graph.js";

export class Controller {
    private generator: Generator<Step>;
    private graph: Graph;
    private intervalId: number | null = null;
    private speed: number = 300;
    private isRunning: boolean = false;

    constructor(generator: Generator<Step>, graph: Graph) {
        this.generator = generator;
        this.graph = graph;
    }

    public setSpeed(ms: number) {
        this.speed = ms;
    }

    public play() {
        if (this.isRunning) return;

        this.isRunning = true;

        this.intervalId = window.setInterval(() => {
            const result = this.generator.next();

            if (result.done || result.value.type === "done") {
                this.stop();
                this.graph.markSorted();
                return;
            }

            this.graph.render(
                result.value.array,
                result.value.indices,
                result.value.type
            );
        }, this.speed);
    }

    public pause() {
        if (this.intervalId !== null) {
            clearInterval(this.intervalId);
            this.intervalId = null;
        }
        this.isRunning = false;
    }

    public stop() {
        this.pause();
    }

    public step() {
        if (this.isRunning) return;

        const result = this.generator.next();

        if (result.done || result.value.type === "done") {
            this.graph.markSorted();
            return;
        }

        this.graph.render(
            result.value.array,
            result.value.indices,
            result.value.type
        );
    }

    public reset(newGenerator: Generator<Step>, initialArray: number[]) {
        this.pause();
        this.generator = newGenerator;
        this.graph.render(initialArray);
    }
}