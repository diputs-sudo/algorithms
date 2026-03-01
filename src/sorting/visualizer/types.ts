export type StepType = "compare" | "swap" | "done";

export interface Step {
    type: StepType;
    indices?: number[];
    array: number[];
}