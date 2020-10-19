#include<iostream>
using namespace std;

int arr[10001];

int main(){
  int state = 0, day =0 , Min = 120000;
  long long hasMoney = 0,bundle = 0;
  cin>>day>>hasMoney;
  for(int i=1;i<=day;i++){
    cin>>arr[i];
  }
  Min = arr[1];
  for(int i=1;i<=day;i++){
    state = 0;
    if(arr[i] < Min){
      Min = arr[i];
      state = 1;
    }
    if((i == day && arr[day] >= arr[day-1]) ||(i<day && arr[i] > arr[i+1] && !state)){
      bundle = hasMoney/Min;
      hasMoney +=  bundle*(arr[i]-Min)*1L;
      Min = arr[i];
    }
  }
  cout<< hasMoney;
  return 0;
}
