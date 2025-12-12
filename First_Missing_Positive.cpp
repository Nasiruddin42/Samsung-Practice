/* https://leetcode.com/problems/first-missing-positive/description/*/

#include<iostream>
#include<vector>

using namespace std ;

int main(){
    int n;
    cin >> n ;

    vector<int> nums(n) ;
    for(int i = 0; i < n; i++){
        cin >> nums[i] ;
    }
    vector<bool> present(n + 1, false) ;
    for(int x : nums){
        if(x > 0 and x <= n){
            present[x] = true ;
        }
    }
    int f = 0 ;
    for(int i = 1; i <= n; i++){
        if(!present[i]){
            f = 1 ;
            cout << i << endl ;
            break;
        }
    }
    if(f == 0){
        cout << n + 1 << endl ;
    }

    return 0 ;
}