export class Controller {
    constructor(generator, graph) {
        this.intervalId = null;
        this.speed = 300;
        this.isRunning = false;
        this.generator = generator;
        this.graph = graph;
    }
    setSpeed(ms) {
        this.speed = ms;
    }
    play() {
        if (this.isRunning)
            return;
        this.isRunning = true;
        this.intervalId = window.setInterval(() => {
            const result = this.generator.next();
            if (result.done || result.value.type === "done") {
                this.stop();
                this.graph.markSorted();
                return;
            }
            this.graph.render(result.value.array, result.value.indices, result.value.type);
        }, this.speed);
    }
    pause() {
        if (this.intervalId !== null) {
            clearInterval(this.intervalId);
            this.intervalId = null;
        }
        this.isRunning = false;
    }
    stop() {
        this.pause();
    }
    step() {
        if (this.isRunning)
            return;
        const result = this.generator.next();
        if (result.done || result.value.type === "done") {
            this.graph.markSorted();
            return;
        }
        this.graph.render(result.value.array, result.value.indices, result.value.type);
    }
    reset(newGenerator, initialArray) {
        this.pause();
        this.generator = newGenerator;
        this.graph.render(initialArray);
    }
}
