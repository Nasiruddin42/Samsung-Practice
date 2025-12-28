#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std ;


void bfs(vector<vector<pair<int, double>>> &adj, vector<double> &res, int t){
    queue<pair<int, double>> q ;
    q.push({1, 1}) ;

    int l = 0 ;
    while(!q.empty()){
        int temp = q.size() ;
        while(temp--){
            auto a = q.front() ;
            //cout << a.first<< " " << a.second << endl; 
            q.pop() ;

            if(l == t){
                res[a.first] += a.second ;
            }

            if(l > t) return ;

            for(auto ed : adj[a.first]){
                q.push({ed.first, a.second * ed.second}) ;
            }
        }
        l += 10 ;
    }
}

int main(){
    int testcase;
    cin >> testcase ;

    while(testcase--){
        int n, e, t ;
        cin >> n >> e >> t ;

        vector<vector<pair<int, double>>> adj(n + 1) ;
        int x, y ;
        double p ;

        for(int i = 0; i < e; i++){
            cin >> x >> y >> p ;
            adj[x].push_back({y, p}) ;
        }

        vector<double> res(n + 1, 0.0) ;
        bfs(adj, res, t) ;

        int mx = -1, div = - 1 ;
        double probability = 0;

        for(int i = 1; i <= n; i++){
            //cout << res[i] << endl ;
            if(res[i] > mx){
                mx = res[i] ;
                div = i ;
                probability = res[i];
            }
        }
        cout << div << " " << fixed << setprecision(6) << probability << endl ;
    }
}