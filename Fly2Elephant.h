#pragma once

#include "Dictionary.h"
#include "WordsTree.h"

// class implements "fly to elephant" quiz words transformation
class Fly2Elephant
{
public:
    // constructor/destructor
    Fly2Elephant();
    ~Fly2Elephant();

    // transform function, returns transformations chain
    bool Transform(const string &words_path, const string &dictionary_path, vector<string> &chain);

private:
    // source and destination words
    string m_src_word;
    string m_dst_word;

    // dictionary
    Dictionary m_dict;

    // words tree
    WordsTree m_tree;

    // load source and destination words from file
    bool LoadWords(const string &path);
};
