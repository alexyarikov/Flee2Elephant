#include "stdafx.h"
#include "Fly2Elephant.h"

// constructor
Fly2Elephant::Fly2Elephant() : m_tree(m_dict)
{
}

// destructor
Fly2Elephant::~Fly2Elephant()
{
}

// transform source word to destination word
bool Fly2Elephant::Transform(const string &words_path, const string &dictionary_path, vector<string> &chain, string &msg)
{
    // load source/destination words and dictionary
    if (!LoadWords(words_path, msg))
        return false;

    // load dictionary
    if (!m_dict.Load(dictionary_path, m_src_word.length(), msg))
        return false;

    // check that source and destination words are contained in dictionary
    if (!m_dict.Contains(m_src_word) || !m_dict.Contains(m_dst_word))
    {
        msg = "ERROR: source and destination words should be contained in dictionary";
        return false;
    }

    // check if source and destination words are equal
    if (m_src_word.compare(m_dst_word) == 0)
    {
        chain.push_back(m_src_word);
        chain.push_back(m_dst_word);
        msg = "WARNING: source and destination words are equal";
        return true;
    }

    // search for a chain from source word to destination word
    return m_tree.FindChain(m_src_word, m_dst_word, chain);
}

// load source and destination words from file
bool Fly2Elephant::LoadWords(const string &path, string &msg)
{
    // clear result
    m_src_word.clear();
    m_dst_word.clear();

    // open file stream
    std::ifstream f(path.c_str());
    if (!f)
    {
        msg = "ERROR: failed to open words file " + path + "\r\n";
        return false;
    }

    // read file
    if (!getline(f, m_src_word) || !getline(f, m_dst_word) || m_src_word.empty() || m_dst_word.empty())
    {
        msg = "ERROR: failed to read source/destination words\r\n";
        return false;
    }

    // transform words to lower case
    std::transform(m_src_word.begin(), m_src_word.end(), m_src_word.begin(), (int(*)(int))std::tolower);
    std::transform(m_dst_word.begin(), m_dst_word.end(), m_dst_word.begin(), (int(*)(int))std::tolower);

    // check length
    if (m_src_word.length() != m_dst_word.length())
    {
        msg = "ERROR: source and destination strings have different length\r\n";
        return false;
    }

    return true;
}
