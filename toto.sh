#!/usr/bin/env bash
set -u -o pipefail

PUSH_SWAP="./push_swap"
CHECKER="./checker_linux"
ITERATIONS=10000
N=100
PROGRESS_EVERY=2000

# --- sanity checks ---
if [[ ! -x "$PUSH_SWAP" ]]; then
  echo "Error: $PUSH_SWAP not found or not executable" >&2
  exit 1
fi
if [[ ! -x "$CHECKER" ]]; then
  echo "Error: $CHECKER not found or not executable" >&2
  exit 1
fi

best_moves=-1
best_seq=""
count=0

for ((i=1; i<=ITERATIONS; i++)); do
  # Generate a random permutation of 1..N as a single line
  seq="$(shuf -i 1-"$N" | tr '\n' ' ' | sed 's/[[:space:]]*$//')"

  # Run push_swap once, capture output
  ops="$($PUSH_SWAP $seq)"
  moves="$(printf '%s\n' "$ops" | wc -l | tr -d ' ')"

  # Validate with checker using the SAME ops
  ok="$(printf '%s\n' "$ops" | $CHECKER $seq)"

  if [[ "$ok" != "OK" ]]; then
    echo "FAIL: checker returned '$ok'" >&2
    echo "SEQ: $seq" >&2
    exit 1
  fi

  ((count++))

  if (( moves > best_moves )); then
    best_moves=$moves
    best_seq="$seq"
    echo "NEW BEST: moves=$best_moves  seq=$best_seq"
  fi

  if (( i % PROGRESS_EVERY == 0 )); then
    echo "progress:$i tested:$count best:$best_moves"
  fi
done

echo "tested:$count"
echo "worst_moves:$best_moves"
echo "worst_seq:$best_seq"
