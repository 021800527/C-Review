/*
 * 串的链式存储
 */
typedef struct StringNode{
    /*
     * 每个结点存1个字符
     */
    char ch;
    struct StringNode *next;
}StringNode,*String;
