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
/*
 * 预定义最大串长为255
 */
#define MAxLEN 255
typedef struct {
    char ch[MAxLEN];
    int length;
}SString;
/*
 * 求子串
 */
bool SubString(SString &Sub,SString S ,int pos ,int len){
    /*
     * 子串范围越界
     */
    if (pos+len - 1>S.length)
        return false;
    for (int i = pos; i <pos+len ; ++i) {
        Sub.ch[i - pos +1] = S.ch[i];
    Sub.length = len;
    return true;
    }
}
/*
 * 比较两个串的大小
 */
int StrCompare(SString S,SString T){
    for (int i = 1; i < S.length && i <T.length; ++i) {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    /*
     * 扫描过的所有字符都相同，则长度长的串更大
     */
    return S.length - T.length;
}
/*
 * 定位操作
 */
int Index(SString S ,SString T){
    int i = 1,n = S.length,m = T.length;
    SString sub;
    while (i<=n-m+1){
        SubString(sub,S,i,m);
        if (StrCompare(sub,T)!=0)
            ++i;
        else
            /*
             * 返回子串在主串中的位置
             */
            return i;
    }
    /*
     * S中不存在与T相等的子串
     */
    return 0;
}