all:
		g++ -Wall -O3 -std=c++11 main.cpp Fly2Elephant.cpp Dictionary.cpp WordsTree.cpp -o f2e
clean:
		rm -rf f2e