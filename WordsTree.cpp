#include "stdafx.h"
#include "WordsTree.h"
#include "Dictionary.h"

// constructor
WordsTree::WordsTree(Dictionary &dict) : m_root(0), m_dict(dict)
{
}

// destructor
WordsTree::~WordsTree()
{
    // delete tree nodes
    FreeNode(m_root);
    m_root = 0;
}

// find a chain from search word to destination word
bool WordsTree::FindChain(const string &src_word, const string &dst_word, vector<string> &chain)
{
    // clear result
    chain.clear();

    // create root if it doesn't exist
    if (!m_root)
        m_root = new Node(&dst_word);

    // build the words tree and search destination word:
    // root is destination word
    // each tree level contains all the words which differ from the parent word in a one letter
    // new word is created by iterating over all the letters in English alphabet and replacing one letter in parent word
    // build a tree and traverse it as breadth first
    // each time we create a new word we compare it with source word

    // clear queue
    while (!m_queue.empty())
        m_queue.pop();

    // push root node in the queue
    m_queue.push(m_root);

    // do breadth first search
    while (!m_queue.empty())
    {
        // dequeue node
        Node *node = m_queue.front();
        m_queue.pop();

        // process node
        if (FindChain(node, src_word, chain))
            return true;
    }

    return false;
}

// insert a new node into the tree
WordsTree::Node *WordsTree::InsertNode(Node *parent, const string *word)
{
    assert(parent);

    Node *new_node = new Node(word, parent);

    if (!parent->child)
        parent->child = new_node;
    else
    {
        Node *last_sibling = parent->child;
        while (last_sibling->sibling)
            last_sibling = last_sibling->sibling;

        last_sibling->sibling = new_node;
    }

    return new_node;
}

// free node
void WordsTree::FreeNode(Node *node)
{
    if (node)
    {
        FreeNode(node->child);
        FreeNode(node->sibling);
        delete node;
    }
}

// find a chain from search word to destination word
bool WordsTree::FindChain(Node *node, const string &src_word, vector<string> &chain)
{
    assert(node);

    // clear chain
    chain.clear();

    // generate a new word based on parent
    for (size_t i = 0; i < node->word->length(); ++i)
    {
        // iterate through all letters
        for (char c = 'a'; c < 'z'; ++c)
        {
            // get new word by one letter substitution
            string new_word(*node->word);

            // if letter is the same skip it
            if (new_word[i] == c)
                continue;

            new_word[i] = c;

            // check whether we found the destination word
            if (new_word.compare(src_word) == 0)
            {
                // found, fill the chain with the path to root node
                chain.push_back(new_word);
                GetChain(node, chain);
                return true;
            }

            // if new word is contained in the dictionary and isn't contained in the tree then insert it into the tree
            Dictionary::DictionaryData::iterator di;
            if (m_dict.Find(new_word, di) && !di->second)
            {
                Node *new_node = InsertNode(node, &di->first);
                m_queue.push(new_node);
                di->second = true;
            }
        }
    }

    return false;
}

// get the chain
void WordsTree::GetChain(const Node *node, vector<string> &chain) const
{
    for (; node; node = node->parent)
        chain.push_back(*node->word);
}
