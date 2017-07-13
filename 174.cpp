#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>

using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int M = dungeon.size();
		int N = dungeon[0].size();
		vector<vector<int>> dp(M+1,vector<int>((N+1),INT_MAX));
		dp[M][N - 1] = 1;
		dp[M - 1][N] = 1;
		for (int i = M - 1; i >= 0; --i) {
			for (int j = N - 1; j >= 0; --j) {
				int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
				dp[i][j] = need > 0 ? need : 1;
			}
		}
		return dp[0][0];
	}
};


int main() {
	vector<vector<int>> v = { 
	{-2,-3,3},
	{-5,-10,1},
	{10,30,-5}
	};
	vector<vector<int>> v1 = { {0,-3} };
	Solution s;
	cout << s.calculateMinimumHP(v1) << endl;

	return 0;
}