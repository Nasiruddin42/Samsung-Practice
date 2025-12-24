/*https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/sum-of-nodes-in-kth-level/problem*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    
    int l = -1, ans = 0 ;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '('){
            l++ ;
        }
        else if(s[i] == ')'){
            l-- ;
        }
        else if(l == n){
            string temp = "" ;
            while(i < (int)s.size() && s[i] != '(' && s[i] != ')'){
                temp += s[i] ;
                i++ ;
            }
            i-- ;
            ans += stoi(temp) ;
        }
    }
    cout << ans << endl ;
    return 0;
}
