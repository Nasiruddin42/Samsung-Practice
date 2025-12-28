/*https://github.com/Rahat-Khan-Pathan/Samsung-Bangladesh-Pre-Employment-Coding-Test-Preparation/tree/main/Physical%20Energy*/

/* ### Problem Description

You are a marathoner trying to break your previous record. You have 5 different speed options, each with a corresponding stamina loss (e.g., Speed 1: 5 minutes per unit distance, Stamina loss: 15). You can switch between speeds after completing each unit interval.

Given your total stamina H (1 ≤ H ≤ 160) and the distance D (1 ≤ D ≤ 40) you need to run, find the minimum time to finish the marathon while staying within your stamina limits (you cannot run with stamina ≤ 0).

**Given**

1. An initial amount of energy `H`.
2. A total distance `D` to travel.
3. Five speeds, each with associated:
    - **Cost of traveling 1 km** (energy required per km).
    - **Time taken to travel 1 km** (time required per km).

**Input**

- An integer `H` representing the initial amount of energy.
- An integer `D` representing the total distance to be traveled.
- A list of five integers representing the energy cost to travel 1 km for each speed.
- A list of five integers representing the time taken to travel 1 km for each speed.

### Test Case
t = 1
**Input:**

```
5 3000 10
4 200
5 210
2 230
3 235
6 215
```

**Output:**
2000
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std ;

int n, energy, dist ;
vector<int> cost, tm ;
vector<vector<vector<int>>> dp ;

int solve(int energy, int dist, int n){
    if(energy <= 0 || n == 0) return 1e9 ;
    if(dist == 0) return 0 ;

    if(dp[energy][dist][n] != -1) return dp[energy][dist][n] ;

    return dp[energy][dist][n] = min(solve(energy, dist, n - 1), 
                        tm[n - 1] + solve(energy - cost[n - 1], dist - 1, n)) ;
}

int main(){
    int test ;
    cin >> test ;
    while(test--){
        cin >> n >> energy >> dist ;

        cost.resize(n) ;
        tm.resize(n) ;

        for(int i = 0; i < n; i++){
            cin >> cost[i] >> tm[i] ;
        }

        dp.assign(energy + 1, vector<vector<int>>(dist + 1, vector<int>(n + 1, -1))) ;

        cout << solve(energy, dist, n) << endl ;

    }
}