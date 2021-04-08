#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
string word;
int wordsize;
bool cmp(pair<int,double> a,pair<int,double> b){
    if(a.second != b.second)
        return a.second < b.second;
    else
        return a.first > b.first;
}
vector<vector<string>> split(vector<string> pages){
    int size = pages.size(),contentSize = 9,hrefSize = 9;
    string check ="<meta property=\"og:url\" ",check2 ="/>",content1 = "https://", content2 = "\"",href = "<a href=\"",body = "<body>\n",bodyEnd = "\n</body>";
    vector<vector<string>> S;
    for(int i=0;i<size;i++){
        vector<string> temp;
        int click = 0;
        int first,second;
        int checkS1 = pages[i].find(check);
        if(checkS1 != -1){
            int checkS2 = pages[i].find(check2,checkS1);
            first = pages[i].find(content1); //h~~
            if(first<checkS2){
                second = pages[i].find(content2,first)-1;// ~~m
                temp.push_back(pages[i].substr(first,second-first+1));
            }else{continue;}
        }else{continue;}
        while(pages[i].find(href,click) !=-1){
            first = pages[i].find(href,click)+hrefSize;
            second = pages[i].find(content2,first)-1;
            temp.push_back(pages[i].substr(first,second-first+1));
            click = second+1;
        }
        first = pages[i].find(body)+7;
        second = pages[i].find(bodyEnd);
        string tmp = pages[i].substr(first,second-first+1);
        temp.push_back(tmp);
        S.push_back(temp);
    }
    return S;
}

vector<vector<int>> split2(vector<vector<string>> S){
    vector<vector<int>> ans;
    for(int i=0;i<S.size();i++){
        vector<int> temp;
        int end = S[i].size()-1;
        for(int j=0;j<S[i][end].size();j++){
            if(S[i][end][j] >='A'&&S[i][end][j]<='Z')
                S[i][end][j]+=32;
        }
        int start = 0,sizeW = word.size(),count=0;
        while(S[i][end].find(word,start)!=-1){
            start = S[i][end].find(word,start)+wordsize;
            if((S[i][end][start]<'A'||S[i][end][start]>'z')&&(S[i][end][start-wordsize-1]<'A'||S[i][end][start-wordsize-1]>'z')){
                count++;
            }
        }
        temp.push_back(count);
        temp.push_back(end+1-2);
        for(int j=1;j<end;j++){
            for(int k=0;k<S.size();k++){
                if(i==k) continue;
                if(S[i][j].compare(S[k][0])==0) {
                    temp.push_back(k);
                    break;
                    }
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int solution(string word2, vector<string> pages) {
    int answer = 0;
    vector<pair<int,double>> All;
    for(int j=0;j<word2.size();j++){
            if(word2[j] >='A'&&word2[j]<='Z')
                word2[j]+=32;
    }
    word = word2;
    wordsize = word.size();
    vector<vector<string>> S = split(pages);
    vector<vector<int>> ans = split2(S);
    for(int i=0;i<ans.size();i++){
        double sum =0.0;
        for(int j=0;j<ans.size();j++){
            for(int m=2;m<ans[j].size();m++){
                if(j==i) continue;
                if(ans[j][1]>0&&ans[j][m] == i) sum =sum + (double)ans[j][0]/(double)ans[j][1];
            }
        }
        sum = sum + (double)ans[i][0];
        All.push_back(make_pair(i,sum));
    }
    sort(All.begin(),All.end(),cmp);
    answer = All.back().first;
    return answer;
}
