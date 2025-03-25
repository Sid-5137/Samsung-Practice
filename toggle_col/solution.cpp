/*
https://www.geeksforgeeks.org/samsung-interview-experience-on-campus-for-r-d-noida/

A binary matrix of nxm was given, you have to toggle any column k number of times so that you can get the maximum 
number of rows having all 1’s.

for eg, n=3, m=3,

            1 0 0

            1 0 1

            1 0 0

if k=2, then we will toggle column 2 and 3 once and we will get rows 1 and 3 with 1 1 1 and 1 1 1 i.e. all 1’s so 
answer is 2 as there are 2 rows with all 1’s.

if k=3, then we will toggle column 2 thrice and we will get row 2 with 1 1 1 i.e. all 1’s so answer is 1 as there 
is 1 row with all 1’s.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

void toggle(){
    
}

int main() {
    int k;
    cin >> n >> m;

    int **grid = new int*[n];
    for(int i = 0;i < n;i++){
        grid[i] = new int[m];
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> grid[i][j];
        }
    }

    cin >> k;
    int maxRows = 0;
    for(int i = 0;i < n;i++) {
        int zero_c = 0;

        for(int j = 0;j < n;j++) {
            if(grid[i][j] == 0)
                zero_c++;
        }

        if(zero_c <= k && (k - zero_c)%2==0){
            int matchCount = 0;
            for(int r = 0;r < n;r++){
                bool same = true;
                for(int c = 0;c < m;c++){
                    if(grid[r][c] != grid[i][c]){
                        same = false;
                        break;
                    }
                }
                if(same) matchCount++;
            }
            if(matchCount > maxRows) maxRows = matchCount;
        }
    }
    cout << maxRows <<endl;
    return 0;
}