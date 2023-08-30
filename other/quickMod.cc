#include <func.hh>
using namespace std;

// 快速幂求余(x的n次幂 % p), x >= 1
int quickMod(int x, int n, int p)
{
    int res = 1;
    if(x == 1) return 1;
    for(; n; n >>= 1, x = x * x % p)
    {
        (n & 1) && (res = res * x % p);
    }
    return res;
}

int main(int argc, char *argv[])
{
    cout << quickMod(10, 3, 997) << endl;
    cout << quickMod(10, 2, 997) << endl;
    return 0;
}

