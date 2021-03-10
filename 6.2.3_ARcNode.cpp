#include <iostream>
using namespace std;
#define MaxVertexNum 100
typedef struct ArcNode{
    int tailvex,headvex;
    struct ArcNode *hlink,*tlink;
}ArcNode;
typedef struct VNode{
    int data;
    ArcNode *firstin,*firstout;
}VNode,AdjList[MaxVertexNum];
typedef struct ALGraph{
    AdjList vetices;
    int vexnum,arcnum;
}ALGraph;