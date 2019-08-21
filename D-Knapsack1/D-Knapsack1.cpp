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
	std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0)); // dp[i][j]: i�ڂɖڂ�ʂ������_�ŏd���̍��v��j�ȉ��ɂȂ�悤�ו���I�������ꍇ�̉��l�̍��v
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= W; j++) {
			if (w[i] <= j) {
				dp[i + 1][j] = std::max(
					dp[i][j], // �ו�i�͑I�΂Ȃ��ꍇ
					dp[i][j - w[i]] + v[i]); // �ו�i��I�ԏꍇ
			}
			else {
				dp[i + 1][j] = dp[i][j]; // �ו�i�͏d�����đI�ׂȂ�
			}
		}
	}
	std::cout << dp[N][W] << std::endl;
	return 0;
}
