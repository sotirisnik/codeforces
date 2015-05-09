#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXN 100
#define MAXK 26

using namespace std;

int k, how;
char text[MAXN+1];
int cnt[MAXK+1];

int main( ) {

    scanf( "%d %s", &k, text );

    cnt[ text[0]-'a' ] = 1;
    how = 1;
    
    for ( int i = 1; text[i] != '\0' && how < k; ++i ) {
    
        if ( cnt[ text[i]-'a' ] == 0 ) {
            cnt[ text[i]-'a' ] = 1;
            ++how;
        }
    
    }
    
    if ( how < k ) {
        printf( "NO\n" );
    }else {
        printf( "YES\n" );
        printf( "%c", text[0] );
        cnt[ text[0]-'a' ] = 0;
        for ( int i = 1; text[i] != '\0'; ++i ) {
            if ( cnt[ text[i]-'a' ] == 1 ) {
                printf( "\n" );
                cnt[ text[i]-'a' ] = 0;
            }
            printf( "%c", text[i] );
        }
        printf( "\n" );
    }
    
    return 0;

}