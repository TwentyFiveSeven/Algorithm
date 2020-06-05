#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<double> V,S;
    vector<int> C;
    for(int i=0;i<lines.size();i++){
        int Fs = lines[i].find(" ");
        int Ss = lines[i].find(" ",Fs+1);
        string time = lines[i].substr(Fs+1,Fs+1 - (Ss-1)+1);
        string work = lines[i].substr(Ss+1,lines[i].size()-(Ss+2));
        int Fi = time.find(":");
        int Si = time.find(":",Fi+1);
        string hour = time.substr(0,2);
        string minute = time.substr(Fi+1,2);
        int clock = atoi(hour.c_str())*60+atoi(minute.c_str());
        time = time.substr(Si+1,time.size()-(Si+1));
        V.push_back(atof(time.c_str()));
        S.push_back(atof(work.c_str()));
        C.push_back(clock);
    }
    answer=1;
    for(int i=0;i<V.size();i++){
        double plusTime = V[i] + 1 - 0.001;
        plusTime = floorf(plusTime * 10000) / 10000;
        int minute = C[i];
        int ans = 1;
        if(plusTime >=60){
            plusTime -=60;
            minute++;
        }
        plusTime = floorf(plusTime * 10000) / 10000;
        for(int j=i+1;j<V.size();j++){
            double checkTime = V[j] - S[j] + 0.001;
            checkTime = floorf(checkTime * 10000) / 10000;
            int checkminute = C[j];
            if(checkTime <0){
                checkTime +=60;
                checkminute--;
            }
            checkTime = floorf(checkTime * 10000) / 10000;
            if(minute == checkminute){
                if(checkTime <=plusTime){
                    ans++;
                }
            }else if(minute > checkminute)
                ans++;
        }
        answer = max(answer,ans);
    }
    return answer;
}
