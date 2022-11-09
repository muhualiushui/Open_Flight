CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -g -fstandalone-debug -O0 -Wall -Wextra -Werror

exec: bin/exec
# tests: bin/tests

bin/exec: ./src/Transform.cpp ./entry/main.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

# bin/tests: ./src/Transform.cpp ./tests/tests.cpp
# 	$(CXX) $(CXX_FLAGS) $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: exec clean

clean:
	rm -f bin/*

