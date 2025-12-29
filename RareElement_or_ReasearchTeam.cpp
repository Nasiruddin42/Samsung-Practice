#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>
#include <queue>

using namespace std ;

int bfs(int n, vector<vector<int>> &grid, vector<pair<int, int>> &elements, int i, int j, map<pair<int, int>, int> &isRare){
    queue<vector<int>> q ;
    q.push({i, j, 0}) ;

    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}} ;
    vector<vector<int>> visit(n, vector<int>(n, 0)) ;

    visit[i][j] = true ;

    int mx = 0 ;
    while(!q.empty()){
        auto temp = q.front() ;
        q.pop() ;

        int a = temp[0], b = temp[1], dist = temp[2] ;

        for(auto it : direction){
            int newa = a + it[0] ;
            int newb = b + it[1] ;

            if(newa >= 0 && newa < n && newb >= 0 && newb < n && grid[newa][newb] == 1 && !visit[newa][newb]){
                q.push({newa, newb, dist + 1}) ;
                //cout << newa << " " << newb << endl ;
                visit[newa][newb] = true ;
                
                if(isRare[{newa, newb}] == 1){
                    mx = max(mx, dist + 1) ;
                }
            }

        }
    }
    return mx ;
}

int main(){
    int testcase ;
    cin >> testcase ;

    while(testcase--){
        int n, c ;
        cin >> n >> c ;

        vector<pair<int, int>> elements(c) ;
        map<pair<int, int>, int> isRare ;

        int x, y ;
        for(int i = 0; i < c; i++){
            cin >> x >> y ;
            elements[i] = {x - 1, y - 1} ;
            isRare[elements[i]] = 1 ;
        }

        int ans = INT_MAX ;
        vector<vector<int>> grid(n, vector<int>(n)) ;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j] ;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int maxi = bfs(n, grid, elements, i, j, isRare) ;
                    ans = min(ans, maxi) ;
                }
            }
        }

        cout << ans << endl ;
    }
    return 0 ;
}