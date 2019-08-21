#include <iostream>
#include <vector>
#include <algorithm>
long long solve(long long N, long long W, std::vector<long long>& w, std::vector<long long>& v) {
	// minw is the minimum weight in the given weights, w.
	// This won't let allocate entries in dp array for cases that total weight is lower than the minimum weight in the given weights for memory saving sake.
	long long minw = std::max(0LL, *std::min_element(w.cbegin(), w.cend()) - 1);
	//  dp[i][j]: total value of items chosen from item 0 through i such that its total weight is lower than or equal to j.
	std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(W + 1 - minw, 0));
	for (long long i = 0; i < N; i++) {
		for (long long j = minw; j <= W; j++) {
			if (w[i] <= j - minw) {
				dp[i + 1][j - minw] = std::max(
					dp[i][j - minw], // the case that item i is not picked
					dp[i][j - w[i] - minw] + v[i]); // the case that the item i is picked
			}
			else if (w[i] <= j) {
				dp[i + 1][j - minw] = std::max(
					dp[i][j - minw], // the case that item i is not picked
					v[i]); // the case that the item i is picked
			}
			else {
				dp[i + 1][j - minw] = dp[i][j - minw]; // the item i can not be carriesd due of its weight
			}
		}
	}
	return dp[N][W - minw];
}
int main(void) {
	long long N, W;
	std::cin >> N >> W;
	std::vector<long long> w(N, 0);
	std::vector<long long> v(N, 0);
	for (int i = 0; i < N; i++) {
		std::cin >> w[i] >> v[i];
	}
	std::cout << solve(N, W, w, v) << std::endl;
	return 0;
}
