/*https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/warmholes*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

vector<vector<int>> warm ;
vector<int> dist ;
vector<int> visit ;
int n ;


int distance(int x1, int y1, int x2, int y2){
    return (abs(x1 - x2) + abs(y1 - y2)) ;
}

int CalculateMinDistance(){
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;
    pq.push({0, 0}) ;
    
    dist.assign(2 * n + 2, INT_MAX) ;
    visit.assign(2 * n + 2, 0) ;
    dist[0] = 0 ;
    
    while(!pq.empty()){
        auto it = pq.top() ;
        pq.pop() ;
        
        int d = it.first ;
        int curr = it.second ;
        
        if(visit[curr]) continue ;
        visit[curr] = 1 ;
        
        for(int i = 0; i < 2 * n + 2; i++){
            if(!visit[i]){
                int d1 = distance(warm[curr][2], warm[curr][3], warm[i][0], warm[i][1]) + warm[i][4] ;
                int d2 = distance(warm[curr][2], warm[curr][3], warm[i][2], warm[i][3]) ;
                int mn = min(d1, d2) ;
                
                if(mn + d < dist[i]){
                    dist[i] = mn + d ;
                    pq.push({dist[i], i}) ;
                }
            }
        }  
    }
    return dist[2 * n + 1] ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t ;
    cin >> t ;
    while(t--){
        cin >> n ;
        
        int sx, sy, ex, ey ;    
        cin >> sx >> sy >> ex >> ey ;
        
        warm.clear() ;
        warm.resize(2 * n + 2, vector<int>(5)) ;
        
        warm[0] = {{sx, sy, sx, sy, 0}} ;
        warm[2 * n + 1] = {{ex, ey, ex, ey, 0}} ;
        
        int a, b, c, d, e ;
        for(int i = 1; i < 2 * n; i+=2){
            cin >> a >> b >> c >> d >> e ;
            
            warm[i]     = {a, b, c, d, e} ;
            warm[i + 1] = {c, d, a, b, e} ;
        }
        cout << CalculateMinDistance() << endl ;
    }
    return 0;
}
