#include <iostream>
#include <vector>
#include <cmath>
int solve(int H, int W, std::vector<std::string> const& a) {
	int const denom = std::pow(10, 9) + 7;
	std::vector<std::vector<int>> dp(H, std::vector<int>(W, 0));
	dp[H - 1LL][W - 1LL] = 1;
	for (int y = H - 1; 0 <= y; y--) {
		for (int x = W - 1; 0 <= x; x--) {
			if (a[y][x] == '.') {
				int r = 0;
				if (x <= W - 2) {
					r = dp[y][x + 1LL];
				}
				int d = 0;
				if (y <= H - 2) {
					d = dp[y + 1LL][x];
				}
				dp[y][x] = (dp[y][x] + r + d) % denom;
			}
		}
	}
	return dp[0][0];
}
int main(void) {
	int H, W;
	std::cin >> H >> W;
	std::vector<std::string> a(H, std::string(""));
	for (int y = 0; y < H; y++) {
		std::cin >> a[y];
	}
	std::cout << solve(H, W, a) << std::endl;
	return 0;
}