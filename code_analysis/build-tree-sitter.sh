#!/bin/bash

cd tree-sitter-structured-text

# tree-sitter --version
# tree-sitter generate

gcc -o parser.so -shared src/parser.c -Isrc -fPIC

cd ..
