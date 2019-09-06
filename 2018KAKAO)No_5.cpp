#include<algorithm>
#include <string>
#include<tuple>
#include <vector>

using namespace std;
vector<tuple<int,int,int>> X;
vector<int> K,M;

void preorder(vector<pair<int,int>> V, int root){ //전위 순환
    int left = V[root].first;
    int right = V[root].second;

    K.push_back(root);
    if(left != 0) preorder(V,left);
    if(right != 0) preorder(V,right);
}
void postorder(vector<pair<int,int>> V,int root){ //전후 순환
    int left = V[root].first;
    int right = V[root].second;

    if(left != 0) postorder(V,left);
    if(right != 0) postorder(V,right);
    M.push_back(root);
}
bool cmp(tuple<int,int,int> a,tuple<int,int,int> b){  //정렬 비교
    if(get<1>(a) != get<1>(b))
        return get<1>(a) > get<1>(b);
    else
        return get<0>(a) < get<0>(b);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int root,i,j,size = nodeinfo.size();
    vector<pair<int,int>> V(size+1);
    vector<int> Num(size+1);
    for(i=0;i<size;i++){  //X에다가 입력
        X.push_back(make_tuple(nodeinfo[i][0],nodeinfo[i][1],i+1));
    }
    sort(X.begin(),X.end(),cmp);//y값의 순서대로 정렬한다.
    root = get<2>(X[0]);
    for(i=0;i<size;i++){  //각 번호마다 y값 순 정렬에서 몇번 째 인지 기억.
        Num[get<2>(X[i])] = i;
    }
    for(i=1;i<size;i++){
        int tmp = 0;
        int x = get<0>(X[i]); //현재 노드의 x값
        while(1){
            auto &parent = V[get<2>(X[tmp])]; //현재 노드의 parent를 가져온다.
            if(x > get<0>(X[tmp])){ //만약 현재노드의 x값이 크다면 right 방향으로 이동
                if(parent.second ==0){    //부모노드의 right가 없다면 right = 현재노드
                    parent.second = get<2>(X[i]);
                    break;
                }else{  //부모노드의 right가 있다면 부모 = 부모노드의 right
                    tmp = Num[parent.second]; //X[tmp]를 이용하기 떄문에 X의 y값 순서를 입력
                    continue;
                }
            }else{
                if(parent.first ==0){
                    parent.first = get<2>(X[i]);
                    break;
                }else{
                    tmp = Num[parent.first];
                    continue;
                }
            }
        }
    }
    preorder(V,root);
    postorder(V,root);
    answer.push_back(K);
    answer.push_back(M);
    return answer;
}
