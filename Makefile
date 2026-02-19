CXX ?= clang++
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:src/%.cpp=build/%.o)

all: build/blackjack

build/blackjack: $(OBJ)
	$(CXX) $^ -o $@

build/%.o: src/%.cpp | build
	${CXX} -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build
	