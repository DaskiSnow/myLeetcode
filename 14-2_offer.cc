#include <func.hh>

using namespace std;

class Solution 
{
public:
    // 因为涉及大数求余, 尝试使用加速幂求余法, 因此要转换方法为贪心算法(3的n次幂对1e9+7取余)
    long long cuttingRope(long long n) 
    {
        if(n <= 3) return n - 1;
        long long quotient = n / 3;
        long long remainder = n - quotient * 3;
        (remainder == 1) && (quotient -= 1, remainder = 4);
        
        // 以下算法的本质：加速幂求余
        long long res = 1;
        long long x = 3;
        long long divisor = 1000000007;
        for(; quotient; quotient >>= 1, x = x * x % divisor)
        {
            (quotient & 1) && (res = res * x % divisor);
        }
        (remainder != 0) && (res = res * remainder % divisor);

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.cuttingRope(10) << endl;
    return 0;
}

