void prepareString(char* s, char* des)
{
    int i = 0;
    while (i<2000 && NULL!=*(s+i))
    {
        *(des+2*i) = '#';
        *(des+2*i+1) = *(s+i);
        i++;
    }
    *(des+2*i) = '#';
}

int test(char* s, char* head, int count, int step, int* max)
{
    char* tail = s+count;
    printf("head=%c, *tail=%c, count=%d, step=%d max=%d\n", *head, *tail, count, step, *max);
    if (count-step-1<0 || count+step+1>2000-1 || NULL==*(tail+step+1)) 
    {
        return 0;
    } 
    printf("%c-%c\n", *(tail-step-1), *(tail+step+1));
    if (*(tail-step-1) == *(tail+step+1)) 
    {
        step++;
        if (*max<step) 
        {
            *max = step;
            head = tail-step-1;
        } 
        test(s, head, count, step, max);
    }
    return 1;
}

char* longestPalindrome(char* s)
{
    char des[2000];
    char* head = NULL;
    char* rec = NULL;
    int i = 0;
    int j = 0;
    int step = 0;
    int max = 1;
    memset(&des, 0, 2000);
    prepareString(s, des);
    head = &des[0];
    
    for (i = 1; i < 2000; i++) 
    {
        if (0 == test(des, head, i, step, &max))
        {
            break;
        }
        else
        {
            step = 0;
            continue;
        }
    }
    rec = malloc(sizeof(int)*max+1);
    memset(rec, 0, sizeof(int)*max+1);
    memcpy(rec, head, max);
    printf("%s\n", rec);

    memset(rec, 0, sizeof(int)*max+1);
    while (j<max) 
    {
        if('#' != *head)
        {
            *(rec+j) = *(head++);
            j++;
        }
        else 
        {
            head++;
        }
    }
    return rec;
}
