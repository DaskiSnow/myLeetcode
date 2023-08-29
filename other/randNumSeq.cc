#include <func.hh>
#include <stdlib.h>
#include <time.h>

using namespace std;

// 题目: 生成一个1~n的不重复的随机序列, 除了传入的数组外不能额外申请存储空间, 要求时间复杂度为O(n)
// 解决方案: 先按序生成, 再执行随机交换
void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}


void getRandSeq(int arr[], int n)
{
    // 1. 按序生成
    for(int i = 1; i <=n; ++i)
    {
        arr[i-1] = i;
    }

    // 2. 随机交换
    srand(time(NULL));
    for(int i = n - 1; i >=1; --i)
    {
        swap(arr[i], arr[rand() % i]);
    }
}

void printArr(int arr[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    int arr[50] = {0};
    getRandSeq(arr, 50);
    printArr(arr, 50);

    return 0;
}

