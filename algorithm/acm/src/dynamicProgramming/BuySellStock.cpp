#include "dynamicProgramming\BuySellStock.h"
#include "ACMMathCommon.h"

using namespace std;
bool BuySellSrock::solve()
{
    if (m_prices.size() == 0) return false;
    question1();
    question2();
    question3();
    return true;
}

// Best Time to Buy and Sell Stock LeeCode T121
// 当天最大收益为 max(前些天的最大收益， 当天价格-前面几天最低的价格）
int BuySellSrock::question1()
{
    int nRes = 0, nMinPrice = m_prices[0];
    for (int i = 1; i < (int)m_prices.size(); ++i)
    {
        nRes = ACM::max(nRes, m_prices[i] - nMinPrice);
        nMinPrice = ACM::min(nMinPrice, m_prices[i]);
    }
    return nRes;
}

// Best Time to Buy and Sell Stock2 LeeCode T122
// 注意该题可以多次买卖，但需要保证下次买入之前要全部卖出
// 解法1： 画二维数组，分析  当天最大收益为 f(i, j) i为购进日，j为售出日，只用分析二维数组的右上部三角形
//        dp(i, j) = max(dp(i, j - 1), dp(i - 1, j), dp(i, j - 1) + price[j] - price[j - 1]) 这个解答，提交后，最后一个用例失败，超出内存限制（数组长度为两万多，二维数组就爆栈了）
// 解法2： 贪心，出现差价就买进，这是经典的贪心场景
int BuySellSrock::question2()
{
    int nRes1 = 0, nRes2 = 0, nLen = m_prices.size();

    // 解法1
    vector<vector<int>> dp(nLen, vector<int>(nLen, 0));
    for(int i = 0; i < nLen; ++i)
        for (int j = i + 1; j < nLen; ++j)
        {
            if (i == 0) dp[0][j] = ACM::max(dp[0][j - 1], dp[0][j - 1] + m_prices[j] - m_prices[j - 1]);
            else dp[i][j] = dp[i][j] = ACM::max(dp[i - 1][j], ACM::max(dp[i][j - 1], dp[i][j - 1] + m_prices[j] - m_prices[j - 1]));
            nRes1 = ACM::max(nRes1, dp[i][j]);
        }
    return nRes1;

    // 解法2
    for (int i = 1; i < nLen; ++i)
    {
        if (m_prices[i] > m_prices[i - 1]) nRes2 += m_prices[i] - m_prices[i - 1];
    }
    return nRes2;
}

// Best Time to Buy and Sell Stock3 LeeCode T123
// 你最多可以完成两笔交易,需要保证下次买入之前要全部卖出
int BuySellSrock::question3()
{
    int nRes = 0, nLen = m_prices.size();
   
    // 解法1
    // A[i]表示从第0天到第i天能赚到的最多的钱(1次交易） 即 question1()
    // B[i]表示从第i天到最后一天能赚到的最多的钱(1次交易)
    vector<int> A(nLen, 0), B(nLen, 0);
    int nMin = m_prices[0];
    for (int i = 1; i < nLen; ++i)
    {
        A[i] = ACM::max(A[i - 1], m_prices[i] - nMin);
        nMin = ACM::min(nMin, m_prices[i]);
    }
    int nMax = m_prices[nLen - 1];
    for (int i = nLen - 2; i >= 0; --i)
    {
        B[i] = ACM::max(B[i + 1], nMax - m_prices[i]);
        nMax = ACM::max(nMax, m_prices[i]);
    }

    for (int i = 0; i < nLen; ++i)
    {
        nRes = ACM::max(nRes, A[i] + B[i]);
    }
    return nRes;

    // 解法2 但是还没理解
    int b1 = INT_MIN, b2 = INT_MIN;
    int s1 = 0, s2 = 0;

    for (int i = 0; i < nLen; i++) {
        b1 = ACM::max(b1, -m_prices[i]);
        s1 = ACM::max(s1, b1 + m_prices[i]);
        b2 = ACM::max(b2, s1 - m_prices[i]);
        s2 = ACM::max(s2, b2 + m_prices[i]);
    }
    return s2;
}

