#include <iostream>
#include <vector>
#include <algorithm>
#include "binarySearch\binarySearch.h"
#include "tree\binaryTree\binaryTreeTraversal.h"
#include "tree\binaryTree\ConstructBinaryTree.h"
#include "tree\binaryTree\BinaryTreetoLinkedList.h"
#include "string\DistinctSubsequnces.h"
#include "others\PascalsTriangle.h"
#include "others\Triangle.h"
#include "dynamicProgramming\BuySellStock.h"
#include "tree\binaryTree\BinaryTreeMaximumPathSum.h"
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
#include "recursion\SudokuSolver.h"
#include "others\SpiralMatrix.h"
#include "recursion\WordSearch.h"
#include "others\UniqueBinarySearchTrees.h"
#include "others\ReverseWords.h"
#include "dynamicProgramming\HouseRobber.h"
#include "dynamicProgramming\MaxConsecutiveOnes.h"
#include "slidingWindow\MaXConsecutiveOnesIII.h"
#include "slidingWindow\MinimumWindowSubstring.h"
#include "slidingWindow\SlidingWindowMaximum.h"
#include "scheduling\LFUCache.h"
#include "stack\LargestRectangleInHistogram.h"
#include "stack\MaximalRectangle.h"
#include "binarySearch\FindPeakElement.h"
#include "linkedList\CloneRandomPointerList.h"
#include "graph\CourseSchedule.h"
#include "dynamicProgramming\MaximumProductSubarray.h"
#include "others\GameOfLife.h"
#include "graph\CourseScheduleII.h"
#include "others\LargestNumber.h"
#include "stack\BasicCalculator.h"
#include "linkedList\AddAndSearchWord.h"
#include "others\MultiplyStrings.h"
#include "recursion\DecodeWays.h"
#include "others\UglyNumber.h"
#include "tree\binaryTree\BinaryTreePaths.h"
#include "dynamicProgramming\LongestIncreasingSubsequence.h"
#include "others\RevealCardsInIncreasingOrder.h"

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

void test37()
{
    vector<vector<char>> board;

    vector<char> vec1(9, '.');
    vec1[2] = '7';
    vec1[3] = '2';
    vec1[7] = '1';
    vec1[8] = '3';
    vector<char> vec2(9, '.');
    vec2[2] = '4';
    vec2[3] = '7';
    vec2[7] = '6';
    vector<char> vec3(9, '.');
    vec3[0] = '6';
    vec3[3] = '8';
    vec3[7] = '5';
    vector<char> vec4(9, '.');
    vec4[2] = '9';
    vec4[4] = '8';
    vec4[5] = '1';
    vec4[8] = '4';
    vector<char> vec5(9, '.');
    vec5[1] = '2';
    vec5[5] = '5';
    vec5[7] = '7';
    vector<char> vec6(9, '.');
    vec6[0] = '8';
    vec6[5] = '2';
    vec6[6] = '5';
    vector<char> vec7(9, '.');
    vec7[1] = '4';
    vec7[5] = '9';
    vec7[8] = '2';
    vector<char> vec8(9, '.');
    vec8[1] = '9';
    vec8[5] = '7';
    vec8[6] = '1';
    vector<char> vec9(9, '.');
    vec9[0] = '7';
    vec9[1] = '6';
    vec9[5] = '8';
    vec9[6] = '3';
    
    board.push_back(vec1);
    board.push_back(vec2);
    board.push_back(vec3);
    board.push_back(vec4);
    board.push_back(vec5);
    board.push_back(vec6);
    board.push_back(vec7);
    board.push_back(vec8);
    board.push_back(vec9);

    IACM *p = new SudokuSolver(board);
    p->solve();
    SAFE_DELETE(p);
}

void test43()
{
    IACM *p = new MultiplyStrings("123", "456");
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

void test59()
{
    IACM *p = new SpiralMatrixII(3);
    p->solve();
    SAFE_DELETE(p);
}

void test76()
{
    IACM *p = new MinimumWindowSubstring("cabwefgewcwaefgcf", "cae");
    p->solve();
    SAFE_DELETE(p);
}

void test79()
{
    vector<vector<char>> board;

    vector<char> a = { 'A', 'B', 'C', 'E' };
    board.push_back(a);

    vector<char> b = { 'S', 'F', 'C', 'S' };
    board.push_back(b);

    vector<char> c = { 'A', 'D', 'E', 'E' };
    board.push_back(c);

    IACM *p = new WordSearch(board, "ABCCED");
    p->solve();
    SAFE_DELETE(p);
}

void test84()
{
    vector<int> heights;
    heights.push_back(4);
    heights.push_back(2);
    heights.push_back(0);
    heights.push_back(3);
    heights.push_back(2);
    heights.push_back(5);

    IACM *p = new LargestRectangleInHistogram(heights);
    p->solve();
    SAFE_DELETE(p);
}

void test85()
{
    vector<vector<char>> matrix;
    vector<char> a = {'1', '0', '1', '0', '0'};
    matrix.push_back(a);

    vector<char> b = {'1', '0', '1', '1', '1'};
    matrix.push_back(b);

    vector<char> c = {'1', '1', '1', '1', '1'};
    matrix.push_back(c);

    vector<char> d = {'1', '0', '0', '1', '0'};
    matrix.push_back(d);

    IACM *p = new MaximalRectangle(matrix);
    p->solve();
    SAFE_DELETE(p);
}

void tet91()
{
    IACM *p = new DecodeWays("12");
    p->solve();
    SAFE_DELETE(p);
}

void test96()
{
    IACM *p = new UniqueBinarySearchTrees(0);
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
    vector<int> preorder = { 3, 9, 4, 20, 15, 7 }, inorder = {4, 9, 3, 15, 20, 7};

    IACM *p = new CBTfromPreInorder(preorder, inorder);
    p->solve();
    SAFE_DELETE(p);
}

void test106()
{
    vector<int> inorder = { 4, 9, 3, 15, 20, 7 }, postOrder = {4, 9, 15, 7, 20, 3};

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
    vector<int> a = {2};  triangle.push_back(a);
    vector<int> b = {3, 4}; triangle.push_back(b);
    vector<int> c = {6, 5, 7}; triangle.push_back(c);
    vector<int> d = {4, 1, 8, 3}; triangle.push_back(d);

    IACM *p = new Triangle(triangle);
    p->solve();
    SAFE_DELETE(p);
}

void test123()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

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
    vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };

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
    vector<int> nums = {99, 1, 99, 1, 0, 1, 99};

    IACM *p = new SingleNumberII(nums);
    p->solve();
    SAFE_DELETE(p);
}

void test138()
{
    //RandomListNode *pNode4 = new RandomListNode(4, nullptr, nullptr);
    //RandomListNode *pNode3 = new RandomListNode(3, pNode4, nullptr);
    RandomListNode *pNode2 = new RandomListNode(2, nullptr, nullptr);
    RandomListNode *pNode1 = new RandomListNode(1, pNode2, nullptr);

    pNode2->random = pNode2;
    pNode1->random = pNode2;

    IACM *p = new CloneRandomPointerList(pNode1);
    p->solve();
    SAFE_DELETE(p);
}

void test139()
{
    //string word = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    string word = "catsandog";
    vector<string> wordDict = { "cats", "og", "sand", "and", "cat" };
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

void test151()
{
    string s(" 1");
    IACM *p = new ReverseWords(s);
    p->solve();

    SAFE_DELETE(p);
}

void test152()
{
    vector<int> nums = {2, -5, -2, -4, 3};

    IACM *p = new MaximumProductSubarray(nums);
    p->solve();
    SAFE_DELETE(p);
 }

void test162()
{
    vector<int> nums = { 1, 2, 3, 1 };
    //nums.push_back(2);
    //nums.push_back(5);

    IACM *p = new FindPeakElement(nums);
    p->solve();
    SAFE_DELETE(p);
}

void test179()
{
    vector<int> nums;
    int n = 100;
    while(n--) nums.push_back(0);

    IACM *p = new LargestNumber(nums);
    p->solve();
    SAFE_DELETE(p);
}

void test198()
{
    vector<int> nums = { 1, 2, 3, 1 };
    IACM *p = new HouseRobber(nums);
    p->solve();

    SAFE_DELETE(p);
}

void test207()
{
    vector<vector<int>> prerequisites;
    prerequisites.resize(1, vector<int>(2, 0));

    prerequisites[0][0] = 1;
    prerequisites[0][1] = 0;

    //prerequisites[1][0] = 1;
    //prerequisites[1][1] = 0;

    //prerequisites[2][0] = 3;
    //prerequisites[2][1] = 1;

    //prerequisites[3][0] = 3;
    //prerequisites[3][1] = 2;

    //prerequisites[4][0] = 1;
    //prerequisites[4][1] = 3;

    //prerequisites[5][0] = 2;
    //prerequisites[5][1] = 2;

    IACM *p = new CourseSchedule(2, prerequisites);
    p->solve();

    SAFE_DELETE(p);
}

void test210()
{
    vector<vector<int>> prerequisites;
    prerequisites.resize(1, vector<int>(2, 0));

    prerequisites[0][0] = 1;
    prerequisites[0][1] = 0;

    //prerequisites[1][0] = 2;
    //prerequisites[1][1] = 0;

    //prerequisites[2][0] = 3;
    //prerequisites[2][1] = 1;

    //prerequisites[3][0] = 3;
    //prerequisites[3][1] = 2;

    //prerequisites[4][0] = 1;
    //prerequisites[4][1] = 3;

    //prerequisites[5][0] = 2;
    //prerequisites[5][1] = 2;

    IACM *p = new CourseScheduleII(3, prerequisites);
    p->solve();

    SAFE_DELETE(p);
}

void tesst211()
{
    AddAndSearchWord *p = new AddAndSearchWord();
    
    p->addWord("a");
    p->search("ab");
    p->search("a");

    SAFE_DELETE(p);
}

void tesst224()
{
    IACM *p = new BasicCalculator("(1+(4+5+2)-3)+(6+8)");
    p->solve();

    SAFE_DELETE(p);
}

void test239()
{
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    IACM *p = new SlidingWindowMaximum(nums, 3);
    p->solve();

    SAFE_DELETE(p);
}

void tesst257()
{
    TreeNode *pNode1 = new TreeNode(1);
    TreeNode *pNode2 = new TreeNode(2);
    TreeNode *pNode3 = new TreeNode(3);
    TreeNode *pNode4 = new TreeNode(4);

    pNode1->left = pNode2;
    pNode1->right = pNode3;

    pNode2->right = pNode4;

    IACM *p = new BinaryTreePaths(pNode1);
    p->solve();

    SAFE_DELETE(p);
}

void test260()
{
    vector<int> nums = { 1, 2, 1, 3 };
    IACM *p = new SingleNumberIII(nums);
    p->solve();

    SAFE_DELETE(p);
}

void tesst264()
{
    IACM *p = new UglyNumberII(10);
    p->solve();

    SAFE_DELETE(p);
}

void test289()
{
    vector<int> vec1 = { 0, 1, 0 };

    vector<int> vec2 = { 0, 0, 1 };

    vector<int> vec3 = { 1, 1, 1 };

    vector<int> vec4 = { 0, 0, 0 };

    vector<vector<int>> board;
    board.push_back(vec1);
    board.push_back(vec2);
    board.push_back(vec3);
    board.push_back(vec4);

    IACM *p = new GameOfLife(board);
    p->solve();

    SAFE_DELETE(p);
}

void test300()
{
    vector<int> nums = { 10, 9, 2, 5, 3, 4 };

    IACM *p = new LongestIncreasingSubsequence(nums);
    p->solve();

    SAFE_DELETE(p);
}

void test460()
{
    LFUCache *p = new LFUCache(2);
    p->put(2, 1);
    p->put(1, 2);
    p->put(2, 3);
    p->put(4, 1);
    p->get(1);
    p->get(2);
    SAFE_DELETE(p);
}

void test485()
{
    vector<int> nums = { 1, 1, 0, 1, 1, 1 };
	IACM *p = new MaxConsecutiveOnes(nums);
	p->solve();

	SAFE_DELETE(p);
}

void test950()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    nums.insert(nums.begin() + 4, 5);
    IACM *p = new RevealCardsInIncreasingOrder(nums);
    p->solve();

    SAFE_DELETE(p);
    
}

void tes1004()
{
    vector<int> nums = { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };
    IACM *p = new MaxConsecutiveOnesIII(nums, 2);
    p->solve();

    SAFE_DELETE(p);
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](vector<int>& lhs, vector<int>& rhs) {
        return lhs[0] > rhs[0] || lhs[0] == rhs[0] && lhs[1] < rhs[1];
    });

    vector<vector<int>> res;
    for (vector<int>& item : people)
    {
        res.insert(res.begin() + item[1], move(item));
    }

    return res;
}

int main()
{
    vector<vector<int>> aaa = { {7,0}, {4,4},{7,1},{5,0},{6,1},{5,2} };
    
    reconstructQueue(aaa);
    test950();
    return 0;
}