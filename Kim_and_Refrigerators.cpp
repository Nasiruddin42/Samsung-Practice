/*https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/kim-and-refrigerators*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

vector<vector<int>> loc ;
vector<vector<int>> dp ;
int ox, oy, hx, hy ;
int n ;

int distance(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2) ;
}

int solve(int curr, int mask){
    if(mask == (1 << n) - 1){
        if(curr == -1){
            return distance(ox, oy, hx, hy) ;
        }
        return distance(loc[curr][0], loc[curr][1], hx, hy) ;
    }
    if(dp[curr + 1][mask] != -1) return dp[curr + 1][mask] ;
    
    int ans = INT_MAX ;
    for(int i = 0; i < n; i++){
        if((mask & (1 << i)) == 0){
            
            int cost ;
            if(curr == -1){
                cost = distance(ox, oy, loc[i][0], loc[i][1]) ;
            }
            else{
                cost = distance(loc[curr][0], loc[curr][1], loc[i][0], loc[i][1]) ;
            }
            ans = min(ans, cost + solve(i, mask | (1 << i))) ;
        }
    }
    return dp[curr + 1][mask] = ans ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int t = 10 ;
    for(int tc = 1; tc <= t; tc++){
        cin >> n ;
        
        cin >> ox >> oy >> hx >> hy ;
        
        loc.assign(n, vector<int>(2)) ;
        for(int i = 0; i < n; i++){
            int x, y ;
            cin >> x >> y ;
            loc[i] = {x, y} ;
        }
        
        dp.assign(n + 1, vector<int>(1 << n, -1)) ;
        int mask = 0 ;
        cout <<"#" << " " << tc << " " << solve(-1, mask) << endl ;
        
    }
    return 0;
}
