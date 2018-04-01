// Accepted
#include <bits/stdc++.h>
using namespace std;
inline int readInt() {
    int x = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar_unlocked();
	}
    return x;
}

int covered(int x_i, int y_i, int x_j, int y_j) {
	// cout << x_i << ' ' << y_i << ' ' << x_j << ' ' << y_j << ' ' << (abs(x_j - x_i) <= (y_i - y_j)) << std::endl;
	return abs(x_j - x_i) <= (y_i - y_j);
}

int X[10000000 + 10];
int Y[10000000 + 10];

int main(){
	int N = readInt();
	int total = 0;
	X[0] = readInt();
	Y[0] = readInt();
	--N;
	for(int i = 0; i < N; i++) {
		int x = readInt();
		int y = readInt();
		if (covered(X[total], Y[total], x, y)) {
			continue;
		} else {
			while (covered(x, y, X[total], Y[total]) && total >= 0) {
				--total;
			}
			++total;
			X[total] = x;
			Y[total] = y;
		}
	}
	cout << total + 1 << endl;
	return 0;
}
