#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<int> arr,answer;

int binary(int start, int end,int value){
  if(start < 0 || end >=N || start > end)
    return 10000001;
  int middle = (start+end)/2;
  if(value == arr[middle])
    return value;
  else if(value < arr[middle]){
    return binary(start, middle-1,value);
  }else{
    return binary(middle+1,end,value);
  }
}

int main(){
  int temp,check=0;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>temp;
    arr.push_back(temp);
  }
  sort(arr.begin(),arr.end());
  cin>>M;
  for(int i=0;i<M;i++){
    cin>>check;
    int result = binary(0,N-1,check);
    if(result == 10000001)
      answer.push_back(0);
    else
      answer.push_back(1);
  }
  for(int i=0;i<answer.size();i++){
    cout<<answer[i]<<' ';
  }
  return 0;
}
