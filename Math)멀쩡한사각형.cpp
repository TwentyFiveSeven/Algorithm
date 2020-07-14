using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    int gcdV=0;
    if(h > w){
        int temp = w;
        w = h;
        h = temp;
    }
    for(int i=1;i<=h;i++){
        if(w%i == 0 && h%i == 0)
            gcdV = i;
    }
    answer = (1LL*h*w) - ((w/gcdV)+(h/gcdV) - 1)*gcdV*1LL;
    return answer;
}
