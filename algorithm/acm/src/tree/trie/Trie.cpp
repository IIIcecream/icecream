#include "tree\trie\Trie.h"
#include <algorithm>

// LeetCode 208. Implement Trie (Prefix Tree)
Trie::Trie()
{
    m_pRoot = new TrieNode;   // 前缀树根节点
}

Trie::~Trie()
{
    delete m_pRoot;
}

bool Trie::solve()
{
    return true;
}

void Trie::insert(string word)
{
    if (word.empty()) return;

    TrieNode *pNode = m_pRoot;
    for (size_t i = 0; i < word.size(); ++i)
    {
        if (pNode->child[word[i] - 'a'] == nullptr) pNode->child[word[i] - 'a'] = new TrieNode();

        pNode = pNode->child[word[i] - 'a'];
    }
    pNode->bIsword = true;
}

bool Trie::search(string word)
{
    if (word.empty() || m_pRoot == nullptr) return false;

    TrieNode *pNode = m_pRoot;
    for (size_t i = 0; i < word.size(); ++i)
    {
        pNode = pNode->child[word[i] - 'a'];
        if (!pNode) return false;
    }
    return pNode->bIsword;
}

bool Trie::startsWith(string prefix)
{
    if (prefix.empty() || m_pRoot == nullptr) return false;

    TrieNode *pNode = m_pRoot;
    for (size_t i = 0; i < prefix.size(); ++i)
    {
        pNode = pNode->child[prefix[i] - 'a'];
        if (!pNode) return false;
    }

    return true;
}

