#include <func.hh>

using namespace std;

// 加速幂运算(底数x, 指数n, x的n次幂), Leetcode 50. Pow(x, n)
double myPow(double x, long long n) {
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(n < 0) 
    {
        x = 1.0 / x;
        n = abs(n);
    }
    double res = 1.0;
    for(; n; n >>= 1, x *= x)
    {
        (n & 1) && (res *= x);
    }
    return res;
}

int main(int argc, char *argv[])
{
    cout << myPow(-2, 11) << endl;
    return 0;
}

