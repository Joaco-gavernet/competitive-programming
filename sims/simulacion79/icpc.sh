#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
CXX="${CXX:-c++}"

run_after_build=0
if [[ "${1:-}" == "-r" || "${1:-}" == "--run" ]]; then
  run_after_build=1
  shift
fi

src="${1:-plantilla.cpp}"
if [[ "$src" != /* ]]; then
  src="$ROOT_DIR/$src"
fi

if [[ ! -f "$src" ]]; then
  echo "Source file not found: $src" >&2
  exit 1
fi

out="${src%.*}"

"$CXX" \
  -std=c++17 \
  -I"$ROOT_DIR" \
  -Wall \
  -Wextra \
  -pedantic \
  "$src" \
  -o "$out"

echo "Built $out"

if [[ "$run_after_build" == "1" ]]; then
  "$out"
fi
