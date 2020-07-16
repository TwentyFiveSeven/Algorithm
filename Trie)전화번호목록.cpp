#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int num = 10;
bool check = false;

class node{
    node *children[num];
    int end = 0;

    public:
    node(){
        for(int i=0; i<num;i++)
            children[i] = NULL;
    }

    void Insert(string s, int i){
        if( i == s.size()){
            end = 1;
            return;
        }

        int next = s[i]-48;
        if(children[next] == NULL){
            children[next] = new node();
            children[next]->Insert(s,i+1);
        }else{
            if(children[next]->end){
                check = true;
                return;
            }else if(i+1 == s.size()){
                check = true;
                children[next]->end = 1;
                return;
            }
            children[next]->Insert(s,i+1);
        }
    }
};
bool solution(vector<string> phone_book) {
    bool answer = true;
    int size = phone_book.size();
    node head;
    for(int i=0;i<size;i++){
        head.Insert(phone_book[i],0);
        if(check)
            return false;
    }
    return true;
}
