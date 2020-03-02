#include<iostream>
#include<queue>
using namespace std;
queue<int> Q;

int main(){
 ios::sync_with_stdio(false);
 cin.tie(NULL);
 int n;
 char c;
 string s,tmp;
 cin>>n;
 n +=1;
 while(n--){
   getline(cin,s);
   tmp = s.substr(0,2);
   if(tmp == "pu"){
     tmp = s.substr(5,s.size()-5);
     Q.push(atoi(tmp.c_str()));
   }else if(tmp == "po"){
     if(Q.empty()) {
       cout<<"-1\n";
       continue;
     }
     cout<<Q.front()<<"\n";
     Q.pop();
   }else if(tmp == "si"){
     cout<<Q.size()<<"\n";
   }else if(tmp == "em"){
     cout<<Q.empty()<<"\n";
   }else if(tmp == "fr"){
     if(Q.empty()) {
       cout<<"-1\n";
       continue;
     }
     cout<<Q.front()<<"\n";
   }else if(tmp == "ba"){
     if(Q.empty()) {
       cout<<"-1\n";
       continue;
     }
     cout<<Q.back()<<"\n";
   }
 }
 return 0;
}
