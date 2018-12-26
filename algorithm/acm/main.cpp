#include <iostream>
#include <vector>
#include <algorithm>
#include "binarySearch\binarySearch.h"
#include "binaryTree\binaryTreeTraversal.h"
#include "binaryTree\ConstructBinaryTree.h"
#include "binaryTree\BinaryTreetoLinkedList.h"
#include "string\DistinctSubsequnces.h"
#include "others\PascalsTriangle.h"
#include "others\Triangle.h"
#include "dynamicProgramming\BuySellStock.h"
#include "binaryTree\BinaryTreeMaximumPathSum.h"
#include "others\LetterCombinationsOfPhoneNumbers.h"
#include "stack\GenerateParentheses.h"
#include "stack\LongestValidParentheses.h"
#include "binarySearch\SearchInRotatedSortedArray.h"
#include "graph\WordLadder.h"
#include "recursion\PalindromePartitioning.h"
#include "others\SingleNumber.h"
#include "recursion\WordBreak.h"
#include "linkedList\LinkedListCycle.h"
#include "others\GroupAnagrams.h"

using namespace std;

void test17()
{
    string s("213");
    IACM *p = new LetterCombinationsOfPhoneNumbers(s);
    p->solve();
    SAFE_DELETE(p);
}

void test22()
{
    IACM *p = new GenerateParentheses(3);
    p->solve();
    SAFE_DELETE(p);
}

void test32()
{
    IACM *p = new LongestValidParentheses("()(())");
    p->solve();
    SAFE_DELETE(p);
}

void test33()
{
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    int nTarget = 4;
    IACM *p = new SearchInRotatedSortedArray(nums, nTarget);
    p->solve();
    SAFE_DELETE(p);
}

void test49()
{
    vector<string> strs;
    strs.push_back("");

    IACM *p = new GroupAnagrams(strs);
    p->solve();
    SAFE_DELETE(p);
}

void test103()
{
    TreeNode *pTree = new TreeNode(1);

    TreeNode *pNode2 = new TreeNode(2);
    TreeNode *pNode3 = new TreeNode(3);
    TreeNode *pNode4 = new TreeNode(4);
    TreeNode *pNode5 = new TreeNode(5);

    pTree->left = pNode2;
    pTree->right = pNode3;

    pNode2->left = pNode4;

    pNode3->right = pNode5;

    IACM *p = new ZigZagLevelOrderTraversal(pTree);
    p->solve();
    SAFE_DELETE(p);
}

void test105()
{
    vector<int> preorder, inorder;
    preorder.push_back(3);
    preorder.push_back(9);
    preorder.push_back(4);
    preorder.push_back(20);
    preorder.push_back(15);
    preorder.push_back(7);

    inorder.push_back(4);
    inorder.push_back(9);
    inorder.push_back(3);
    inorder.push_back(15);
    inorder.push_back(20);
    inorder.push_back(7);

    IACM *p = new CBTfromPreInorder(preorder, inorder);
    p->solve();
    SAFE_DELETE(p);
}

void test106()
{
    vector<int> inorder, postOrder;
    inorder.push_back(4);
    inorder.push_back(9);
    inorder.push_back(3);
    inorder.push_back(15);
    inorder.push_back(20);
    inorder.push_back(7);

    postOrder.push_back(4);
    postOrder.push_back(9);
    postOrder.push_back(15);
    postOrder.push_back(7);
    postOrder.push_back(20);
    postOrder.push_back(3);

    IACM *p = new CBTfromInPostOrder(inorder, postOrder);
    p->solve();
    SAFE_DELETE(p);
}

void test114()
{
    TreeNode *pNode1 = new TreeNode(1);
    TreeNode *pNode2 = new TreeNode(2);
    TreeNode *pNode3 = new TreeNode(3);
    TreeNode *pNode4 = new TreeNode(4);
    TreeNode *pNode5 = new TreeNode(5);
    TreeNode *pNode6 = new TreeNode(6);

    pNode1->left = pNode2;
    pNode1->right = pNode5;

    pNode2->left = pNode3;
    pNode2->right = pNode4;

    pNode5->right = pNode6;

    IACM *p = new BinaryTreetoLinkedList(pNode1);
    p->solve();
    SAFE_DELETE(p);
}

void test115()
{
    string s("aacc"), t("ac");
    IACM *p = new DistinctSubsequnces(s, t);
    p->solve();
    SAFE_DELETE(p);
}

void test118()
{
    IACM *p = new PascalsTriangle(5);
    p->solve();
    SAFE_DELETE(p);
}

void test120()
{
    vector<vector<int>> triangle;
    vector<int> a; a.push_back(2);  triangle.push_back(a);
    vector<int> b; b.push_back(3), b.push_back(4); triangle.push_back(b);
    vector<int> c; c.push_back(6), c.push_back(5), c.push_back(7); triangle.push_back(c);
    vector<int> d; d.push_back(4), d.push_back(1), d.push_back(8), d.push_back(3); triangle.push_back(d);

    IACM *p = new Triangle(triangle);
    p->solve();
    SAFE_DELETE(p);
}

void test123()
{
    vector<int> prices;
    prices.push_back(3);
    prices.push_back(3);
    prices.push_back(5);
    prices.push_back(0);
    prices.push_back(0);
    prices.push_back(3);
    prices.push_back(1);
    prices.push_back(4);

    IACM *p = new BuySellSrock(prices);
    p->solve();
    SAFE_DELETE(p);
}

void test124()
{
    TreeNode *pNode1 = new TreeNode(2);
    TreeNode *pNode2 = new TreeNode(-1);
    //TreeNode *pNode3 = new TreeNode(3);

    pNode1->left = pNode2;
    //pNode1->right = pNode3;

    IACM *p = new BTMaxPathSum(pNode1);
    p->solve();
    SAFE_DELETE(p);
}

void test127()
{
    string sBegin("hit"), sEnd("cog");
    vector<string> words;
    words.push_back("hot");
    words.push_back("dot");
    words.push_back("dog");
    words.push_back("lot");
    words.push_back("log");
    words.push_back("cog");

    IACM *p = new WordLadder(sBegin, sEnd, words);
    p->solve();
    SAFE_DELETE(p);
}

void test131()
{
    IACM *p = new PalindromePartitioning("aaa");
    p->solve();
    SAFE_DELETE(p);
}

void test137()
{
    vector<int> nums;
    nums.push_back(99);
    nums.push_back(1);
    nums.push_back(99);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(99);

    IACM *p = new SingleNumber2(nums);
    p->solve();
    SAFE_DELETE(p);
}

void test139()
{
    //string word = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    string word = "catsandog";
    vector<string> wordDict;
    wordDict.push_back("cats");
    wordDict.push_back("og");
    wordDict.push_back("sand");
    wordDict.push_back("and");
    wordDict.push_back("cat");
    //wordDict.push_back("a");
    //wordDict.push_back("aa");
    //wordDict.push_back("aaa");
    //wordDict.push_back("aaaa");
    //wordDict.push_back("aaaaa");
    //wordDict.push_back("aaaaaa");
    //wordDict.push_back("aaaaaaa");
    //wordDict.push_back("aaaaaaaa");
    //wordDict.push_back("aaaaaaaaa");
    //wordDict.push_back("aaaaaaaaaa");
    IACM *p = new WordBreak(word, wordDict);
    p->solve();
    SAFE_DELETE(p);
}

void test142()
{
    ListNode *pNode1 = new ListNode(1);
    ListNode *pNode2 = new ListNode(2);
    ListNode *pNode3 = new ListNode(3);
    ListNode *pNode4 = new ListNode(4);
    ListNode *pNode5 = new ListNode(5);
    ListNode *pNode6 = new ListNode(6);
    ListNode *pNode7 = new ListNode(7);
    pNode1->next = pNode2;
    pNode2->next = pNode3;
    pNode3->next = pNode4;
    pNode4->next = pNode5;
    pNode5->next = pNode6;
    pNode6->next = pNode7;
    pNode7->next = pNode4;

    IACM *p = new LinkedListCycleII(pNode1);
    p->solve();

    SAFE_DELETE(p);
}

int main()
{
    test49();
    return 0;
}