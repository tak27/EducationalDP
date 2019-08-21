#include <iostream>
#include <vector>
std::string solve(std::string const& s, std::string const& t) {
	// dp[i+1][j+1]: the longest common substring between s[0...j] and t[0...j]
	std::vector<std::vector<std::string>> dp(s.length() + 1, std::vector<std::string>(t.length() + 1, ""));
	for (size_t i = 0; i < s.length(); i++) {
		for (size_t j = 0; j < t.length(); j++) {
			if (s[i] == t[j]) {
				dp[i + 1][j + 1] = dp[i][j] + s[i];
			}
			else {
				dp[i + 1][j + 1] = dp[i][j + 1].length() < dp[i + 1][j].length() ? dp[i + 1][j] : dp[i][j + 1];
			}
		}
	}
	return dp[s.length()][t.length()];
}
int main(void) {
	std::string s;
	std::string t;
	std::cin >> s;
	std::cin >> t;
	std::cout << solve(s, t) << std::endl;
	return 0;
}
