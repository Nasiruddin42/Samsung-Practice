/*https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/flip-columns*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m, k ;
    cin >> n >> m >> k ;
    map<vector<int>, int > mp ;
    int x, ans = 0 ;
    for(int i = 0; i < n; i++){
        vector<int> temp ;
        int cnt = 0 ;
        
        for(int j = 0; j < m; j++){
            cin >> x ;
            temp.push_back(x) ;
            if(x == 0){
                cnt++ ;
            }
        }
        if(cnt <= k && (k - cnt) % 2 == 0){
            mp[temp]++ ;
            ans = max(ans, mp[temp]) ;
        }
    }
    cout << ans << endl ;
    return 0;
}
