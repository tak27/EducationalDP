#include <iostream>
#include <vector>
#include <algorithm>
int solve(int N, int M, std::vector<int> const& x, std::vector<int> const& y) {
	// dp[i+1][j] is accumulated length to reach vertex j+1 using [1...j+1] edges.
	std::vector<std::vector<int>> dp(M + 1LL, std::vector<int>(N, 0));
	for (long long i = 0; i < M; i++) {
		for (long long j = 0; j < M; j++) {
			dp[i + 1][y[j] - 1LL] = std::max(dp[i + 1LL][y[j] - 1LL], dp[i][x[j] - 1LL] + 1);
		}
	}
	return *std::max_element(dp[M].begin(), dp[M].end());
}
int main(void) {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> x(M, 0);
	std::vector<int> y(M, 0);
	for (int i = 0; i < M; i++) {
		std::cin >> x[i] >> y[i];
	}
	std::cout << solve(N, M, x, y) << std::endl;
	return 0;
}
