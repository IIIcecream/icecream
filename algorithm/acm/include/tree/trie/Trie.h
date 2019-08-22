#pragma once

#include "IACM.h"
#include <string>
using namespace std;

// ǰ׺���ڵ㣨�ֵ�����
struct TrieNode {
    bool bIsword;
    TrieNode* child[26];
    TrieNode() : bIsword(false)
    {
        for (int i = 0; i < 26; i++) child[i] = nullptr;
    }
    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
            if(child[i]) delete child[i];
    }
};

// ʵ�� Trie (ǰ׺��)
class Trie : public IACM
{
public:
    Trie();
    ~Trie();

    virtual bool solve() override;

    /** Inserts a word into the trie. */
    void insert(string word);

    /** Returns if the word is in the trie. */
    bool search(string word);

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix);

private:
    TrieNode * m_pRoot;
};