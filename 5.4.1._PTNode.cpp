#include <iostream>
using namespace std;
#define MAX_TREE_SIZE 100
/*
 * 双亲表示法
 */
typedef struct {
    int data;
    int parent;
}PTNode;
typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int n ;
}PTree;
/*
 * 孩子表示法
 */
typedef struct CNode{
    int child;
    struct CNode *next;
}CNode;

typedef struct {
    int data;
    struct CNode *child;
}PNode;

typedef struct {
    PNode nodes[MAX_TREE_SIZE];
    int n;
}CTree;

/*
 * 孩子兄弟表示法
 */
typedef struct CSNode{
    int data;
    struct CSNode *firstchild , *nextsibling;
}CSNode,CSTree;