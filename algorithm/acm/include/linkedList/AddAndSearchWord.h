#pragma once

#include "IACM.h"
#include <string>
#include "tree/trie/Trie.h"
using std::string;

// 添加与搜索单词 - 数据结构设计
class AddAndSearchWord : public IACM
{
public:
    AddAndSearchWord() : m_pTrie(new TrieNode()) {}
    virtual bool solve() override;

    void addWord(string word);
    bool search(string word);
    bool search(string &word, size_t nIndex, TrieNode *pNode);

private:
    TrieNode *m_pTrie;
};