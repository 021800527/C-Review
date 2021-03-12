#include <iostream>
#include <queue>
#define Max_Tree_SIZE 100
using namespace std;
typedef struct Graph{
    int vexnum;
};
int FirstNeighbor(Graph G , int v){

}
int NextNeighbor(Graph G ,int v , int w){

}
bool visited[Max_Tree_SIZE];
queue<int>Q;
void BFS(Graph G , int v){
    cout<<v;
    visited[v] = true;
    Q.push(v);
    while (!Q.empty()){
        Q.pop();
        for (auto w= FirstNeighbor(G,v);  w>=0< ; w = NextNeighbor(G,v,w)) {
            if (!visited[w]){
                cout<<w;
                visited[w]= true;
                Q.push(w);
            }
        }
    }
}
void BFSTraverse(Graph G){
    for (int i = 0; i < G.vexnum; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < G.vexnum; ++i) {
        if (!visited[i])
            BFS(G,i);
    }
}
int d[Max_Tree_SIZE];
void BFS_MI_Distance(Graph G ,int u){
    for (int i = 0; i < G.vexnum; ++i) {
        d[i] = Max_Tree_SIZE;
    }
    visited[u] = true;
    d[u] = 0;
    Q.push(u);
    while (!Q.empty()){
        Q.pop();
        for (auto w= FirstNeighbor(G,u);  w>=0 ; w = NextNeighbor(G,u,w)) {
            if (!visited[w]){
                visited[w] = true;
                d[w] = d[u] + 1;
                Q.push(w);
            }
        }
    }
}