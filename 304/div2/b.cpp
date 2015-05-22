#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXN 3000

using namespace std;

int n, cnt, cost, maxu;
int A[MAXN+1];

int main( ) {

    scanf( "%d", &n );

    for ( int i = 1; i <= n; ++i ) {
        scanf( "%d", &A[i] );
    }
    
    sort( A+1, A+n+1 );
    
    maxu = A[1];
    
    for ( int i = 2; i <= n; ++i ) {
        if ( A[i] <= maxu ) {
            cost += maxu - A[i] + 1;
            A[i] = maxu + 1;
        }
        maxu = max( maxu, A[i] );
            
    }
    
    printf( "%d\n", cost );
    
    return 0;

}