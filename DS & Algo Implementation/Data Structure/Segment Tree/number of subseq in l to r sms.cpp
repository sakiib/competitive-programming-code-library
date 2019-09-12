#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template <typename Arg1>
void __f( const char* name , Arg1&& arg1 ) {
        cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f( const char* na , Arg1&& arg1 , Args&&... args ) {
        const char* c = strchr( na + 1 , ',' );
        cerr.write( na , c - na ) << " : " << arg1 << " , ";
        __f( c + 1 , args... );
}
#define endl "\n"
#define all(V) V.begin(),V.end()
#define Unique(V) sort(all(V)),V.erase(unique(all(V)),V.end())
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int LL;
const int N = 1e5 + 5;

string s;

struct segment {
        LL s , m , sm , ms , sms;
        segment(){}
        segment( LL s , LL m , LL sm , LL ms , LL sms ) :
                s(s) , m(m) , sm(sm) , ms(ms) , sms(sms) {}
} tree[ 4*N ];

void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                if( s[b] == 's' ) tree[node].s++;
                if( s[b] == 'm' ) tree[node].m++;
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node].s = tree[l].s + tree[r].s;
        tree[node].m = tree[l].m + tree[r].m;
        tree[node].sm = tree[l].s * tree[r].m + tree[l].sm + tree[r].sm;
        tree[node].ms = tree[l].m * tree[r].s + tree[l].ms + tree[r].ms;
        tree[node].sms = tree[l].s * tree[r].ms + tree[l].sm * tree[r].s +
                                            tree[l].sms + tree[r].sms;
}
segment query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return segment(0,0,0,0,0);
        if( i <= b && j >= e ) return tree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        segment x = query( l , b , m , i , j );
        segment y = query( r , m + 1 , e , i , j );
        segment ret;
        ret.s = x.s + y.s;
        ret.m = x.m + y.m;
        ret.sm = x.s * y.m + x.sm + y.sm;
        ret.ms = x.m * y.s + x.ms + y.ms;
        ret.sms = x.s * y.ms + x.sm * y.s + x.sms + y.sms;
        return ret;
}
int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        cin >> s;
        s = "#" + s;
        build( 1 , 1 , s.size() - 1 );
        int q;
        cin >> q;
        while( q-- ) {
                int l , r;
                cin >> l >> r;
                segment res = query( 1 , 1 , s.size() - 1 , l , r );
                //trace( res.s , res.m, res.sm ,res.ms, res.sms );
                cout << res.sms << endl;
        }
        return 0;
}








