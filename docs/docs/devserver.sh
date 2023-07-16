#!/usr/bin/bash

command -v bundle &> /dev/null || { echo "bundle is not installed or Jekyll is not correctly setup"; exit 1; }

bundle exec jekyll serve    --livereload \
                            --livereload-port 8080 \
                            --port 4000

