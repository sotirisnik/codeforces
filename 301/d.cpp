#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <algorithm>

#define MAXN 100

using namespace std;

int r, s, p;
double memo[MAXN+1][MAXN+1][MAXN+1];

double best( int rocks, int scissors, int papers ) {

    if ( memo[rocks][scissors][papers] > -0.5 ) {
        return ( memo[rocks][scissors][papers] );
    }

    if ( rocks == r && scissors == s && papers == p ) {
        return 1;
    }

    double Best = 0;
    
    if ( scissors+1 <= s ) {
        ++scissors;
        double pairs = ( rocks * scissors + rocks * papers + scissors * papers );
        if ( pairs > 0 && rocks*scissors > 0 ) {
            Best += ( (double)(rocks*scissors) / (double)(pairs) ) * best( rocks, scissors, papers );
        }
        --scissors;
    }
    if ( papers+1 <= p ) {
        ++papers;
        double pairs = ( rocks * scissors + rocks * papers + scissors * papers );
        if ( pairs > 0 && scissors * papers > 0 ) {
            Best += ( (double)(scissors*papers) / (double)(pairs) ) * best( rocks, scissors, papers );
        }
        --papers;
    }
    if ( rocks+1 <= r ) {
        ++rocks;
        double pairs = ( rocks * scissors + rocks * papers + scissors * papers );
        if ( pairs > 0 && papers*rocks > 0 ) {
            Best += ( (double)(papers*rocks) / (double)(pairs) ) * best( rocks, scissors, papers );
        }
        --rocks;
    }
    
    memo[rocks][scissors][papers] = Best;
    
    return ( Best );

}


int main( ) {

    scanf( "%d %d %d", &r, &s, &p );
    
    double sum_r = 0, sum_s = 0, sum_p = 0;
    
    memset( memo, -1, sizeof( memo ) );
    
    for ( int i = 1; i <= r; ++i )
        sum_r += best( i, 0, 0 );
    
    for ( int i = 1; i <= s; ++i )
        sum_s += best( 0, i, 0 );

    for ( int i = 1; i <= p; ++i )
        sum_p += best( 0, 0, i );
    
    printf( "%.9llf %.9lf %.9lf\n", sum_r, sum_s, sum_p );
    
    return 0;

}