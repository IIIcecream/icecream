#include <iostream>
#include <vector>
#include <algorithm>
#include "binarySearch\binarySearch.h"
#include "binaryTree\binaryTreeTraversal.h"
#include "binaryTree\ConstructBinaryTree.h"
#include "binaryTree\BinaryTreetoLinkedList.h"
#include "string\DistinctSubsequnces.h"
#include "others\PascalsTriangle.h"

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

int main()
{
    test118();
    return 0;
}

