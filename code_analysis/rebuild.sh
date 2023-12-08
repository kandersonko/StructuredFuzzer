#!/bin/bash

# install tree-sitter-cli
# cargo install tree-sitter-cli

cd tree-sitter-structured-text

tree-sitter generate

gcc -o parser.so -shared src/parser.c -Isrc -fPIC
