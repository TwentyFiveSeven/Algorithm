#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> V;
string solution(string compressed) {
    string answer = "",number ="",mstr="";
    int size = compressed.size();
    for(int i=0;i<size;i++){
        if(compressed[i] >= '0' && compressed[i]<='9'){
            number += compressed[i];
        }else if(compressed[i] == '('){
            if(number != ""){
                V.push_back(number);
                number = "";
            }
            V.push_back("(");
        }else if(compressed[i] == ')'){
            if(mstr != ""){
                V.push_back(mstr);
                mstr = "";
            }
            string s = "",test = "",save = "";
            while(V.back() !="("){
                s = V.back();
                save = s + save;
                V.pop_back();
            }
            s = save;
            if(!V.empty() && V.back() == "(")
                V.pop_back();
            if(!V.empty()){
                string check = V.back();
                int val = 0;
                if(check[0]>='0' && check[0] <='9'){
                    val = atoi(check.c_str());
                    V.pop_back();
                }
                val -=1;
                string mul = s;
                while(val--){
                    if(val == -2)break;
                    s = s + mul;
                }
            }
            if(s != "")
                V.push_back(s);
        }else{
            if(V.size() != 0 && ((V.back())[0]>='a' && (V.back())[0]<='z')){
                string check2 = V.back();
                check2 += compressed[i];
                V.pop_back();
                V.push_back(check2);
            }else if(V.size() == 0){
                string sss = "";
                sss +=compressed[i];
                V.push_back(sss);
            }
            else{
                mstr += compressed[i];
            }
        }
    }
    string save1 = "";
    while(!V.empty()){
        if((V.back())[0] >='a' && (V.back())[0] <='z'){
            save1 = V.back();
            answer = save1 + answer;
        }
        V.pop_back();
    }
    return answer;
}
