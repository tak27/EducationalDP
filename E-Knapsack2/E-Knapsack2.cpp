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
	long long minw = std::max(0LL, *std::min_element(w.cbegin(), w.cend()) - 1); // minw�͏d���̍ŏ��l�BD-Knapsack1�Ɣ�r���āAE-Knapsack2�ł͏d���̍��v���d���̍ŏ��l�������P�[�X�ɂ��Ă�dp�z���p�ӂ��Ȃ��B
	std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(W + 1 - minw, 0)); // dp[i][j]: i�ڂɖڂ�ʂ������_�ŏd���̍��v��j+minw�ȉ��ɂȂ�悤�ו���I�������ꍇ�̉��l�̍��v
	for (long long i = 0; i < N; i++) {
		for (long long j = minw; j <= W; j++) {
			if (w[i] <= j - minw) {
				dp[i + 1][j - minw] = std::max(
					dp[i][j - minw], // �ו�i�͑I�΂Ȃ��ꍇ
					dp[i][j - w[i] - minw] + v[i]); // �ו�i��I�ԏꍇ
			}
			else if (w[i] <= j) {
				dp[i + 1][j - minw] = std::max(
					dp[i][j - minw], // �ו�i�͑I�΂Ȃ��ꍇ
					v[i]); // �ו�i��I�ԏꍇ
			}
			else {
				dp[i + 1][j - minw] = dp[i][j - minw]; // �ו�i�͏d�����đI�ׂȂ�
			}
		}
	}
	std::cout << dp[N][W - minw] << std::endl;
	return 0;
}
