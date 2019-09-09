#include <string>
#include <vector>

using namespace std;

int CNT, M, N;
vector<vector<int> > X, Y;

void Rotate()
{
    vector<vector<int> > ret(M, vector<int>(M, 0));
    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
        {
            ret[j][M-i-1] = X[i][j];
        }
    X = ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    X = key; Y = lock;
    M = X.size(); N = Y.size();

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if (Y[i][j] == 0)
                CNT++;

    for(int t=0; t<4; t++)
    {
        for(int i=-25; i<=25; i++)
        {
            for(int j=-25; j<=25; j++)
            {
                int cnt = 0, fail = 0;
                for(int y = 0; y < M; y++)
                    for(int x = 0; x < M; x++)
                    {
                        int ny = i + y, nx = j + x;
                        if (0 <= ny && ny < N && 0 <= nx && nx < N)
                        {
                            if (Y[ny][nx] == 1 && X[y][x] == 1) fail = 1;
                            else if (Y[ny][nx] == 0 && X[y][x] == 1) cnt++;
                        }
                    }
                if (cnt == CNT && fail == 0) return true;
            }
        }
        Rotate();
    }
    return false;
}
