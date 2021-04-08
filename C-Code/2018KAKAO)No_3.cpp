#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<string> ans;
int sizeN,sizeM;

int dup(string temp){
  for(int i=0;i<ans.size();i++){
    int count=0;
    for(int j=0;j<ans[i].size();j++){
      if(temp.find(ans[i][j])!=-1) count++;
    }
    if(count == ans[i].size()) return 1;
  }
  return 0;
}


void solve(vector<vector<string>> S, vector<string> s,int depth,int n,string str,int now){
    if(depth == n){
        int flag = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                if(s[i].compare(s[j])==0) {
                    flag =1;
                    break;
                }
            }
            if(flag ==1) break;
        }
        if(flag ==0 ){
            ans.push_back(str);
        }
        return;
    }
    for(int i=now+1;i<sizeN;i++){
        vector<string> temps(s);
        string Stemp = str+to_string(i);
        int flag = 0;
        for(int j=0;j<ans.size();j++){
            if(ans[j].size()<=Stemp.size()){
              if(dup(Stemp)){
                flag = 1;
                break;
              }
            }
        }
        if(flag==1) continue;
        for(int j=0;j<sizeM;j++){
            temps[j]+=S[i][j];
        }
        solve(S,temps,depth+1,n,Stemp,i);
    }
}

int solution(vector<vector<string>> relation) {
    vector<vector<string>> S;
    int answer = 0;
    for(int i=0;i<relation[0].size();i++){
        vector<string> temp;
        for(int j=0;j<relation.size();j++){
            temp.push_back(relation[j][i]);
        }
        S.push_back(temp);
    }
    sizeN = S.size();
    sizeM = S[0].size();
    for(int i=0;i<S.size();i++){
        int flag = 0;
        for(int j=0;j<S[i].size();j++){
            for(int m=j+1;m<S[i].size();m++){
                if(S[i][j].compare(S[i][m])==0) {
                    flag =1;break;
                }
            }
            if(flag ==1) break;
        }
        if(flag == 0){
            ans.push_back(to_string(i));
            answer++;
        }
    }
    int Dsize = S.size()- ans.size();
    for(int depth =2;depth<=Dsize;depth++){
        for(int i=0;i<S.size()-1;i++){
            string check = to_string(i);
            int flag = 0;
            for(int j=0;j<ans.size();j++){
                if(ans[j].compare(check)==0) {
                    flag=1;break;
                }
            }
            if(flag ==1) continue;
            vector<string> s(S[i]);
            solve(S,s,1,depth,check,i);
        }
    }
    answer = ans.size();
    for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<endl;
    }
    return answer;
}
