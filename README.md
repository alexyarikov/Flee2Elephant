# Flee2Elephant
Приложение Flee2Elephant решает следующую задачу.

This application solves the following problem:

Given source and destination words specified length. Length of words has no limits.
The problem is to make a chain (path) from source word to destination word so that:

- each word in chain differs from a previous word in only one letter
- the source, the destination and all words in chain have the same length
- the source, the destination and all words in chain should exist in user-specified dictionary

The input:

- path to text file with source (first line) and destination words (second line).
- path to text file with words dictionary. Words are crlf-separated. Words can have different length.

The output:

- application prints to concole a chain from source word to destination word.

Build:
$make all

Run tests:
$make test

Run application:
./f2e words dict

Restrictions, todo's etc:

- will be better to use allocators for tree nodes and words strings
- the application works with English dictionary only
- as main algorithm, to search a words chain, I build a words tree with its breadth-first search. In the root of tree - destination word. Each next tree level is filled with words which differ from parent-word in one letter. In the same time I search for a source word in the tree. If word is found, I make a desired words chain traversing to the root of tree.
- as alternative way (not implemented), we could build a words graph. Graph vertices are bound if corresponding words in vertices differ in one word. So, after building of graph, we can just perform breadth-first searching of destination word. This solution if suitable for multiple words chain searches, as the O-complexity (for graph building) is O(n*n), where n - dictionary capacity.