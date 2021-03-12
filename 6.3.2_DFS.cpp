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
void DFS(Graph G,int v){
    cout<<v;
    visited[v]= true;
    for (auto w = FirstNeighbor(G,v);  w>=0 ; w = NextNeighbor(G,v,w)) {
        if (!visited[w])
            DFS(G,w)
    }
}
void DFSTraverse(Graph G){
    for (int i = 0; i < G.vexnum; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < G.vexnum; ++i) {
        if (!visited[i])
            DFS(G,i);
    }
}