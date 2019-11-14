#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0,size = dartResult.size(),count =0,value=0,Cd=0,Ct=0,input =0;
    vector<int> V;
    while(count<size){
        char c = dartResult[count];
        if(c>47&&c<58){
            value = c-48;
            if(dartResult[count+1] == '0'){
                value +=9;
                count++;
            }
        }
        else if(c>64&&c<91){
            if(c == 'D') value *=value;
            else if(c == 'T') value *=value*value;
            if((count<size-1&&dartResult[count+1]!='*'&&dartResult[count+1]!='#')||count==size-1){
                V.push_back(value);
                input++;
            }
        }else{
            if(c == '*'){
                if(input>0)
                    V[input-1] *= 2;
                value *=2;
            }else{
                value *= -1;
            }
            V.push_back(value);
            input++;
        }
        count++;
    }
    for(int i=0;i<V.size();i++){
        answer+= V[i];
    }
    return answer;
}
