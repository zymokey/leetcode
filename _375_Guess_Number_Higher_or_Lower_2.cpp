/*
We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:
n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.
You end up paying $5 + $7 + $9 = $21.

Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int getMoneyAmount(int n) {
            int t[n+1][n+1];
            memset(t, 0, (n+1)*(n+1)*sizeof(int));
            for(int i = 2; i <= n; i++) {
                for(int j = i - 1; j > 0; j--) {
                    int globalMin = INT_MAX;
                    for(int k = j + 1; k < i; k++) {
                        int localMax = k + max(t[j][k - 1], t[k + 1][i]);   // j ~ k-1 and k+1 ~i
                        globalMin = min(localMax, globalMin);
                    }
                    t[j][i] = j + 1 == i ? j : globalMin;
                }
            }
            return t[1][n];
        }

        int getMoneyAmount_Recursive(int n) {
            vector<vector<int>> t(n + 1, vector<int> (n + 1, 0));
            return DP(t,1,n);
        }

        int DP(vector<vector<int>> &t, int s, int e) {
            if(s >= e) return 0;
            if(t[s][e]) return t[s][e];
            int res = INT_MAX;
            for(int i = s; i <= e; i++) {
                int localMax = i + max(DP(t, s, i - 1), DP(t, i + 1, e));
                res = min(localMax, res);
            }
            t[s][e] = res;
            return res;
        }

};

int main() {
    Solution sol;
    return 0;
}

/*
https://en.wikipedia.org/wiki/Dynamic_programming
https://en.wikipedia.org/wiki/Minimax
*/