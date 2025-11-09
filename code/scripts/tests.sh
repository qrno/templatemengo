#!/bin/bash

set -eu

make $1

for f in "$2"/*; do
    echo "=== $f ==="
    cat $f
    echo "=== Out ==="
    $1 < $f
done
