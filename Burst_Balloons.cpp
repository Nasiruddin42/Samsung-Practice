/*https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/burst-balloons*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> v ;
vector<vector<int>> dp ;
int n ;

int solve(int i, int j){
    if(i == j) return 0 ;
    
    if(dp[i][j] != -1) return dp[i][j] ;
    
    int temp, ans = INT_MIN ;
    for(int k = i; k < j; k++){
        if(i == 1 && j == n + 1){
            temp = v[k] + solve(i, k) + solve(k + 1, j) ;
        }
        else{
            temp = v[i - 1] * v[j] + solve(i, k) + solve(k + 1, j) ;
        }
        ans = max(ans, temp) ;
    }
    return dp[i][j] = ans ;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    cin >> n ;
    
    v.resize(n + 2) ;
    v[0] = 1 ;
    v[n + 1] = 1 ;
    for(int i = 1; i <= n; i++){
        cin >> v[i] ;
    }
    
    dp.assign(n + 2, vector<int>(n + 2, -1));
    cout << solve(1, n + 1) << endl ;
    
    return 0;
}
