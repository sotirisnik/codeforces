#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXN 100000

using namespace std;

struct state {
    long long val, height;
};

int n, x, h, cnt;
state A[MAXN+1];
bool is_good[MAXN+1], is_left[MAXN+1], is_right[MAXN+1];

int main( ) {

    scanf( "%d", &n );
    
    is_good[1] = is_good[n] = true;
    is_right[1] = true;
    is_left[n] = true;
    
    for ( int i = 1; i <= n; ++i ) {
        scanf( "%d %d", &A[i].val, &A[i].height );
    }
    
    for ( int i = 2; i < n; ++i ) {
    
        if ( A[i].val-A[i].height > A[i-1].val ) {
            if ( is_right[i-1] && A[i-1].val+A[i-1].height < A[i].val-A[i].height ) {
                is_good[i] = true;
                is_left[i] = true;
                continue;
            }
        }
        
        if ( A[i].val+A[i].height < A[i+1].val ) {
            if ( is_left[i+1] ){
                if ( A[i+1].val-A[i+1].height > A[i].val+A[i].height ) {
                    is_good[i] = true;
                    is_right[i] = true;
                 }
            }else {
                is_good[i] = true;
                is_right[i] = true;
            }
        }
    }

    for ( int i = 1; i <= n; ++i ) {
        if ( is_good[i] ) {
            ++cnt;
        }
    }
    
    printf( "%d\n", cnt );
 
    return 0;

}