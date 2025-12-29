// use binary search 
// x = an + bn [log2(n)] + cn^3
// given a,b,c,x, find n
// https://www.geeksforgeeks.org/find-element-position-in-given-monotonic-sequence/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std ; 

#define small_N  1000000 ;
#define large_N  1000000000000000 ;

long long func(long long a, long long b, long long c, long long n){
    long long res = a * n ;
    long long log_value = floor(log2(n)) ;
    res += (b * n * log_value) ;
    res += (c * (n * n * n)) ;

    return res ;
}

long long GetPositionInSeries( long long a, long long b, long long c, long long k){
    long long start = 1, end = small_N ;

    if(c == 0){
        end = large_N ;
    }
        
    long long ans = 0 ;

    while(start <= end){

        long long mid = (start + end) / 2 ;
        long long val = func(a, b, c, mid) ;
        //cout <<start << " " << end << " " << mid << " " << val << endl ;

        if(val == k){
            ans = mid ;
            break ;
        }
        else if(val > k){
            end = mid - 1 ;
        }
        else{
            start = mid + 1 ;
        }
    }
    return ans ;
}

int main(){
    long long a, b, c, k ;
    cin >> a >> b >> c >> k ;

    cout << GetPositionInSeries(a, b, c, k) << endl ;

    return 0 ;
}