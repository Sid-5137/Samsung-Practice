/*
There are n balloons and n bullets and each balloon is assigned with a particular number (point).
Whenever a particular balloon is shot the no of points increases by
1.the multiplication of point assigned to balloon on left and that of right side.
2.point assigned to left if no right exists
3.point assigned to right if no left exists.
4.the point assigned to itself if no other balloon exists.
 
You have to output the maximum no of points possible.
 
Input
1 2 3 4
 
Output
20
*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int n;
vector<int> nums;
int maxCoins() {
    int **dp = new int*[n];

    
    for(int i = 2;i < n;i++) {
        for(int left = 0; left < n - i;left++) {
            int right = left + i;
            for(int j = left + 1;j < right;j++) {
                if(left == 0 && right == n - 1) {
                    if(left==0 && right==n-1)
                        dp[left][right] = max(nums[left]*nums[i]*nums[right] + dp[left][i] + dp[i][right],dp[left][right]);
                    else
                        dp[left][right] = max(nums[left]*nums[right] + dp[left][i] + dp[i][right],dp[left][right]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return dp[0][n-1];
}

int main() {
    cin >> n;
    nums[0] = nums[n+1] = 1;
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }

    cout<<maxCoins();

    return 0;
}