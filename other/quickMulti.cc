#include <func.hh>
using namespace std;
int quickMulti(int A, int B)
{
    int product = 0;

    for(; B; B >>= 1)
    {
        if(B & 1)
        {
            product += A;
        }
        A <<= 1;
    }

    return product;
}

int main(int argc, char *argv[])
{
    cout << quickMulti(10, 50) << endl;
    return 0;
}

