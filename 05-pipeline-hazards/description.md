# Pipeline Stalls and Hazards

## Concept
Modern CPUs pipeline instructions (fetch, decode, execute, writeback). Hazards occur when:
- **Data hazard**: Instruction needs result from previous instruction
- **Control hazard**: Branch outcome unknown (pipeline speculation)
- **Structural hazard**: Resource conflict

## What's Broken
The code has a data dependency chain that creates pipeline stalls.

## Learning Goal
Understand:
- How instruction pipelining works
- Why dependencies cause stalls
- How to write pipeline-friendly code

## Fix It
Restructure computations to reduce data dependencies.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
