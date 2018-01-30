char rec[512] = {0};
int num = 0;
typedef struct rec
{
    int head;
    int tail;
    int len;
    char rec[512];
} REC;
void updateLen(REC *r)
{
    if (r->len < r->tail - r->head)
    {
        r->len = r->tail - r->head;
    }
}
int getChar(REC *r, char *c)
{
    int i = r->head;
    while (i < r->tail)
    {
        if (*c == r->rec[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}
void addChar(REC *r, char *c)
{
    r->rec[r->tail] = *c;
    r->tail++;
    if (r->tail > 512)
    {
        r->tail = 0;
    }
}
void delChar(REC *r, char *c)
{
    updateLen(r);
    while (r->head != r->tail)
    {
        if ( *c == r->rec[r->head])
        {
            r->head++;
            break;
        }
        r->head++;
        if (r->head > 512)
        {
            r->head = 0;
        }
    }
}
int lengthOfLongestSubstring(char* s) {
    REC *rec = (REC *)malloc(sizeof(REC));
    memset(rec, 0, sizeof(REC));

    while (NULL != *s)
    {
        if (1 == getChar(rec, s))
        {
            addChar(rec, s);
        }
        else
        {
            delChar(rec, s);
            addChar(rec, s);
        }
        s++;
    }
    updateLen(rec);
    return rec->len;
}
