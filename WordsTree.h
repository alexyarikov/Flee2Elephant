#pragma once

class Dictionary;

class WordsTree
{
public:
    // constructor/destructor
    WordsTree(Dictionary &dict);
    ~WordsTree();

    // find a chain from search word to destination word
    bool FindChain(const string &src_word, const string &dst_word, vector<string> &chain);

private:
    // tree node structure
    struct Node
    {
        const string *word;
        Node *parent;
        Node *child;
        Node *sibling;
        Node(const string *_word,
             Node *_parent = 0,
             Node *_child = 0,
             Node *_sibling = 0) { word = _word; parent = _parent; child = _child; sibling = _sibling; }
    };

    Node *m_root;           // tree root
    Dictionary &m_dict;     // dictionary reference
    queue<Node*> m_queue;   // queue for breadth first search

    // insert a new node into the tree
    Node *InsertNode(Node *parent, const string *word);

    // free node
    void FreeNode(Node *node);

    // find a chain from search word to destination word
    bool FindChain(Node *node, const string &src_word, vector<string> &chain);

    // get the chain
    void GetChain(const Node *node, vector<string> &chain) const;
};
