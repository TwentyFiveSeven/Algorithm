#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

string tmp;
set<string> temp;
vector<string> arr[51];
bool compare(string a,string b){  // compare 함수 만들기.
  // if(a.size()<b.size())
  int sizeN = a.size(),i;
    for(i=0;i<sizeN;i++){
      if(a.at(i) == b.at(i)) continue;
      else{
        return a.at(i)<b.at(i); // 내림차순
      }
    }
}

int main(){
  int n,i,j,value,maxN=0;
  scanf("%d", &n);

  for(i=1;i<=n;i++){
    cin>>tmp;
    temp.insert(tmp);
    if(tmp.size()>maxN) maxN = tmp.size();  // set에 넣어서 겹치는 것 제거
  }
  set<string>::iterator iter;
  for(iter = temp.begin(); iter !=temp.end(); ++iter){  //set에서 iterator를 사용하여 vector에 push
      arr[(*iter).size()].push_back(*iter);
  }
  for(i=1;i<=maxN;i++){ //사이즈별로 정렬해준다.
    sort(arr[i].begin(),arr[i].end(),compare);
  }
  for(i=1;i<=maxN;i++){
    value = arr[i].size();
    for(j=0;j<value;j++){
      cout<<arr[i][j]<<endl;  // 출력.
    }
  }
  return 0;
}
