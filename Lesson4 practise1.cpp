#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXN 100 
using namespace std;
struct Node
{
    int x,y,w;
    bool flag;
};
Node edge[MAXN*MAXN];
bool cmp(Node a,Node b)
{
    return a.w<b.w;
}
int n,m,father[MAXN];
int kruskal(int num,int m)
{
    int ans=0,cnt=1;
    for(int i=1; i<=m; ++i)
    {
        if(i==num)  
            continue;
        int s1=father[edge[i].x];
        int s2=father[edge[i].y];
        if(s1!=s2)
        {
            cnt++;
            ans+=edge[i].w;
            father[s2]=s1; 
            for(int j=0; j<=n; ++j)
                if(father[j]==s2)
                    father[j]=s1;
        }
    }
    if(cnt!=n)
        return -1;
    else
        return ans;
}
int main()
{
    int t,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; ++i)
            father[i]=i;
        for(int i=1; i<=m; ++i)
        {
            scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].w);
            edge[i].flag=false;
        }
        sort(edge+1,edge+1+m,cmp);
        ans=0;
        for(int i=1; i<=m; ++i)
        {
            int s1=father[edge[i].x];
            int s2=father[edge[i].y];
            if(s1!=s2)
            {
                edge[i].flag=true;  
                ans+=edge[i].w;
                father[s2]=s1;
                for(int j=0; j<=n; ++j)
                    if(father[j]==s2)
                        father[j]=s1;
            }
        }
        bool flag=0;
        for(int i=1; i<=m; ++i) 
        {
            if(edge[i].flag==false)
                continue;
            int sum=0;
            for(int j=1; j<=n; ++j)
                father[j]=j;
            sum=kruskal(i,m); 
            if(sum==ans)
            {
                flag=true;
                break;
            }
        }
        if(flag)
            printf("Not Unique!\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}

