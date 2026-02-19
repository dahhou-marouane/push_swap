# Turk Algo Module (No Parsing)

This folder contains only the Turk sorting algorithm logic.

## What it does
- Sort strategy on pre-indexed stack nodes (`idx` in `[0..n-1]`)
- Cost computation (`cost_a`, `cost_b`)
- Cheapest-node move selection
- Combined rotations (`rr` / `rrr`)

## What it does not do
- No argv parsing
- No input validation/indexing
- No checker integration

## API
- `turk_sort(t_node **a, t_node **b, t_ops **ops)`
- `turk_node_new`, `turk_node_push_back`, `turk_node_free`
- `turk_ops_free`, `turk_ops_count`

## Build
```sh
cd turk_demo1
make
```
This creates `libturk_demo.a`.
