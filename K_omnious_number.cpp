#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std ;

int main(){
    int s, e, n, k ;
    cin >> s >> e >> n >> k ;

    map<int, bool> bad ;
    int x ;
    for(int i = 0; i < n; i++){
        cin >> x ;
        bad[x] = true ;
    }

    int ans = 0 ;
    for(int i = s; i <= e; i++){
        int x = i ;

        int cnt = 0 ;
        while(x){
            if(bad[x % 10]) cnt++ ;
            x /= 10 ;
        }
        
        if(cnt >= k) ans++ ;
    }
  

    cout << "K Omnious number is : " << ans << endl ;
}
