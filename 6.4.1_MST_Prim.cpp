#include <iostream>
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
void MST_Prim(Graph G){
    int min_weight[G.vexnum];
    int adjvex[G.vexnum];
    for (int i = 0; i < G.vexnum; ++i) {
        min_weight[i] = G.Edge[0][i];
        adjvex[i] = 0;
    }
    int min_arc;
    int min_vex;
    for (int i = 1; i < G.vexnum; ++i) {
        min_arc = Max_Tree_SIZE;
        for (int j = 1; j < G.vexnum; ++j) {
            if (min_weight[j]!=0 && min_weight[j]<min_arc){
                min_arc = min_weight[j];
                min_vex = j;
            }
            min_weight[min_vex] = 0;
            for (int j = 0; j < G.vexnum; ++j) {
                if (min_weight[j]!=0 && G.Edge[min_arc][j]<min_weight[j]){
                    min_weight[j] = G.Edge[min_arc][j];
                    adjvex[j] = min_arc;
                }
            }
        }
    }
}