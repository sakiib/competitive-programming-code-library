#include <bits/stdc++.h>
using namespace std;

/////////////////////////////// Hash Table //////////////////////////
// code courtesy : Sabit Zahin

#define PAD 66667
#define MAX 200010
#define MOD 1000033
unsigned int hashtable[MOD + PAD];
int counter[MOD + PAD];

inline unsigned int smhash( unsigned int h ){
        h ^= h >> 16;
        h *= 0x85ebca6b;
        h ^= h >> 13;
        h *= 0xc2b2ae35;
        h ^= h >> 16;
        return ( h + 1 );
}
inline void Insert( unsigned int x ){
        x = smhash( x );
        int i = x % MOD;
        while ( hashtable[i] && hashtable[i] != x ) i++;
        hashtable[i] = x;
        counter[i]++;
}
inline bool Find( unsigned int x ){
        x = smhash( x );
        int i = x % MOD;
        while ( hashtable[i] && hashtable[i] != x ) i++;
        return hashtable[i] == x;
}
inline int Count( unsigned int x ) {
        x = smhash( x );
        int i = x % MOD;
        while ( hashtable[i] && hashtable[i] != x ) i++;
        if( hashtable[i] != x ) return 0;
        return counter[i];
}
inline void Remove( unsigned int x ) {
        x = smhash( x );
        int i = x % MOD;
        while ( hashtable[i] && hashtable[i] != x ) i++;
        if( hashtable[i] != x ) return;
        counter[i]--;
        if( counter[i] == 0 ) hashtable[i] = 0;
}
/////////////////////////////////////////////////////////////////////


int main( ) {
        memset( hashtable , 0 , sizeof( hashtable ) );
        memset( counter , 0 , sizeof( counter ) );

        return 0;
}




