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
// �����������Ϊ max(ǰЩ���������棬 ����۸�-ǰ�漸����͵ļ۸�
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
// ע�������Զ������������Ҫ��֤�´�����֮ǰҪȫ������
// �ⷨ1�� ����ά���飬����  �����������Ϊ f(i, j) iΪ�����գ�jΪ�۳��գ�ֻ�÷�����ά��������ϲ�������
//        dp(i, j) = max(dp(i, j - 1), dp(i - 1, j), dp(i, j - 1) + price[j] - price[j - 1]) �������ύ�����һ������ʧ�ܣ������ڴ����ƣ����鳤��Ϊ����࣬��ά����ͱ�ջ�ˣ�
// �ⷨ2�� ̰�ģ����ֲ�۾���������Ǿ����̰�ĳ���
int BuySellSrock::question2()
{
    int nRes1 = 0, nRes2 = 0, nLen = m_prices.size();

    // �ⷨ1
    vector<vector<int>> dp(nLen, vector<int>(nLen, 0));
    for(int i = 0; i < nLen; ++i)
        for (int j = i + 1; j < nLen; ++j)
        {
            if (i == 0) dp[0][j] = ACM::max(dp[0][j - 1], dp[0][j - 1] + m_prices[j] - m_prices[j - 1]);
            else dp[i][j] = dp[i][j] = ACM::max(dp[i - 1][j], ACM::max(dp[i][j - 1], dp[i][j - 1] + m_prices[j] - m_prices[j - 1]));
            nRes1 = ACM::max(nRes1, dp[i][j]);
        }
    return nRes1;

    // �ⷨ2
    for (int i = 1; i < nLen; ++i)
    {
        if (m_prices[i] > m_prices[i - 1]) nRes2 += m_prices[i] - m_prices[i - 1];
    }
    return nRes2;
}

// Best Time to Buy and Sell Stock3 LeeCode T123
// ��������������ʽ���,��Ҫ��֤�´�����֮ǰҪȫ������
int BuySellSrock::question3()
{
    int nRes = 0, nLen = m_prices.size();
   
    // �ⷨ1
    // A[i]��ʾ�ӵ�0�쵽��i����׬��������Ǯ(1�ν��ף� �� question1()
    // B[i]��ʾ�ӵ�i�쵽���һ����׬��������Ǯ(1�ν���)
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

    // �ⷨ2 ���ǻ�û���
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

