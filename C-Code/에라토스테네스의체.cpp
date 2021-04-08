#include <string>
#include <vector>
#include <math.h>

using namespace std;
int check[1000001];
int ans=0;
bool Check(int value){
    for(int i=2;i<=sqrt(value);i++){
        if(check[i] ==1) continue;
        for(int j= i+i;j<=value;j+=i){
            if(check[j] ==1)continue;
            check[j] = 1;
            ans--;
        }
    }
    return 1;
}

int solution(int n) {
    int answer = 0;
    int temp = 0;
    ans = n-1;
    Check(n);
    answer = ans;
    return answer;
}
