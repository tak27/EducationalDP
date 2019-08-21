#include <iostream>
#include <vector>
#include <algorithm>
int main(void) {
	int N, W;
	std::cin >> N >> W;
	std::vector<int> w(N, 0);
	std::vector<int> v(N, 0);
	for (int i = 0; i < N; i++) {
		std::cin >> w[i] >> v[i];
	}
	std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0)); // dp[i][j]: i個目に目を通した時点で重さの合計がj以下になるよう荷物を選択した場合の価値の合計
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= W; j++) {
			if (w[i] <= j) {
				dp[i + 1][j] = std::max(
					dp[i][j], // 荷物iは選ばない場合
					dp[i][j - w[i]] + v[i]); // 荷物iを選ぶ場合
			}
			else {
				dp[i + 1][j] = dp[i][j]; // 荷物iは重すぎて選べない
			}
		}
	}
	std::cout << dp[N][W] << std::endl;
	return 0;
}
