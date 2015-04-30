#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXN 1000

using namespace std;

int n, ans;
char orig[MAXN+1], final[MAXN+1];

int main( ) {

    scanf( "%d", &n );
    
    scanf( "%s %s", orig, final );

    for ( int i = 0; i < n; ++i ) {
        ans += min( abs( (orig[i]-'0') - (final[i]-'0') ), min( (orig[i]-'0'), (final[i]-'0') ) + 10 - max( (orig[i]-'0'), (final[i]-'0') ) );
    }
    
    printf( "%d\n", ans );
    
    return 0;

}