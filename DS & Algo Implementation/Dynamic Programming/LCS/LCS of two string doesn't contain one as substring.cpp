#include<bits/stdc++.h>

using namespace std;

const int N = 1005;
int F[N];
string A,B;

void kmp()
{
   F[0] = 0;
   for(int i = 1;i<B.size();i++){
      int j = F[i-1];
      while(j > 0 and B[j] != B[i]){
         j = F[j-1];
      }
      if(B[i] == B[j])j++;
      F[i] = j;
   }
}

int dp[N][N];

int call(int x,int y)
{
    if(y == B.size())return -1e5;
    if(x == A.size())return 0;
    if(dp[x][y] != -1)return dp[x][y];

    int ret = call(x + 1,y);

    if(A[x] == B[y]){
        ret = max(ret,1 + call(x + 1,y + 1));
    }else{
        if(y > 0)ret = max(ret,call(x,F[y - 1]));
        else ret = max(ret,1 + call(x + 1,0));
    }
    return dp[x][y] = ret;
}
int main()
{
    cin >> A >> B;
    kmp();
    for(int i = 0;i < B.size();i++)cout << F[i] << " ";cout << endl;
    memset(dp,-1,sizeof dp);
    cout << call(0,0) << "\n";
}

