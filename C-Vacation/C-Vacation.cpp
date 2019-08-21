#include <iostream>
#include <vector>
#include <algorithm>
int solve(int N, std::vector<std::vector<int>> const& happiness) {
	// dp[i+1][j]: accumulated happiness by day i in case that activity j is taken at the day i,
	// where j=0, 1, and 2 represent activity A, B, and C, respectively.
	std::vector<std::vector<int>> dp(N, std::vector<int>(3, 0));
	dp[0][0] = happiness[0][0];
	dp[0][1] = happiness[0][1];
	dp[0][2] = happiness[0][2];
	for (long long i = 1; i < N; i++) {
		dp[i][0] = std::max(dp[i - 1][1], dp[i - 1][2]) + happiness[i][0];
		dp[i][1] = std::max(dp[i - 1][2], dp[i - 1][0]) + happiness[i][1];
		dp[i][2] = std::max(dp[i - 1][0], dp[i - 1][1]) + happiness[i][2];
	}
	return std::max(dp[N - 1LL][0], std::max(dp[N - 1LL][1], dp[N - 1LL][2]));
}
int main(void) {
	int N;
	std::cin >> N;
	// happiness[i+1][j] is a happiness which is given by taking activity j at the day i.
	std::vector<std::vector<int>> happiness(N, std::vector<int>(3, 0));
	for (int i = 0; i < N; i++) {
		std::cin >> happiness[i][0] >> happiness[i][1] >> happiness[i][2];
	}
	std::cout << solve(N, happiness) << std::endl;
	return 0;
}
