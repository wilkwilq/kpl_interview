#!/bin/bash
cmake ./unit_tests/CMakeLists.txt
make -C unit_tests/
./unit_tests/runTests
