#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, m ;
vector<vector<int>>adj ;

vector<int> path ;
vector<int> visited, inStack ;

vector<int> bestCycle ;
int bestSum = INT_MAX ;

void dfs(int u){
    visited[u] = true ;
    inStack[u] = true ;
    
    path.push_back(u) ;
    
    for(auto v : adj[u]){
        if(!visited[v]){
            dfs(v) ;
        }
        else if(inStack[v]) {
            
            vector<int> cycle ;
            int sum = 0 ;
            for(int i = path.size() - 1; i >= 0; i--){
                cycle.push_back(path[i]) ;
                sum += path[i] ;
                if(path[i] == v) break ;
            }
            sort(cycle.begin(), cycle.end()) ;
            
            // int sum = 0 ;
            // for(auto it : cycle){
            //     sum += it ;
            // }
            if(sum < bestSum){
                bestSum = sum ;
                bestCycle = cycle ;
            }
        }
    }
    inStack[u] = false ;
    visited[u] = false ;
    path.pop_back() ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    cin >> n >> m ;
    
    adj.assign(n + 1, vector<int>()) ;
    visited.resize(n + 1, 0) ;
    inStack.resize(n + 1, 0) ;
    path.clear() ;
    bestCycle.clear() ;
    bestSum = INT_MAX;
    
    for(int i = 0; i < m; i++){
        int u, v ;
        cin >> u >> v ;
        adj[u].push_back(v) ;
    }
    
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i) ;
        }
    }
    
    for(auto x : bestCycle){
        cout << x << " " ;
    }
    cout << endl ;
    return 0;
}
