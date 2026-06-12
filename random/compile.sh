#!/usr/bin/env bash
set -euo pipefail

cmd_name=$(basename -- "$0")

usage() {
  echo "Usage: $cmd_name <source.cpp> [output]" >&2
  exit 2
}

if [[ $# -lt 1 || $# -gt 2 ]]; then
  usage
fi

src=$1
if [[ ! -f "$src" ]]; then
  echo "$cmd_name: source file not found: $src" >&2
  exit 1
fi

script_path=${BASH_SOURCE[0]}
while [[ -L "$script_path" ]]; do
  link_dir=$(cd -- "$(dirname -- "$script_path")" && pwd)
  link_target=$(readlink "$script_path")
  if [[ "$link_target" == /* ]]; then
    script_path=$link_target
  else
    script_path=$link_dir/$link_target
  fi
done

script_dir=$(cd -- "$(dirname -- "$script_path")" && pwd)
compiler=${CXX:-clang++}
out=${2:-${src%.*}}

"$compiler" \
  -std=c++17 \
  -O2 \
  -pipe \
  -Wall \
  -Wextra \
  -I"$script_dir" \
  "$src" \
  -o "$out"

echo "Built $out"
