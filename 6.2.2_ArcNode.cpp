#include <iostream>
using namespace std;
#define MaxVertexNum 100
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
}ArcNode;
typedef struct VNode{
    int data;
    ArcNode *first;
}VNode,AdjList[MaxVertexNum];
typedef struct ALGraph{
    AdjList vetices;
    int vexnum,arcnum;
}ALGraph;