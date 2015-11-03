#pragma once

class Dictionary
{
public:
    // constructor/destructor
    Dictionary() {};
    ~Dictionary() {};

    // dictionary type (key - word, value - processed attribute
    typedef unordered_map<string, bool> DictionaryData;

    // load dictionary from file
    bool Load(const string &path, size_t word_length, string &msg);

    // check that word is contained in the dictionary
    bool Contains(const std::string &word) const;

    // returns true if a word is contained in dictionary and is not processed yet
    bool Find(const std::string &word, DictionaryData::iterator &dict_data);

private:
    // dictionary data
    DictionaryData m_data;
};
