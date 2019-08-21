#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
int solve(int N, std::vector<int> const& h) {
	std::vector<int> dp(N, INT_MAX);
	dp[0] = 0;
	for (long long i = 1; i < N; i++) {
		dp[i] = dp[i - 1] + std::abs(h[i] - h[i - 1]);
		if (2 <= i) dp[i] = std::min(dp[i], dp[i - 2] + std::abs(h[i] - h[i - 2]));
	}
	return dp[N - 1LL];
}
int main(void) {
	int N;
	std::cin >> N;
	std::vector<int> h(N, 0);
	for (int i = 0; i < N; i++) {
		std::cin >> h[i];
	}
	std::cout << solve(N, h) << std::endl;
	return 0;
}
