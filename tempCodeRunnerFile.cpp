/*https://github.com/Rahat-Khan-Pathan/Samsung-Bangladesh-Pre-Employment-Coding-Test-Preparation/tree/main/Physical%20Energy*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std ;

int n, energy, dist ;
vector<int> cost, time ;
vector<vector<vector<int>>> dp ;

int solve(int energy, int dist, int n){
    if(energy <= 0 || n == 0) return 1e5 ;
    if(dist == 0) return 0 ;

    if(dp[energy][dist][n] != -1) return dp[energy][dist][n] ;

    return dp[energy][dist][n] = min(solve(energy, dist, n - 1), time[n - 1] + solve(energy - cost[n], dist - 1, n)) ;
}

int main(){
    int test ;
    cin >> test ;
    while(test--){
        cin >> n >> energy >> dist ;

        cost.resize(n) ;
        time.resize(n) ;

        for(int i = 0; i < n; i++){
            cin >> cost[i] >> time[i] ;
        }

        dp.assign(energy + 1, vector<vector<int>>(dist + 1, vector<int>(n + 1, -1))) ;

        cout << solve(energy, dist, n) ;

    }
}