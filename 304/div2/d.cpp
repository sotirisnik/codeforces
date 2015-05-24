#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#define MAXN 5000000

using namespace std;

int t, from, to;
int A[MAXN+1], F[MAXN+1], primediviser[MAXN+1];
bool p[MAXN+1];

void sieve( ) {

    for ( int i = 2; i <= MAXN; ++i ) {
        p[i] = true;
    }

    int sqrt_MAXN = sqrt( MAXN );
        
    for ( int i = 2; i <= MAXN+1; ++i ) {
        if ( p[i] ) {
            primediviser[i] = i;
            for ( int j = 2*i; j <= MAXN+1; j += i ) {
                p[j] = false;
                primediviser[j] = i;
            }
        }
    }
    
}

int main( ) {
   
    sieve( );
   
    scanf( "%d", &t );
   
    for ( int i = 2; i <= MAXN; ++i ) {
        A[i] = 1 + A[ i / primediviser[i] ];
        F[i] = F[i-1] + A[i];
    }
   
    for ( int i = 0; i < t; ++i ) {
        scanf( "%d %d", &to, &from );
        int ans = F[to] - F[from];
        printf( "%d\n", ans );
    }
    
    return 0;
    
}