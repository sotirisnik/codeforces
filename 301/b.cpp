#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXN 999

using namespace std;

int n, k, p, x, y, sum, cnt;
int A[MAXN+1], B[MAXN+1];

int main( ) {

    scanf( "%d %d %d %d %d", &n, &k, &p, &x, &y );
    
    for ( int i = 1; i <= k; ++i ) {
        scanf( "%d", &A[i] );
        sum += A[i];
    }
    
    for ( int i = k+1; i <= n; ++i ) {
        A[i] = 1;
        ++sum;
        B[++cnt] = A[i];
    }
        
    sort( A+1, A+n+1 );
    
    cnt = 0;
    
    int how = n-k;
    
    if ( A[(n+1)/2] < y ) {
        for ( int i = (n+1)/2; how >= 1 && i <= n; ++i ) {
            if ( A[i] < y ) {
                ++cnt;
                sum += y-A[cnt];
                B[cnt] = y;
                A[cnt] = y;
            }else {
                break;
            }
            --how;
        }
    }
    
    sort( A+1, A+n+1 );
    
    if ( sum > x || A[ (n+1)/2 ] < y ) {
        printf( "-1\n" );
    }else {
        printf( "%d", B[1] );
        for ( int i = 2; i <= n-k; ++i )
            printf( " %d", B[i] );
        printf( "\n" );
    }
    
    return 0;

}