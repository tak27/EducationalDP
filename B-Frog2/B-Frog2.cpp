#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
int solve(int N, int K, std::vector<int> const& h) {
	std::vector<int> dp(N, INT_MAX);
	dp[0] = 0;
	for (long long i = 1; i < N; i++) {
		dp[i] = dp[i - 1] + std::abs(h[i] - h[i - 1]);
		for (long long j = 2; j <= K && j <= i; j++) {
			dp[i] = std::min(dp[i], dp[i - j] + std::abs(h[i] - h[i - j]));
		}
	}
	return dp[N - 1LL];
}
int main(void) {
	int N, K;
	std::cin >> N >> K;
	std::vector<int> h(N, 0);
	for (int i = 0; i < N; i++) {
		std::cin >> h[i];
	}
	std::cout << solve(N, K, h) << std::endl;
	return 0;
}
