/*
 * 假设图用邻接表表示，设计一个算法，输出从顶点Vi到顶点Vj的所有简单路径
 */
#include <iostream>
#include <stack>
#include <queue>
#define Max_Tree_SIZE 100
using namespace std;
typedef struct Graph{
    int vexnum;
    int Edge[Max_Tree_SIZE][Max_Tree_SIZE];
};
int FirstNeighbor(Graph G , int v){

}
int NextNeighbor(Graph G ,int v , int w){

}
void FindPath(Graph *G,int u ,int v,int path[],int d){
    int w ,i;
    /*
     * ArcNode *p;
     *
     * 路径长度加1
     * d++;
     *
     * 将当前顶点添加到路径中
     * path[d] = u;
     * 置已访问标记
     * visited[u] = 1;
     * 找到一条路径则输出
     * if(u==v)
     *      print(path[]);
     * p指向u的第一个相邻点
     * p = G->adjlist[u].firstarc；
     * while(p!=NULL){
     * 若顶点w未访问，递归访问它
     *      w = p -> adjvex;
     * if(!visited[w] == 0)
     * FindPath(G,w,V,path,d);
     * p指向u的下一个相邻点
     * p = p -> nextarc;}
     * 恢复环境，使该顶点可以重新使用
     * visited[u] = 0;
     */
}