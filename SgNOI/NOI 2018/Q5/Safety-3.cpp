#include<bits/stdc++.h>

int N;
long long H;
std::vector<long long> S;

int main() {
	std::cin >> N >> H;
	for (int i = 0; i < N; ++i) {
		int tmp;
		std::cin >> tmp;
		S.push_back(tmp);
	}
	if (H == 0) {
		long long ave = 0;
		for (auto& i : S) {
			ave += i;
		}
		ave /= N;
		long long ans = 0;
		for (auto& i : S) {
			ans += std::abs(i - ave);
		}
		std::cout << ans << std::endl;

		return 0;
	}
	return 0;
}
