all: out/test out/main.hpp

out/test: out $(shell find test -name *.cpp)
	g++ -std=c++17 test/main.cpp -o out/test
	./out/test

out/main.hpp: out $(shell find src -name *.hpp)
	g++ -std=c++17 -E src/main.hpp -o out/main.hpp

out:
	mkdir -p out
