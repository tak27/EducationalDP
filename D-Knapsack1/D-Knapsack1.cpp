#include <iostream>
#include <vector>
#include <algorithm>
int solve(int N, int W, std::vector<int>& w, std::vector<int>& v) {
	// dp[i][j]: total value of items chosen from item 0 through i such that its total weight is lower than or equal to j.
	std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0));
	for (long long i = 0; i < N; i++) {
		for (long long j = 1; j <= W; j++) {
			if (w[i] <= j) {
				dp[i + 1][j] = std::max(
					dp[i][j], // the case that item i is not picked
					dp[i][j - w[i]] + v[i]); // the case that the item i is picked
			}
			else {
				dp[i + 1][j] = dp[i][j]; // the item i can not be carriesd due of its weight
			}
		}
	}
	return dp[N][W];
}
int main(void) {
	int N, W;
	std::cin >> N >> W;
	std::vector<int> w(N, 0);
	std::vector<int> v(N, 0);
	for (int i = 0; i < N; i++) {
		std::cin >> w[i] >> v[i];
	}
	std::cout << solve(N, W, w, v) << std::endl;
	return 0;
}
