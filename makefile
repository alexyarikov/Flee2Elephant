all:
		g++ -Wall -O3 -std=c++11 main.cpp Fly2Elephant.cpp Dictionary.cpp WordsTree.cpp -o f2e
test:
		g++ -Wall -DTEST -O3 -std=c++11 main.cpp Fly2Elephant.cpp Dictionary.cpp WordsTree.cpp Test.cpp -o f2e
		./f2e words dict
clean:
		rm -rf f2e
