char* head = NULL;
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

int test(char* s, int count, int step, int* max)
{
    char* tail = s+count;
    if (count-step-1<0 || count+step+1>2000 || NULL==*(tail+step+1)) 
    {
        return 0;
    } 
    if (*(tail-step-1) == *(tail+step+1)) 
    {
        step++;
        if (*max<step) 
        {
            *max = step;
            head = tail-step;
        } 
        test(s, count, step, max);
    }
    return 1;
}

char* longestPalindrome(char* s)
{
    char des[2000];
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
        if (0 == test(des, i, step, &max))
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
