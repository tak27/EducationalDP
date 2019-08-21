#include <iostream>
#include <vector>
#include <numeric>
double solve(int N, std::vector<double> const& p) {
	int M = N / 2 + 1;
	// dp[i][j] is a probability to get j coins in back among the first i coins tossed
	std::vector<std::vector<double>> dp(N + 1LL, std::vector<double>(M, 0.0));
	dp[0][0] = 1.0;
	for (long long i = 0; i < N; i++) {
		for (long long j = 0; j < M; j++) {
			dp[i + 1][j] = dp[i][j] * p[i];
			if (1 <= j) {
				dp[i + 1][j] += dp[i][j - 1] * (1.0 - p[i]);
			}
		}
	}
	return std::accumulate(dp[N].begin(), dp[N].end(), 0.0);
}
int main(void) {
	int N;
	std::cin >> N;
	std::vector<double> p(N, 0.0);
	for (int i = 0; i < N; i++) {
		std::cin >> p[i];
	}
	std::cout.precision(10);
	std::cout << solve(N, p) << std::endl;
	return 0;
}
