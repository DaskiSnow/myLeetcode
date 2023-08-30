#include <func.hh>

using namespace std;

// 加速幂运算(底数x, 指数n, x的n次幂)
int qpow(int x, int n)
{
    int res = 1;
    for(; n; n >>= 1, x *= x)
    {
        res *= x;
    }
    return res;
}

int main(int argc, char *argv[])
{
    cout << qpow(5, 3) << endl;
    return 0;
}

