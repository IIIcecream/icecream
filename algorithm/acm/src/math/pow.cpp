#include "math\pow.h"
#include "ACMMathCommon.h"

bool CalcPow::solve()
{
    myPow(m_dX, m_n);
    return true;
}

// ����(n>0)
double pow1(double x, int n) {
    double r = 1.0;
    while (n--) r *= x;
    return r;
}

// һ��(n>0)
double pow2(double x, int n) {
    double r = 1.0;
    while (n != 0) {
        if (n % 2) r *= x;
        x *= x;
        n /= 2;
    }
    return r;
}

// �ݹ��
double getPow(double x, int n) {
    if (n == 1 || n == -1) return x;
    if (!n & 1) return getPow(x * x, n / 2);
    return getPow(x * x, n / 2) * x;
}

double pow3(double x, int n) {
    if (x == 0) return 0;
    if (x == 1 || n == 0) return 1.0;
    if (n < 0) x = 1 / x;
    return getPow(x, n);
}

// λ����
double pow4(double x, int n)
{
    //���账�� -2^31����Ϊ2^31�����
    if (n < 0)
    {
        if (n == INT_MIN) return 1.0 / (x * pow4(x, -(n + 1)));
        return 1.0 / pow4(x, -n);
    }

    double r = 1.0;
    while (n)
    {
        if (n & 1) r *= x;
        x *= x;
        n >>= 1;
    }
    return r;
}


double CalcPow::myPow(double x, int n)
{
    pow3(x, n);
}

