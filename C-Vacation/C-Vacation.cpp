#include <iostream>
#include <vector>
#include <algorithm>
int main(void) {
	int N;
	std::cin >> N;
	std::vector<std::vector<int>> happiness(N, std::vector<int>(3, 0)); // happiness[i+1][j]はi日目に活動jを実施して得られる幸福度。ただし、j=0、1、2は活動A、B、Cを表す。
	for (int i = 0; i < N; i++) {
		std::cin >> happiness[i][0] >> happiness[i][1] >> happiness[i][2];
	}
	std::vector<std::vector<int>> dp(N, std::vector<int>(3, 0)); // dp[i+1][j]: i日目に活動jを実施した場合の最大の累積の幸福度。ただし、j=0、1、2は活動A、B、Cを表す。
	dp[0][0] = happiness[0][0];
	dp[0][1] = happiness[0][1];
	dp[0][2] = happiness[0][2];
	for (int i = 1; i < N; i++) {
		dp[i][0] = std::max(dp[i - 1][1], dp[i - 1][2]) + happiness[i][0];
		dp[i][1] = std::max(dp[i - 1][2], dp[i - 1][0]) + happiness[i][1];
		dp[i][2] = std::max(dp[i - 1][0], dp[i - 1][1]) + happiness[i][2];
	}
	std::cout << std::max(dp[N - 1][0], std::max(dp[N - 1][1], dp[N - 1][2])) << std::endl;
	return 0;
}
