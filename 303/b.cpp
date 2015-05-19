#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int cnt_s, cnt_t;
string s, t, p;

int main( ) {

    cin >> s >> t;
    
    for ( int i = 0; i < s.size(); ++i ) {
        if ( s[i] == t[i] ) {
            p += s[i];
        }else {
        
            if ( cnt_s <= cnt_t ) {
                p += s[i];
                ++cnt_s;
            }else {
                p += t[i];
                ++cnt_t;
            }
        
        }
    }
    
    if ( cnt_s != cnt_t ) {
        printf( "impossible\n" );
    }else {
        printf( "%s\n", p.c_str() );
    }
    
    return 0;

}