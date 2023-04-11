#include <bits/stdc++.h>
using namespace std;

/*

b[i] = (a[i] + a[i+1]) % 2, where 1 <= i < N
b[N] = (a[N] + a[1]) % 2

----------------------------

2
1 0

a[1], a[2]
odd, even

NO

----------------------------

4
1 0 1 0

a[1], a[2], a[3], a[4]
even, odd, odd, even

YES

----------------------------

3
1 0 0

a[1], a[2], a[3]
even, odd, odd

NO

----------------------------

9
1 0 0 1 1 1 0 1 0

1 0 0 1 1 1 0 1 0
e o o o e o e e o

----------------------------

9
1 0 0 1 0 1 0 1 0

1 0 0 1 0 1 0 1 0
e o o o e e o o e

----------------------------

*/

void solve() {
	int n;
	cin >> n;
	int b[n];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	char parity[n];
	parity[0] = 'e';
	for (int i = 1; i < n; i++) {
		if (b[i-1] == 1) {
			parity[i] = parity[i-1] ^ ('e' ^ 'o');
		} else {
			parity[i] = parity[i-1];
		}
	}
	// for (char letter : parity)
	// 	cout << letter << " ";
	// cout << "\n";
	if (b[n-1] == 1 && parity[n-1] == parity[0]) {
		cout << "NO\n";
		return;
	}
	if (b[n-1] == 0 && parity[n-1] != parity[0]) {
		cout << "NO\n";
		return;	
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
