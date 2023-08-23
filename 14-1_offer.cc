#include <func.hh>

using namespace std;

class Solution 
{
public:
    // n >= 2
    unsigned long long cuttingRope(unsigned long long n) 
    {
        vector<unsigned long long> vec;
        vec.reserve(n + 1);
        vec[1] = 1;
        for(unsigned long long i = 2; i <= n; ++i)
        {
            unsigned long long maxProduct = 1;
            for(unsigned long long j = 1; j <= i / 2; ++j)
            {
                unsigned long long product1 = vec[j] * vec[i - j];
                unsigned long long product2 = vec[j] * (i - j);
                unsigned long long product3 = j * vec[i - j];
                unsigned long long product4 = j * (i - j);
                if(product1 > maxProduct) maxProduct = product1;
                if(product2 > maxProduct) maxProduct = product2;
                if(product3 > maxProduct) maxProduct = product3;
                if(product4 > maxProduct) maxProduct = product4;
            }
            vec[i] = maxProduct;
            printf("vec[%d] = %d\n", i, vec[i]);
        }
        return vec[n];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.cuttingRope(10) << endl;
    return 0;
}

