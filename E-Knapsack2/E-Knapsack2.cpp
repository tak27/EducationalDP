#include <iostream>
#include <vector>
#include <algorithm>
int main(void) {
	long long N, W;
	std::cin >> N >> W;
	std::vector<long long> w(N, 0);
	std::vector<long long> v(N, 0);
	for (int i = 0; i < N; i++) {
		std::cin >> w[i] >> v[i];
	}
	long long minw = std::max(0LL, *std::min_element(w.cbegin(), w.cend()) - 1); // minwは重さの最小値。D-Knapsack1と比較して、E-Knapsack2では重さの合計が重さの最小値を下回るケースについてのdp配列を用意しない。
	std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(W + 1 - minw, 0)); // dp[i][j]: i個目に目を通した時点で重さの合計がj+minw以下になるよう荷物を選択した場合の価値の合計
	for (long long i = 0; i < N; i++) {
		for (long long j = minw; j <= W; j++) {
			if (w[i] <= j - minw) {
				dp[i + 1][j - minw] = std::max(
					dp[i][j - minw], // 荷物iは選ばない場合
					dp[i][j - w[i] - minw] + v[i]); // 荷物iを選ぶ場合
			}
			else if (w[i] <= j) {
				dp[i + 1][j - minw] = std::max(
					dp[i][j - minw], // 荷物iは選ばない場合
					v[i]); // 荷物iを選ぶ場合
			}
			else {
				dp[i + 1][j - minw] = dp[i][j - minw]; // 荷物iは重すぎて選べない
			}
		}
	}
	std::cout << dp[N][W - minw] << std::endl;
	return 0;
}
