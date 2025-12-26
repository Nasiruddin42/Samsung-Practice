/*https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/rock-climbing/problem*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m ;
vector<vector<int>> grid ;
vector<vector<int>> visited ;
bool flag = false ;

void dfs(int l, int r, int c){
    if(flag) return ;
    if(grid[r][c] == 3){
        flag = true;
        return ;
    }
    
    visited[r][c] = true ;
    
    // move left
    if(c - 1 >= 0 && grid[r][c - 1] && !visited[r][c - 1]){
        dfs(l, r, c - 1) ;
    }
    
    // move right
    if(c + 1 < m && grid[r][c + 1] && !visited[r][c + 1]){
        dfs(l, r, c + 1) ;
    }
    
    // move up within limit l
    for(int i = 1; i <= l; i++){
        if(r - i >= 0 && grid[r - i][c] && !visited[r - i][c]){
            dfs(l, r - i, c) ;
        }
    }
    
    // move down within limit l
    for(int i = 1; i <= l; i++){
        if(r + i < n && grid[r + i][c] && !visited[r + i][c]){
            dfs(l, r + i, c) ;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    cin >> n >> m ;
    
    grid.resize(n, vector<int>(m)) ;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j] ;
        }
    }
    
    for(int i = 0; i < n; i++){
        visited.assign(n, vector<int>(m, 0)) ;
        flag = false ;
        dfs(i, n - 1, 0) ;
        
        if(flag){
            cout << i << endl ;
            break ;
        }
    }
    return 0;
}
