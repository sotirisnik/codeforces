#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>

#define MAXN 500

using namespace std;

queue < pair<int,int> > q;
int rows, cols, start_x, start_y, goal_x, goal_y;
bool found;
char maze[MAXN+1][MAXN+1];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool valid( int x, int y ) {
    return ( x >= 0 && y >= 0 && x < rows && y < cols );
}

bool check( int x, int y ) {
    return ( x == goal_x && y == goal_y );
}

int main( ) {

    scanf( "%d %d", &rows, &cols );
    
    for ( int i = 0; i < rows; ++i ) {
        scanf( "%s", maze[i] );
    }
    
    scanf( "%d %d %d %d", &start_x, &start_y, &goal_x, &goal_y );
    
    --start_x;
    --start_y;
    --goal_x;
    --goal_y;
    
    q.push( make_pair( start_x, start_y ) );
    
    while ( !q.empty() && !found ) {
    
        pair<int,int> top = q.front();
        q.pop();
        
        for ( int k = 0; k < 4 && !found; ++k ) {
            int next_x = top.first + dx[k];
            int next_y = top.second + dy[k];
            if ( valid( next_x, next_y ) ) {
                if ( maze[next_x][next_y] == '.' ) {
                    q.push( make_pair( next_x, next_y ) );
                    maze[next_x][next_y] = 'X';
                }else {
                    if ( check( next_x, next_y ) ) {
                        found = true;
                    }
                }
            }
        }
    
    }
    
    if ( found ) {
        printf( "YES\n" );
    }else {
        printf( "NO\n" );
    }
    
    return 0;

}