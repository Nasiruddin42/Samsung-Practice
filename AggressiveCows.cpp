/* https://www.geeksforgeeks.org/problems/aggressive-cows/1 */

/* Input: n = 5, stalls[] = [1, 2, 4, 8, 9], k = 3
   Output: 3
*/

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std ;

bool canWePlace(vector<int> &stalls, int dist, int k){
    int cnt = 1 ;
    int last = stalls[0] ;
    for(int i = 1; i < stalls.size(); i++){
        if(stalls[i] - last >= dist){
            last = stalls[i];
            cnt++ ;
        }
    }
    if(cnt >= k){
        return true;
    }
    else return false ;
}

int main(){
    int n, k ;
    cin >> n >> k ;
    vector<int> stalls(n) ;
    for(int i = 0; i < n; i++){
        cin >>  stalls[i] ;
    }
    sort(stalls.begin(), stalls.end()) ;
    int low = 1, high = stalls[n-1] - stalls[0], mid ;
    while(low <= high){
        mid = (low + high) / 2 ;
        if(canWePlace(stalls, mid, k)){
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ;
        }
    }
    cout << high << endl;
    
}