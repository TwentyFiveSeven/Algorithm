#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

vector<vector<string>> V;
vector<string> Vstring;

bool cmp(vector<string> a, vector<string> b){
    if(atoi(a[1].c_str()) == atoi(b[1].c_str())){
        return atoi(a[0].c_str()) < atoi(b[0].c_str());
    }else
        return atoi(a[1].c_str()) > atoi(b[1].c_str());
}

void makeString(string &m){
    for(int i=0;i<m.size();i++){
        if(m[i] == '#'){
            char c = m[i-1]+32;
            string temp = ""; temp += c;
            m.replace(i-1,2,temp);
        }
    }
}

string solution(string m, vector<string> musicinfos) {
    string answer = "",s,melody = "";
    makeString(m);
    for(int i=0; i<musicinfos.size();i++){
        makeString(musicinfos[i]);
        istringstream ss(musicinfos[i]);
        melody ="";
        while(getline(ss,s,',')){
            Vstring.push_back(s);
        }
        int Scount = 0;
        for(int j=0;j<Vstring[3].size();j++)
            if(Vstring[3][j] =='#')
                Scount++;
        int hour = atoi(Vstring[1].substr(0,2).c_str()) - atoi(Vstring[0].substr(0,2).c_str());
        if(hour < 0) hour += 24;
        int minute = atoi(Vstring[1].substr(3,2).c_str()) + hour*60 - atoi(Vstring[0].substr(3,2).c_str());
        int mul = minute/Vstring[3].size(); //#을 하나로 봐야한다.
        int remainder = minute%Vstring[3].size();
        while(mul--)
            melody += Vstring[3];
        melody += Vstring[3].substr(0,remainder);
        Vstring[0] = to_string(i);
        Vstring[1] = to_string(minute);
        cout<<Vstring[0]<<' '<<Vstring[1]<<' '<<Vstring[2]<<' '<<Vstring[3]<<'\n';
        if(melody.find(m) != -1)
            V.push_back(Vstring);
        Vstring.clear();
    }
    if(!V.empty()){
        sort(V.begin(),V.end(),cmp);
        answer = V[0][2];
    }else
        answer = "(None)";
    return answer;
}
