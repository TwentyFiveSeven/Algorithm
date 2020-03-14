#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;
string input[1001];
int main() {
	string s;
	int N;
	scanf("%d",&N);
	input[1] = "0";input[2] = "1";input[3] ="7";input[4] = "4";input[5] = "5";input[6] = "9";input[7] = "8";
	for(int i=2;i<=N;i++){
		for(int j=i-1;j>=i/2+i%2;j--){
			s =input[j];
      if(i-j != 1)
        s += input[i-j];
			if(input[i].size() == s.size()){
				if(input[i] <s)
					input[i] = s;
			}else{
				if(input[i].size() < s.size()){
					input[i] = s;
				}
			}
		}
	}
	cout<<input[N];
	return 0;
}
