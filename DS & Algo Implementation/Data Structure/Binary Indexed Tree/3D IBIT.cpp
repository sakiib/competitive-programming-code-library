#include <bits/stdc++.h>
using namespace std;
bool BIT[205][205][205];
int xl,xr,xq,yl,yr,yq,zl,zr,zq,gapx,gapy,gapz,r,tc,q;
char c[5];

void update(int x,int y,int z){
  for(int i = x; i <= gapx; i += i & -i)
    for(int j = y; j <= gapy; j += j & -j)
      for(int k = z; k <= gapz; k += k & -k)
          BIT[i][j][k] ^= 1;
}

bool query(int x,int y,int z){
  bool res = 0;
  for(int i = x; i > 0; i -= i & -i)
    for(int j = y; j > 0; j -= j & -j)
      for(int k = z; k > 0; k -= k & -k)
          res ^= BIT[i][j][k];
  return res;
}

int main(){
  scanf("%d",&tc);
  while(tc--){
    scanf("%d %d %d %d %d %d",&xl,&yl,&zl,&xr,&yr,&zr);
    gapx = xr-xl+1;
    gapy = yr-yl+1;
    gapz = zr-zl+1;

    for(int i = 1;i <= gapx; i++)
      for(int j = 1; j <= gapy; j++)
        for(int k = 1; k <= gapz; k++)
          BIT[i][j][k]=0;

    scanf("%d",&q);
    /// range update & point query
    while(q--){
      scanf("%s",c);
      if(c[0]=='U'){
        scanf("%d %d %d %d",&xq,&yq,&zq,&r);

        int xb = xq-xl+r+2;
        int xa = max(1,xq-xl+1-r);
        int yb = yq-yl+r+2;
        int ya = max(1,yq-yl+1-r);
        int zb = zq-zl+r+2;
        int za = max(1,zq-zl+1-r);
        // inklusi-eksklusi
        update(xb,yb,zb);
        update(xa,ya,za);
        update(xb,ya,za);
        update(xa,yb,za);
        update(xa,ya,zb);
        update(xb,yb,za);
        update(xb,ya,zb);
        update(xa,yb,zb);
      }
      else if(c[0]=='Q'){
        scanf("%d %d %d",&xq,&yq,&zq);
        xq=xq-xl+1;
        yq=yq-yl+1;
        zq=zq-zl+1;

        bool res = query(xq,yq,zq);
        if(res)
            printf("Friend\n");
        else
            printf("Enemy\n");
      }
    }
  }
  return 0;
}

