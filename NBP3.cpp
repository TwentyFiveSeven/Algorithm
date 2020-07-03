#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX ((int)log2(2000000000))

using namespace std;
int solution(int num, vector<int> mark) {
    int answer = -1,size = mark.size(), count =0;
    vector<vector<int>> dp(size + 1, vector<int>(MAX + 1));
	for(int i=1;i<=size;i++){
		dp[i][0] = mark[i-1]+1;
	}
	for (int i = 1; i <= MAX; i++)
	   for (int j = 1; j <= size; j++)
			dp[j][i] = dp[dp[j][i - 1]][i - 1];
    int a = num, b = 1;
	for (int i = 0; i <= MAX; i++){
	    if((1<<i) > a) break;
		if (a & (1 << i)){
	    b = dp[b][i];
	    }
	}
	answer = b-1;
    return answer;
}
