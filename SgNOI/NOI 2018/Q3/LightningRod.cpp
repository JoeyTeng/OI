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

int main(){
	int N = readInt();
	int total = 1;
	int X = readInt();
	int Y = readInt();
	--N;
	for(int i = 0; i < N; i++) {
		int x = readInt();
		int y = readInt();
		if (covered(X, Y, x, y)) {
			continue;
		} else if (covered(x, y, X, Y)) {
			X = x;
			Y = y;
		} else {
			X = x;
			Y = y;
			++total;
		}
	}
	cout << total << endl;
	return 0;
}
