#include<bits/stdc++.h>

int N;
int H;
std::vector<int> S;

int main() {
	std::cin >> N >> H;
	for (int i = 0; i < N; ++i) {
		int tmp;
		std::cin >> tmp;
		S.push_back(tmp);
	}
	if (H == 0) {
		int ave = 0;
		for (auto& i : S) {
			ave += i;
		}
		ave /= N;
		int ans = 0;
		for (auto& i : S) {
			ans += std::abs(i - ave);
		}
		std::cout << ans << std::endl;

		return 0;
	}
	return 0;
}
