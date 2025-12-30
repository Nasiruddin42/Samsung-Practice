#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std ;

int main(){

    int testcase = 3 ;

    while(testcase--){
        int n ;
        cin >> n ;
        
        if(n == 0) break; 

        int m ;
        cin >> m ;

        vector<vector<int>> adj(n) ;
        for(int i = 0; i < m; i++){
            int u, v ;
            cin >> u >> v ;

            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }

        vector<int> color(n, -1) ;
        bool isBipartite = true ;

        for(int start = 0; start < n && isBipartite; start++){

            if(color[start] == -1){
                color[start] = 0 ;
                queue<int> q ;
                q.push(start) ;

                while(!q.empty() && isBipartite){
                    int u = q.front() ;
                    q.pop() ;

                    for(auto v : adj[u]){
                        if(color[v] == -1){
                            color[v] = 1 - color[u] ;
                            q.push(v) ;
                        }
                        else if(color[v] == color[u]){
                            isBipartite = false ;
                            break;
                        }
                    }
                }
            }
        }
        
        if(isBipartite){
            cout << "BICOLORABLE" << endl ;
        }
        else{
            cout << "NOT BICOLORABLE" << endl ;
        }
    }
    return 0 ;
}