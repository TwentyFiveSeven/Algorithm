#include <string>
#include <vector>

using namespace std;
vector<int> V[100001];
string solution(int n, vector<vector<int>> delivery) {
    int fir,sec,thr;
    vector<int> arr(n+1,-1);
    string answer = "";
    int size = delivery.size();
    for(int i=0;i<size;i++){
        fir = delivery[i][0];
        sec = delivery[i][1];
        thr = delivery[i][2];
        if(thr == 0 && sec == -1 && thr == -1){
            V[fir].push_back(sec);
            V[sec].push_back(fir);
        }
        if(thr){
            arr[fir] = 1;
            arr[sec] = 1;
            int sizeV = V[fir].size();
            for(int j=0;j<sizeV;j++){
                arr[V[fir][j]] = 0;
            }
            int sizeS = V[sec].size();
            for(int j=0;j<sizeS;j++){
                arr[V[sec][j]] = 0;
            }
        }else if(arr[fir] == 1){
            if(arr[sec] != 1)
                arr[sec] = 0;
        }else if(arr[sec] == 1){
            if(arr[fir] != 1)
                arr[fir] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        if(arr[i] ==1){
            answer +="O";
        }else if(arr[i] == -1){
            answer +="?";
        }else{
            answer+="X";
        }
    }
    return answer;
}
