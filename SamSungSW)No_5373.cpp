#include<iostream>
using namespace std;
// 1: 왼,초   2 : 앞,빨   3 : 오,파   4: 뒷,오    5 : 윗,흰 6:밑,노
char cube[6][3][3] = {{{'g','g','g'},{'g','g','g'},{'g','g','g'}},
                      {{'r','r','r'},{'r','r','r'},{'r','r','r'}},
                      {{'b','b','b'},{'b','b','b'},{'b','b','b'}},
                      {{'o','o','o'},{'o','o','o'},{'o','o','o'}},
                      {{'w','w','w'},{'w','w','w'},{'w','w','w'}},
                      {{'y','y','y'},{'y','y','y'},{'y','y','y'}}};
void turnU(int dir){
  if(dir){
    swap_ranges(cube[0][0],cube[0][0]+3,cube[1][0]);
    swap_ranges(cube[2][0],cube[0][0]+3,cube[3][0]);
    swap_ranges(cube[0][0],cube[0][0]+3,cube[2][0]);
  }else{
    swap_ranges(cube[0][0],cube[0][0]+3,cube[3][0]);
    swap_ranges(cube[2][0],cube[0][0]+3,cube[1][0]);
    swap_ranges(cube[0][0],cube[0][0]+3,cube[2][0]);
  }
}
void Turn(char side,int dir){
  if(side == 'U'){
    turnU(dir);
  }else if(side == 'D'){
    turnD(dir);
  }else if(side == 'F'){
    turnF(dir);
  }else if(side == 'B'){
    turnB(dir);
  }else if(side == 'L'){
    turnL(dir);
  }else if(side == 'R'){
    turnR(dir);
  }
}

int main(){
  cout<<cube[1][0][0];
  return 0;
}
