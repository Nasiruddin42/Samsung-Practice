/*https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/endoscope*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int n, m, x, y, k ;
vector<vector<int>> grid ;
map<int, vector<vector<int>>> mp ;


bool valid(int cx, int cy, int nx, int ny, int l){
    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] && l <= k){
        for(auto a : mp[grid[nx][ny]]){
            if(nx + a[0] == cx && ny + a[1] == cy){
                return true ;
            }
        }
    }
    return false ;
}

int pipeCount(){
    queue<vector<int>> q ;
    q.push({x, y, 1});
    int ans = 0 ;
    
    while(!q.empty()){
        auto t = q.front() ;
        q.pop() ;
        int cx = t[0], cy = t[1], l = t[2] ;
        
        if(!grid[cx][cy] || l > k) continue ;
        
        ans++ ;
        //cout << grid[cx][cy] << " : " ;
        for(auto a : mp[grid[cx][cy]]){
            int nx = cx + a[0], ny = cy + a[1] ;
            if(valid(cx, cy, nx, ny, l+1)){
                //cout << grid[nx][ny] << " " ;
                q.push({nx, ny, l+1}) ;
            }
        }
        grid[cx][cy] = 0 ;
    }
    return ans ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    mp[1] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}} ;
    mp[2] = {{-1, 0}, {1, 0}} ;
    mp[3] = {{0, -1}, {0, 1}} ;
    mp[4] = {{-1, 0}, {0, 1}} ;
    mp[5] = {{1, 0},  {0, 1}} ;
    mp[6] = {{0, -1},  {1, 0}} ;
    mp[7] = {{0, -1}, {-1, 0}} ;
    
    int t ;
    cin >> t ;
    while(t--){
        cin >> n >> m >> x >> y >> k ;
        
        grid.clear() ;
        grid.resize(n, vector<int>(m)) ;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j] ;
            }
        }
        cout << pipeCount() << endl ;
    }
    return 0;
}
