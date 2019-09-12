#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
typedef long long LL;
const int inf = 1000000000;

int month[] = { 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
int monthL[] = { 0 , 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

string day[] = { "Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat"  };
int Da , Ya , Ma , Db , Yb , Mb;

struct date {
    int dd , mm , yy;
    date(){}
    date( int dd , int mm , int yy ) : dd(dd) , mm(mm) , yy(yy){}
};

bool leap( int year ) {
    return (((year % 4 == 0) && (year % 100 != 0)) ||(year % 400 == 0));
}
bool inrange( date a , date b ) {
    if( a.yy > b.yy ) return false;
    if( a.yy < b.yy ) return true;
    if( a.yy == b.yy)  {
        if( a.mm < b.mm ) return true;
        if( a.mm == b.mm ) {
            if( a.dd <= b.dd ) return true;
            return false;
        }
        return false;
    }
    return false;
}
void go( ) {
    int year = 1900 , m = 1 , d = 1;
    int ans = 0;
    for( int i = year; i <= 9999; i++ ) {
        for( int j = 1; j <= 12; j++ ) {
            if( leap(i) ) {
                for( int k = 1; k <= monthL[j]; k++ , d++ ) {
                    if( k == 13 ) {
                        if( day[d%7] == "Fri" && (inrange( date(Da,Ma,Ya) , date(k,j,i) ) && inrange( date(k,j,i) , date(Db,Mb,Yb) ) ) )
                        {
                          ans++;
                        }

                    }
                }
            }
            else {
                for( int k = 1; k <= month[j]; k++ , d++ ) {
                    if( k == 13 ) {
                        if( day[d%7] == "Fri" && ( inrange( date(Da,Ma,Ya) , date(k,j,i) ) && inrange( date(k,j,i) , date(Db,Mb,Yb) ) ))
                        {
                          ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
int main( int argc , char const *argv[] ){
    ios_base::sync_with_stdio( false ); cin.tie( NULL );
    int t;
    cin >> t;
    while( t-- ) {
        cin >> Da >> Ma >> Ya;
        cin >> Db >> Mb >> Yb;
        go( );
    }
    return 0;
}
