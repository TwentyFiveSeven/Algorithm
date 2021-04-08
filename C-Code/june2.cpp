#include<iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  int teamNum=0,prNum=0,count=0;
  bool endflag =0;
  cin>>teamNum>>prNum;

  int quizN=0;
  int *memNum = new int[teamNum];
  string quiz;
  string *teamName= new string[teamNum];
  string **memName;

  memName= new string*[teamNum];

  while(true){  //teamNum 만큼
    //cout<< "input team name : ";
    cin>>teamName[count];

    //cout<< "input number of member : ";
    cin>>memNum[count];
    memNum[count] = memNum[count]+1;

    memName[count] = new string[memNum[count]];
    memName[count][0] = teamName[count];
    for(int i =1; i<memNum[count];i++){
      //cout<<"input memName : ";
      cin>>memName[count][i];
    }
    count++;
    if(count == teamNum){
      break;
    }
  }
  for(int i=0;i<teamNum;i++){
    sort(memName[i]+1,memName[i]+memNum[i]);
  }

  count =0;
  while(true){
    //cout<<"input quiz : ";
    cin>>quiz;
    cin>>quizN;

    endflag = 0;
    if(quizN == 1){
      for(int i=0; i<teamNum;i++){
          for(int j=1;j<memNum[i];j++){
            if(quiz.compare(memName[i][j])==0){
              cout<<memName[i][0]<<endl;
              endflag = 1;
              break;
            }
          }
          if(endflag){
            break;
          }
      }
    }else{
      for(int i=0; i<teamNum;i++){
        if(quiz.compare(teamName[i])==0){
          for(int j=1; j<memNum[i];j++){
            cout<<memName[i][j]<<endl;
          }
          break;
        }
      }
    }
    count++;
    if(count == prNum){
      break;
    }
  }

  return 0;

}
