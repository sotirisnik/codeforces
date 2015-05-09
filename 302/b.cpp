#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXN 100

using namespace std;

int n, k, cnt;
char cur;
char maze[MAXN+1][MAXN+1];

int main( ) {

    scanf( "%d %d", &n, &k );
    
    for ( int i = 0; i < n; ++i ) {
    
        if ( !(i & 1) ) {
            cur = 'L';
        }else {
            cur = 'S';
        }
    
        for ( int j = 0; j < n; ++j ) {
            
            if ( cur == 'L' && cnt+1 <= k ) {
                maze[i][j] = cur;
                ++cnt;
            }else {
                maze[i][j] = 'S';
            }
            
            if ( cur == 'L' ) {
                cur = 'S';
            }else {
                cur = 'L';
            }
        
        }
    
    }
    
    if ( cnt != k ) {
        printf( "NO\n" );
    }else {
        printf( "YES\n" );
        for ( int i = 0; i < n; ++i ) {
            printf( "%s\n", maze[i] );
        }
    }
    
    return 0;

}