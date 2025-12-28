/* [https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/](https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/)[https://www.careercup.com/page?pid=samsung-interview-questions](https://www.careercup.com/page?pid=samsung-interview-questions)


A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and the edge weights are the probabilities of the doctor going from that division to other connected division but the doctor stays 10mins at each division now there will be given time and had to find the division in which he will be staying by that time and is determined by finding division which has high probability.

Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division in which he will be there, the edges starting point, end point, probability.

Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling time is not considered and during that 10min at 10th min he will be in next division, so be careful.

find the division with highest probability that doctor is in it after 10 min is div 3 and probability is 0.7.

After 9 minutes dr has yet to move to another division he is in div 1 and probability is 1.0. Forty minutes later the division with highest probabilty is 6 and probabilty is 0.77400

> Input:
> 
> 
> 2
> 6 10 40
> 1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
> 6 10 10
> 1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
> 
> Output :
> 
> 6 0.774000
> 
> 3 0.700000
>
*/


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