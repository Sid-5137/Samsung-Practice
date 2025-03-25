/*
https://www.careercup.com/question?id=14989765
http://ideone.com/oXdBaF

Given a 2 D matrix where 1 represent the places where the frog can jump and 0 represent the empty spaces,
the frog can move freely in horizontal direction (on 1’s only) without incurring any cost (jump). 
A vertical jump from a given point of the matrix to other point on the matrix can be taken (on 1’s only) 
with cost as the number of jumps taken.
Given a source and destination, the frog has to reach the destination minimizing the cost (jump).
*/
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 105;

int bfs(int mat[MAX][MAX], int n, int sx, int sy, int tx, int ty) {
    int dis[MAX][MAX] = {0};
    bool visited[MAX][MAX] = {false};
    
    queue <pair<int,int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    dis[sx][sy] = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0;i < n; i++) {
            if(mat[x][i] == 1 && visited[x][i] == false) {
                visited[x][i] = true;
                dis[x][i] = dis[x][y];
                q.push({x, i});
            }
        }

        for (int i = 0; i < n; i++) {
            if (mat[i][y] == 1 && !visited[i][y]) {
                visited[i][y] = true; 
                dis[i][y] = dis[x][y] + 1;  
                q.push({i, y});                   
            }
        }
    }
    return  dis[tx][ty];
}

int main() {
    int n;
    cin >> n;

    int mat[105][105];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    int result = bfs(mat, n, sx, sy, tx, ty);

    cout << result << endl;

    return 0;
}