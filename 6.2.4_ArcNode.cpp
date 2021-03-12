#include <iostream>
using namespace std;
#define MaxVertexNum 100
typedef struct ArcNode{
    int ivex,jvex;
    struct ArcNode *ilink,*jlink;
}ArcNode;
typedef struct VNode{
    int data;
    ArcNode *firstedge;
}VNode,AdjList[MaxVertexNum];
typedef struct ALGraph{
    VNode adjList[MaxVertexNum];
    int vexnum,arcnum;
}ALGraph;