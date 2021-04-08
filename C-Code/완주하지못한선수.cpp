#include <string>
#include <vector>

using namespace std;

typedef struct node{
    struct node* alpha[26];
    int end;
    int count =0;
}node;

node* newNode(){
    node* newN = (node *)malloc(sizeof(node));
    newN->end = 0;
    for(int i=0;i<26;i++) newN->alpha[i] = 0;
    return newN;
}

void insert(node* root, string str){
    int size = str.size(),flag=0;
    node* now = root;

    for(int i=0;i<size;i++){
        if(!now->alpha[str[i]-'a'])
            now->alpha[str[i]-'a'] = newNode();
        now = now->alpha[str[i]-'a'];
    }
    now->count++;
    if(now->end == 0)
        now ->end = 1;
}

int find(node* root, string s){
    node* Nroot = root;
    int i,j,size = s.size();
    for(i=0;i<size;i++){
        if(!Nroot->alpha[s[i]-'a']){
            return 0;
        }
        Nroot = Nroot->alpha[s[i]-'a'];
    }

    if((Nroot->end++)>Nroot->count)
        return 0;
    return 1;
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    node* Froot = newNode();
    for(int i=0;i<completion.size();i++){
        insert(Froot,completion[i]);
    }
    for(int i=0;i<participant.size();i++){
        if(!find(Froot,participant[i])){
            answer = participant[i];
            break;
        }
    }
    return answer;
}
