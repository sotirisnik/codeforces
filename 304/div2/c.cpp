#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, k1, k2, x, turns;

vector <int> p1, p2;
set < vector<int> > s;

vector <int> vstate( vector <int> p1, vector <int> p2 ) {

    vector <int> ret;
    
    for ( int i = 0; i < p1.size(); ++i ) {
        ret.push_back( p1[i] );
    }
    
    ret.push_back( 0 );
    
    for ( int i = 0; i < p2.size(); ++i ) {
        ret.push_back( p2[i] );
    }
    
    return ( ret );

}

int main( ) {

    scanf( "%d", &n );

    scanf( "%d", &k1 );
    
    for ( int i = 1; i <= k1; ++i ) {
        scanf( "%d", &x );
        p1.push_back( x );
    }
    
    scanf( "%d", &k2 );
    
    for ( int i = 1; i <= k2; ++i ) {
        scanf( "%d", &x );
        p2.push_back( x );
    }
    
    bool ok = true;
    
    while ( true ) {

        if ( p1.size() == 0 || p2.size() == 0 ) {
            break;
        }
        
        ++turns;
    
        if ( p1[0] < p2[0] ) {
            p2.push_back( p1[0] );
            p2.push_back( p2[0] );
            p1.erase( p1.begin() );
            p2.erase( p2.begin() );
            if ( s.find( vstate( p1, p2 ) ) == s.end() ) {
                s.insert( vstate( p1, p2 ) );
            }else {
                ok = false;
                break;
            }
        }else {
            p1.push_back( p2[0] );
            p1.push_back( p1[0] );
            p1.erase( p1.begin() );
            p2.erase( p2.begin() );
            if ( s.find( vstate( p1, p2 ) ) == s.end() ) {
                s.insert( vstate( p1, p2 ) );
            }else {
                ok = false;
                break;
            }
        }
    
    }
    
    if ( ok ) {
        printf( "%d %d\n", turns, ( p1.size() > 0 ) ? 1 : 2 );
    }else {
        printf( "-1\n" );
    }
    
    return 0;

}