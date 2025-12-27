/*https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/aeroplane-bombing/problem*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n ;
vector<vector<int>> grid ;
int dp[15][5][2][6] ;

int solve(int r, int c, int bomb, int safe){
    if(r < 0 || r >= n || c < 0 || c >= 5) return 0 ;
    if(dp[r][c][bomb][safe] != -1) return dp[r][c][bomb][safe] ;
    
    int coin = 0 ;
    
    if(grid[r][c] == 0 || grid[r][c] == 1){
        if(grid[r][c] == 1) coin++ ;
        safe = max(0, safe - 1) ;
    }
    else if(grid[r][c] == 2){
        if(bomb && safe > 0){
            safe = max(0, safe - 1) ;
        }
        else if(bomb && safe <= 0){
            return dp[r][c][bomb][safe] = coin ;
        }
        else if(!bomb){
            bomb = 1 ;
            safe = 4 ;
        }
    } 
    int mx = -1 ;
    for(int j = -1; j <= 1; j++){
        mx = max(mx, solve(r - 1, c + j, bomb, safe)) ;
    }
    coin += mx ;
    
    return dp[r][c][bomb][safe] = coin ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t ;
    cin >> t ;
    for(int test = 1; test <= t; test++){
        cin >> n ;
        
        grid.clear() ;
        grid.assign(n, vector<int>(5)) ;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 5; j++){
                cin >> grid[i][j] ;
            }
        }
        
        memset(dp, -1, sizeof(dp)) ;
        int MX = -1, bomb = 0, safe = 0 ;
        for(int i = -1; i <= 1; i++){
            MX = max(MX, solve(n - 1, 2 + i, bomb, safe)) ;
        }
        
        cout << "#" << test << " " << MX << endl ;
        
    }
    return 0;
}
