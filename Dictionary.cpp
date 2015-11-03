#include "stdafx.h"
#include "Dictionary.h"

// load dictionary from file into dictionary vector
bool Dictionary::Load(const string &path, size_t word_length, string &msg)
{
    // open file stream
    std::ifstream f(path.c_str());
    if(!f)
    {
        msg = "ERROR: failed to open dictionary file '%s'\r\n", path.c_str();
        return false;
    }

    // read words
    string line;
    while (getline(f, line))
    {
        // check word length
        if (line.length() != word_length)
            continue;

        // transform to lower case
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);

        // add word to dictionary
        m_data[line] = false;
    }

    return true;
}

// check that word is contained in the dictionary
bool Dictionary::Contains(const std::string &word) const
{
    DictionaryData::const_iterator i = m_data.find(word);
    return i != m_data.end();
}

// find a word in dictionary, returns pointer to this word and processed attribute
bool Dictionary::Find(const std::string &word, DictionaryData::iterator &dict_data)
{
    dict_data = m_data.find(word);
    return dict_data != m_data.end();
}
