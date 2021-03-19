/**
 * 试设计一个算法，判断一个无向图G是否是一棵树。若是一棵树，则算法返回true，否则返回false
 */
#include <iostream>
#include <queue>
#define Max_Tree_SIZE 100
using namespace std;
typedef struct Graph{
    int vexnum;
    int Edge[Max_Tree_SIZE][Max_Tree_SIZE];
};
bool visited[Max_Tree_SIZE];
int FirstNeighbor(Graph G , int v){

}
int NextNeighbor(Graph G ,int v , int w){

}
bool isTree(Graph& G){
    for (int i = 0; i < G.vexnum; ++i) {
        /*
         * 访问标记visited[]初始化
         */
        visited[i] = false;

    }
    /*
     * 记录顶点数和边数
     */
    int Vnum = 0, Enum = 0;

}
/*
 * 深度优先遍历图G，统计访问过的顶点数和边数，通过Vｎｕｍ返回和Ｔｎｕｍ返回
 */
void DFS(Graph& G , int v ,int &Vnum, int &Enum ,int visited[]){
    /*
     * 作返回标记，顶点计数
     */
    visited[v] = true;
    Vnum++;
    /*
     * 取v的第一个邻接顶点
     */
    int w = FirstNeighbor(G,v);
    /*
     * 当邻接顶点存在
     */
    while (w!=-1){
        /*
         * 边存在，边计数
         */
        Enum++;
        /*
         * 当该邻接顶点未访问过
         */
        if (!visited[w])
            DFS(G,w,Vnum,Enum,visited);
        w = NextNeighbor(G,v,w);
    }
}