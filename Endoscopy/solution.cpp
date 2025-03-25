#include <iostream>
#include <queue>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int pipedir[8][4] = {
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {1, 1, 0, 0},
    {0, 0, 1, 1},
    {1, 0, 0, 1},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {1, 0, 1, 0}
};

int bfs(int **grid, bool** visited, int N, int M, int R, int C, int L) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{R,C}, 1});
    visited[R][C] = true;
    int count = 1;

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int len = q.front().second;
        q.pop();

        if(len >= L) continue;
        
        int pipetype = grid[x][y];

        for(int d = 0; d < 4; d++) {
            if(!pipedir[pipetype][d]) continue;

            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx < 0 || ny < 0 || nx > N || ny > M) continue;
            if(visited[nx][ny]) continue;
            if(grid[nx][ny] == 0) continue;

            int nextpipe = grid[nx][ny];
            int opposite = (d == 0) ? 1 : (d == 1) ? 0 : (d == 2) ? 3 : 2;

            if(!pipedir[nextpipe][opposite]) continue;

            visited[nx][ny] = true;
            count++;
            q.push({{nx,ny},len + 1});
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    int N, M, R, C, L;
    while (t--){
        cin >> N >> M >> R >> C >> L;
        int **grid = new int*[N];
        for(int i = 0;i < N;i++){
            grid[i] = new int[M];
        }
        for(int i = 0;i < N;i++){
            for(int j=0;j < M;j++){
                cin >> grid[i][j];
            }
        }
        bool **visited = new bool*[N];
        for (int i = 0; i < N; i++) {
            visited[i] = new bool[M]();
        }

        cout << bfs(grid, visited, N, M, R, C, L);
        
    }
}