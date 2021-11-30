all: test out/main.hpp

test: out/test
	./out/test

out/test: out $(wildcard test/**/*.hpp test/**/*.cpp)
	g++ -std=c++17 test/main.cpp -o out/test

out/main.hpp: out $(wildcard src/**/*.hpp)
	g++ -std=c++17 -E src/main.hpp -o out/main.hpp

out:
	mkdir -p out
