#!/usr/bin/env bash

set -o errexit
set -o nounset

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

mkdir -p "$ROOT/build"
pushd "$ROOT/build"
cmake "$ROOT"
make
popd
