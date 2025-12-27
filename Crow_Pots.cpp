/*https://codereview.stackexchange.com/questions/136165/the-thirsty-crow*/

#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std ;

int n, k ;
vector<int> over ;
vector<vector<int>> dp ;

int solve(){
    for(int i = n - 1; i >= 0; i--){
        dp[i][0] = (n - i) * over[i] ;
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = 1; j < k; j++){
            for(int p = i + 1; p < n; p++){
                if(dp[p][j - 1] == INT_MAX) continue;
                dp[i][j] = min(dp[i][j], dp[p][j - 1] + over[i] * (p - i)) ;
            }
        }
    }
    int ans = INT_MAX ;
    for(int i = 0; i < n; i++){
        ans = min(ans, dp[i][k - 1]) ;
    }
    return ans ;
}

int main(){
    int t ;
    cin >> t ;
    while(t--){
        cin >> n >> k ;

        over.resize(n) ;
        for(int i = 0; i < n; i++){
            cin >> over[i] ;
        }
        sort(over.begin(), over.end()) ;
        dp.assign(n, vector<int>(k, INT_MAX)) ;
        cout << solve() << endl ;
    }

    return 0 ;
}