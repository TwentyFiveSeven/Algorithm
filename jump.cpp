#include <iostream>
#include <stack>
using namespace std;


int** arr;
int size;

class Point
{
  private:
        int x;
        int y;
  public:
      void change_point(int _x,int _y)
      {
          x = _x;
          y = _y;
      }
      int getx(){return x;}
      int gety(){return y;}
};

void promising(stack<Point> &st,Point p){
  st.pop();
  Point tmp;

  tmp.change_point(p.getx()+arr[p.getx()][p.gety()],p.gety());
  if(tmp.getx()<size){
    st.push(tmp);
  }

  tmp.change_point(p.getx(),p.gety()+arr[p.getx()][p.gety()]);
  if(tmp.gety()<size){
    st.push(tmp);
  }
}

void jump(stack<Point> &st){

  while(true){
    if(st.empty()){
      cout<<"Hing"<<endl;
      break;
    }else if(st.top().getx() == (size-1)&&st.top().gety() == (size-1)){
      cout<<"HaruHaru"<<endl;
      break;
    }else{
      promising(st,st.top());
    }
  }
}


int main(){
  Point start;
  start.change_point(0,0);
  stack<Point> st;

  cin>>size;
  arr = new int*[size];
  for(int i=0;i<size;i++){
    arr[i] = new int[size];
  }

  st.push(start);
  for(int i=0; i<size;i++){
    for(int j=0; j<size;j++){
      cin>>arr[i][j];
    }
  }

  jump(st);
}
