#include <iostream>
#include <algorithm>
using namespace std;

int n,stair[301];
int dp[301];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stair[i];
    }

    dp[0] = stair[0];
    dp[1] = max(stair[0]+stair[1],stair[1]);
    dp[2] = max(stair[0]+stair[2],stair[1]+stair[2]);

    for (int i = 3; i < n; i++) {
        dp[i] = max(dp[i-2]+stair[i], stair[i-1]+stair[i]+dp[i-3]);
        // dp[i] = Max(dp[i-2]+stair[i],stair[i]+dp[i-1]);
        // dp[i-1]값은 stair[i]+stair[i-1]+stair[i-2] 가 연속적으로 등장해서 불가능.
    }
    printf("%d",dp[n-1]);

    return 0;
}
