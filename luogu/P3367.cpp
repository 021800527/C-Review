#include<iostream>
using namespace std;
int i,j,k,n,m,s,ans,f[10010],p1,p2,p3;
//f[i]表示i的集合名
int find(int k){
    //路径压缩
    if(f[k]==k)return k;
    return f[k]=find(f[k]);
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        f[i]=i;//初始化i的老大为自己
    for(i=1;i<=m;i++){
        cin>>p1>>p2>>p3;
        if(p1==1)
            f[find(p2)]=find(p3);
            //p3打赢了p2
        else
        if(find(p2)==find(p3))
            //是否是一伙的
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
