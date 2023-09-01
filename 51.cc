#include <func.hh>
using namespace std;

void printVec(vector<vector<string>> vec)
{
    for(auto v : vec)
    {
        for(auto item : v)
        {
            cout << item << endl;
        }
        cout << "-----------------" << endl;
    }
}

void print(vector<string> vec)
{
    for(auto & str : vec)
    {
        cout << str << endl;
    }
}
class Solution {
public:
    bool isValid(int rowIdx, int colIdx)
    {
        for(int i = 0; i < rowIdx; ++i)
        {
            int verticle = colIdx; // 2
            int lDiagonal = colIdx - (rowIdx - i); // 1
            int rDiagonal = colIdx + (rowIdx - i); // 3

            if(_solution[i][verticle] == 'Q') return false;
            if(lDiagonal >= 0 && _solution[i][lDiagonal] == 'Q') return false;
            if(rDiagonal <= _n - 1 && _solution[i][rDiagonal] == 'Q')  return false;
        }
        return true;
    }

    void backTrack(int rowIdx)
    {
        // 说明产生了一个解决方案
        if(rowIdx >= _n)
        {
            _ans.push_back(_solution);
            return;
        } 

        for(int colIdx = 0; colIdx < _n; ++colIdx)
        {
            if(isValid(rowIdx, colIdx))
            {
                _solution[rowIdx][colIdx] = 'Q';
                backTrack(rowIdx + 1);
                _solution[rowIdx][colIdx] = '.'; // 回溯到默认状态
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        _n = n;
        _solution = vector<string>(n, string(n, '.'));
        backTrack(0);
        return _ans;
    }

public:
    vector<string> _solution;
    vector<vector<string>> _ans;
    int _n;
};

int main(int argc, char *argv[])
{
    Solution s; 
    /* s.solveNQueens(4); */
    printVec(s.solveNQueens(4));

    return 0;
}

