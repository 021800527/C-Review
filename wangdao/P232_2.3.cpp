/**
 * 写出图的深度优先搜索DFS算法的非递归算法（图采用邻接表形式）
 */
/*
 * 在深度优先搜索的分递归算法中使用了一个栈S来记忆下一步可能访问的顶点，
 * 同时使用了一个访问标记数组visited[]来记忆第i个顶点是否在栈内或曾经在栈内
 * 若是则它以后不能再进栈。图采用邻接表形式，算法的实现如下。
 */
#include <iostream>
#include <stack>
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
/*
 * 从顶点v开始进行深度优先搜索，一次遍历一个连通分量的所有顶点
 */
void DFS_Non_Rc(Graph &G ,int v){
    /*
     *顶点序号
     */
    int w;
    /*
     * 初始化栈
     */
    stack<int>S;
    /*
     * 初始化visited
     */
    for (int i = 0; i < G.vexnum; ++i) {
       visited[i] = false;
    }
    /*
     * v入栈并置visited[v]
     */
    S.push(v);
    v = S.top();
    visited[v] = true;
    while(S.empty()){
        /*
         * 栈中退出一个顶点
         */
        int k = S.top();
        S.pop();
        /*
         * 先访问，再将其子结点入栈
         */
        cout<<k;
        /*
         * k所有邻接点
         */
        for (int w= FirstNeighbor(G,k);  w>=0 ; w=NextNeighbor(G,k,w)) {
            /*
             * 未进过栈的顶点入栈
             */
            if (!visited[w]){
                S.push(w);
                /*
                 * 作标记，以免再次入栈
                 */
                visited[w] = true;
            }
        }
    }
}