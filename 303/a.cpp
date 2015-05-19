#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXN 100

using namespace std;

int n, x, cnt;
bool is_good[MAXN+1];

int main( ) {

    scanf( "%d", &n );
    
    for ( int i = 1; i <= n; ++i ) {
        is_good[i] = true;
    }
    
    for ( int i = 1; i <= n; ++i ) {
        
        for ( int j = 1; j <= n; ++j ) {
            scanf( "%d", &x );
            
            if ( x == 1 ) {
                is_good[i] = false;
            }else if ( x == 2 ) {
                is_good[j] = false;
            }else if ( x == 3 ) {
                is_good[i] = false;
                is_good[j] = false;
            }
            
        }
        
    }
    
    for ( int i = 1; i <= n; ++i ) {
        if ( is_good[i] ) {
            ++cnt;
        }
    }
    
    printf( "%d\n", cnt );
    
    int i = 1;
    
    for ( ; i <= n; ++i ) {
       if ( is_good[i] ) {
            printf( "%d", i );
            break;
        }
    }
    
    for ( ++i ; i <= n; ++i ) {
        if ( is_good[i] ) {
            printf( " %d", i );
        }
    }
    
    return 0;

}