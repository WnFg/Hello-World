#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include <iostream>
using namespace std;
vector<int>v[300005];
int Tree[300005],st[300005],ed[300005],i,j,m,n,p,k,tot,x,y,deep[300005],fa[200005][20],a[300005],q,ans;
void get(int x)
{
      int i;
      for (i=1;i<=18;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
}
void dfs(int x)
{
      get(x);
      int i;
      st[x]=++tot;
      for (i=0;i<v[x].size();++i)
      {
           int j=v[x][i];
           if (j==fa[x][0]) continue;
           fa[j][0]=x;
           deep[j]=deep[x]+1;
           dfs(j);
      }
      ed[x]=++tot;
}
int lowbit(int x) { return x&-x; }
void update(int x,int y)
{
      for (;x<=tot;x+=lowbit(x)) Tree[x]^=y;
}
int ask(int x)
{
      int sum=0;
      for (;x;x-=lowbit(x)) sum^=Tree[x];
      return sum;
}
int lca(int x,int y)
{
      int i,j,k;
      if (deep[x]<deep[y]) swap(x,y);
      k=deep[x]-deep[y];
      for (i=18;i>=0;--i) if (k&(1<<i)) x=fa[x][i];
      if (x==y) return x;
      for (i=18;i>=0;--i)
        if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
        return fa[x][0];
}
int main()
{
     int T;
     scanf("%d",&T);
     for (;T--;)
 {
      for (i=1;i<=2*n;++i) Tree[i]=deep[i]=0; tot=0;
      for (i=1;i<=n;++i) for (j=0;j<=18;++j) fa[i][j]=0;
    scanf("%d%d",&n,&q);
    for (i=1;i<n;++i) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
    for (i=1;i<=n;++i) scanf("%d",&a[i]),a[i]++;
    dfs(1);
    for (i=1;i<=n;++i) cout<<st[i]<<" "<<ed[i]<<endl;
    for (i=1;i<=n;++i) update(st[i],a[i]),update(ed[i],a[i]);
    for (;q--;)
  {
        int type;
        scanf("%d",&type);
        if (type&1)
        {
              scanf("%d%d",&x,&y);
              cout<<st[x]<<" YY  "<<st[y]<<endl;
              cout<<ask(st[x])<<" XX "<<ask(st[y])<<endl;
              ans=ask(st[x])^ask(st[y])^a[lca(x,y)];
              if (ans==0) printf("-1\n");
              else printf("%d\n",ans-1);
        }
        else 
        {
              scanf("%d%d",&x,&y);
              update(st[x],a[x]); update(ed[x],a[x]);
              a[x]=y+1;
              update(st[x],a[x]); update(ed[x],a[x]);
        }
  }
}
}
