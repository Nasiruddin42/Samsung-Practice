/*https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/travelling-salesman-4/problem*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, visit ;
vector<vector<int>> v ;
vector<vector<int>> dp;

int solve(int curr, int mask){
    if(visit == mask){
        return v[curr][0] ;
    }
    if(dp[mask][curr] != -1){
        return dp[mask][curr] ;
    }
    int MN = INT_MAX ;
    for(int i = 1; i < n; i++){
        if((mask & (1 << i)) == 0){
            int ans = v[curr][i] + solve(i , mask | (1 << i)) ;
            MN = min(MN, ans) ;
        }
    }
    return dp[mask][curr] = MN ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t ;
    cin >> t ;
    while(t--){
        cin >> n ;
        v.resize(n, vector<int>(n)) ;
        for(int i= 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> v[i][j] ;
            }
        }
        visit = (1 << n) - 1 ;
        dp.assign((1 << n), vector<int>(n, -1)) ;
        int curr = 0, mask = 1 ;
        cout << solve(curr, mask) << endl ;
    }
    return 0;
}
