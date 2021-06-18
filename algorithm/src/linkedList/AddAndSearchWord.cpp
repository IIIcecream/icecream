#include "linkedList/AddAndSearchWord.h"

bool AddAndSearchWord::solve()
{
    return true;
}

// LeetCode 211. Add and Search Word - Data structure design
void AddAndSearchWord::addWord(string word)
{
    if (word.empty()) return;

    TrieNode *pNode = m_pTrie;

    for (char c : word)
    {
        if (!pNode->child[c - 'a'])
        {
            pNode->child[c - 'a'] = new TrieNode();
        }

        pNode = pNode->child[c - 'a'];
    }
    pNode->bIsword = true;
}

bool AddAndSearchWord::search(string word)
{
    return search(word, 0, m_pTrie);
}

// ��֪������д�������Ǹ���������д Ϊʲô�᲻һ����һ��waһ��ac������ֻ�ǵݹ���һ�������
//bool AddAndSearchWord::search(string &word, size_t nIndex, TrieNode *pNode)
//{
//    if (pNode == nullptr) return false;
//    if (nIndex == word.size()) return pNode->bIsword;
//
//    if ('.' == word[nIndex])
//    {
//        for (int j = 0; j < 26; ++j)
//        {
//            if (search(word, nIndex + 1, pNode->child[j])) return true;
//        }
//        return false;
//    }
//    return search(word, nIndex + 1, pNode->child[word[nIndex] - 'a']);
//}

bool AddAndSearchWord::search(string &word, size_t nIndex, TrieNode *pNode)
{
    if (nIndex == word.size()) return pNode->bIsword;

    if ('.' == word[nIndex])
    {
        for (int j = 0; j < 26; ++j)
        {
            if (pNode->child[j] && search(word, nIndex + 1, pNode->child[j])) return true;
        }
        return false;
    }
    return pNode->child[word[nIndex] - 'a'] && search(word, nIndex + 1, pNode->child[word[nIndex] - 'a']);
}