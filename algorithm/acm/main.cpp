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

using namespace std;


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

    ConstructBinaryTree *pConstruct = new CBTfromPreInorder(preorder, inorder);
    pConstruct->solve();
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

    ConstructBinaryTree *pConstruct = new CBTfromInPostOrder(inorder, postOrder);
    pConstruct->solve();
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
}

void test115()
{
    string s("aacc"), t("ac");
    IACM *p = new DistinctSubsequnces(s, t);
    p->solve();
}

void test118()
{
    IACM *p = new PascalsTriangle(5);
    p->solve();
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
}

void test17()
{
    string s("213");
    IACM *p = new LetterCombinationsOfPhoneNumbers(s);
    p->solve();
}

int main()
{
    test17();
    return 0;
}

