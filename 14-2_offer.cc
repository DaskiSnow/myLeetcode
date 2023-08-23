#include <func.hh>

using namespace std;

class Solution 
{
public:
    // n >= 2
    unsigned long long cuttingRope(unsigned long long n) 
    {
        int tempPower = n / 3;
        int lastLen = n % 3;
        if(lastLen == 0) return remainder(3, tempPower, 1000000007);
        if(lastLen == 1) return ( remainder(3, tempPower - 1, 1000000007) * 4 ) % 1000000007;
        if(lastLen == 2) return ( remainder(3, tempPower, 1000000007) * 2 ) % 1000000007;
    }
    
    unsigned long long remainder(int baseNumber, int power, int rhs)
    {
        int rem = 1;
        while(power > 1)
        {
            if(power % 2 == 0) 
            {
                // power为偶数
                rem = rem * rem % rhs;
                
            }
            else
            {
                // power为奇数
                rem = baseNumber * (rem * rem % rhs) % rhs;
                power = power - 1;
            }
            power /= 2;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.cuttingRope(10) << endl;
    return 0;
}

