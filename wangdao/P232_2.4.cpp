/*
 * 分别采用基于深度优先遍历和广度优先遍历算法判断以邻接表方式存储的有向图中是否存在由顶点v1到顶点vj的路径(i!=j)。
 * 注意，算法中涉及的图的基本操作必须在此存储结构上实现
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
/*
 * 访问标记数组
 */
bool visited[Max_Tree_SIZE];
int EXist_Path_DFS(Graph G,int i ,int j){
    /*
     * 顶点序号
     */
    int p ;
    /*
     * 深度优先判断有向图G中顶点vi到顶点vj是否有路径，是则返回1，否则返回0
     */
    if (i==j)
        /*
         * i就是j
         */
        return 1;
    else
    {
        /*
         * 置访问标记
         */
        visited[i] = 1;
        for (int p = FirstNeighbor(G,i); p>= 0; p = NextNeighbor(G,i,p)) {
            /*
             * 递归检测邻接点
             */
            if (!visited[p]&&EXist_Path_DFS(G,p,j))
                /*
                 * i下游的顶点到j有路径
                 */
                return 1;

        }
    }
    return 0;
}
int Exist_Path_BFS(Graph G,int i ,int j)
{
    /*
     * 广度优先判断有向图G中顶点vi到顶点vj是否有路径，是则返回1，否则返回0
     */
    queue<int>Q;
    /*
     * 顶点i入队
     */
    Q.push(i);
    /*
     * 非空循环
     */
    while(!Q.empty()){
        /*
         * 队头顶点出队
         */
        int u = Q.front();
        Q.pop();
        /*
         * 置访问标记
         */
        visited[u] = 1;
        /*
         * 检查所有邻接点
         */
        for(int p = FirstNeighbor(G,i);p;p=NextNeighbor(G,u,p)){
            /*int k = p.adjvex;
             * 若k == j，则查找成功
             * if(k==j)
             *  return 1;
             *  否则，顶点k入队
             * if(!visited[k]）
             *  Q.push(k)
            */
        }
    }
    return 0;
}