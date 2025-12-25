// Author : Nasir
// RU - CSE
/*https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/fisherman/problem*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n ;
vector<int> people ;

int solve1(int gatepos, int gatepeople){
    gatepos-- ;
    int l = gatepos, r = gatepos ;
    int ans = 0 ;
    
    while(gatepeople--){
        
        while(l >= 0 && people[l] != 0) l-- ;
        while(r < n && people[r] != 0) r++ ;
        
        if(l < 0 || (r < n && r - gatepos <= gatepos - l)){
            ans += (r - gatepos) + 1 ;
            people[r++] = 1 ;
        }
        else{
            ans += (gatepos - l) + 1 ;
            people[l--] = 1 ;
        }
    }
    return ans ;
}

int solve2(int gatepos, int gatepeople){
    gatepos-- ;
    int l = gatepos, r = gatepos ;
    int ans = 0 ;
    
    while(gatepeople--){
        
        while(l >= 0 && people[l] != 0) l-- ;
        while(r < n && people[r] != 0) r++ ;

        if(l < 0 || (r < n && r - gatepos < gatepos - l)){
            ans += (r - gatepos) + 1 ;
            people[r++] = 1 ;
        }
        else{
            ans += (gatepos - l) + 1 ;
            people[l--] = 1 ;
        }
    }
    return ans ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    cin >> n ;
    vector<int> gatepos(3) ;
    vector<int> gatepeople(3) ;
    
    for(int i = 0; i < 3; i++){
        cin >> gatepos[i] ;
    }
    for(int i = 0; i < 3; i++){
        cin >> gatepeople[i] ;
    }
    
    int permute[3] = {0, 1, 2} ;
    int ans = INT_MAX ;
    do{
        int t1 = 0, t2 = 0 ;
        
        people.assign(n, 0) ;
        for(int i = 0; i < 3; i++){
            t1 += solve1(gatepos[permute[i]], gatepeople[permute[i]]) ;
        }
        
        people.assign(n, 0) ;
        for(int i = 0; i < 3; i++){
            t2 += solve2(gatepos[permute[i]], gatepeople[permute[i]]) ;
        }
        ans = min({ans, t1, t2}) ;
        
    } while(next_permutation(permute, permute + 3)) ;
    
    cout << ans << endl ;
    return 0;
}
