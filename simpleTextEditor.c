#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


enum opTypes
{
    ADD = 1,
    DEL,
    PRINT,
    UNDO
};

typedef struct lastOP
{
    int type;
    int len;
    char *deleted;
} lastOP_t;

#define MAX_LIST 100000
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned int q;
    char *s = NULL;

    size_t s_len = 0;
    size_t d_len = 0;
    lastOP_t lastop[MAX_LIST];
    unsigned long int opCnt = 0;
    size_t pPos = 0;
    
    scanf("%d", &q);
    //printf("%d\n",q);
    while(q--)
    {
        
        int op;
        char *line = NULL;
        unsigned long int len;
        size_t i_len;
        
        scanf("%d", &op);
       // printf("Op %d\n", op);
        //printf("slen %ld\n", s_len);
        switch(op)
        {
            case ADD:
                getc(stdin);
                i_len = getline(&line, &len, stdin);
                //printf("line %s len %ld\n", line, i_len);
                if (s == NULL){
                    s = line;
                    s_len = i_len - 1;
                }
                else {
                    char *tmp;
                    tmp = realloc(s, s_len + i_len);
                    memcpy(tmp + s_len, line, i_len - 1);
                    //printf("tmp %s", tmp);
                    s = tmp;
                    s_len += i_len - 1;
                }
                lastop[opCnt].type = ADD;
                lastop[opCnt].len = i_len - 1;
                opCnt++;
                break;
            case DEL:
                getc(stdin);
                scanf("%ld",&d_len);
                lastop[opCnt].type = DEL;
                lastop[opCnt].len = d_len;
                lastop[opCnt].deleted = malloc(d_len);
                memcpy(lastop[opCnt].deleted, s + (s_len - d_len), d_len);
                //printf("Deleted %s\n",lastop[opCnt].deleted);
                opCnt++;
                s_len -= d_len;
                break;
            case PRINT:
                getc(stdin);
                scanf("%ld", &pPos);
                printf("%c\n", s[pPos - 1]);
                break;
            case UNDO:
                opCnt--;
                //printf("opcCnt %ld, type %d len %d\n", opCnt, lastop[opCnt].type,
                //        lastop[opCnt].len);
                if (lastop[opCnt].type == ADD)
                {
                    s_len -= lastop[opCnt].len;
                } else if ( lastop[opCnt].type == DEL)
                {
                    char *tmp;
                    tmp = realloc(s, s_len + lastop[opCnt].len);
                    //printf("dleted %s\n", lastop[opCnt].deleted);
                    memcpy(s + s_len , lastop[opCnt].deleted, lastop[opCnt].len);
                    s = tmp;
                    s_len += lastop[opCnt].len;
                    free(lastop[opCnt].deleted);  
                }
                lastop[opCnt].type = 0;
                
                break;
        }
        //printf("s is %s s len %ld\n", s, s_len);
    }  
    return 0;
}

