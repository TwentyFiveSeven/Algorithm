#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX ((int)log2(500005))

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
	int m; cin >> m;
	vector<vector<int>> dp(m + 1, vector<int>(MAX + 1));
	for (int i = 1, x; i <= m; i++) {
		cin >> x;
		dp[i][0] = x;
	}
	for (int i = 1; i <= MAX; i++)
		for (int j = 1; j <= m; j++)
			dp[j][i] = dp[dp[j][i - 1]][i - 1];
	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		for (int i = 0; i <= MAX; i++){
      if((1<<i) > a) break;
			if (a & (1 << i)){
         b = dp[b][i];
      }
    }
		cout << b << '\n';
	}
	return 0;
}
