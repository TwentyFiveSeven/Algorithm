#include <string>
#include <vector>
#include <iostream>
using namespace std;
int lcm(int a,int b,int c){
    return a*b/c;
}
int gcd(int a,int b){
    while(b !=0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

vector<int> V;
int solution(vector<int> arr) {
    int answer = 1;
    V = arr;
    if(arr.size() == 1) return arr[0];
    while(V.size() != 1){
        int a = V.back();
        V.pop_back();
        int b = V.back();
        V.pop_back();
        int val = lcm(a,b,gcd(a,b));
        V.push_back(val);
    }
    answer = V[0];
    return answer;
}
