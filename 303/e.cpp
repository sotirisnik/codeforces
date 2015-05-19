#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

#define MAXN 300000

using namespace std;

struct state {
    unsigned long long cost;
    int id, edge_id;
    state( unsigned long long cost, int id, int edge_id ) : cost(cost), id(id), edge_id(edge_id) { }
};

bool operator < ( const state &a, const state &b ) {
    return ( a.cost > b.cost );
}

int n, m, from, to, cost, start;
unsigned long long sum;
vector < list<state> > adj(MAXN+1);
int P[MAXN+1], E[MAXN+1];
unsigned long long W[MAXN+1];
unsigned long long D[MAXN+1];
priority_queue <state> q;

int main( ) {

    scanf( "%d %d", &n, &m );
    
    for ( int i = 1; i <= m; ++i ) {
        scanf( "%d %d %d", &from, &to, &cost );
        adj[from].push_back( state( cost, to, i ) );
        adj[to].push_back( state( cost, from, i ) );
    }
    
    scanf( "%d", &start );
    
    for ( int i = 1; i <= n; ++i ) {
        D[i] = -1;
    }
    
    q.push( state( 0, start, 0 ) );
    D[start] = 0;
    P[start] = -1;
    
    while ( !q.empty() ) {
        
        state top = q.top();
        q.pop();
        
        for ( list<state>::iterator pos = adj[top.id].begin(); pos != adj[top.id].end(); ++pos ) {
            if ( D[pos->id] == -1 || D[top.id]+pos->cost < D[pos->id] || ( D[top.id]+pos->cost == D[pos->id] && W[pos->id] > pos->cost ) ) {
                D[pos->id] = D[top.id]+pos->cost;
                P[pos->id] = top.id;
                E[pos->id] = pos->edge_id;
                W[pos->id] = pos->cost;
                q.push( state( D[pos->id], pos->id, pos->edge_id ) );
            }
        }
        
    }
    
    for ( int i = 1; i <= n; ++i ) {
        sum += W[i];
    }
    
    printf( "%I64d\n", sum );
    
    int k = 1;
    
    for ( ; k <= n; ++k ) {
        if ( D[k] != 0 ) {
            printf( "%d", E[k] );
            break;
        }
    }
    
    for ( ++k; k <= n; ++k ) {
        if ( D[k] != 0 ) {
            printf( " %d", E[k] );
        }
    }
    
    
    
    printf( "\n" );
    
    return 0;

}