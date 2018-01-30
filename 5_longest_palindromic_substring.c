char* rec=NULL;
int isPalindromic(char *s, int len, int step, int* mode, int* max)
{
    char* tail = (s+len);
    int ret = 0;

    printf("tail=%c len=%d step=%d mode=%d max=%d ret=%d rec=%c\n", *tail, len, step, *mode, *max, ret, *rec);
    if (1 == *mode) 
    {
        if (*tail == *(tail-2*step-2)) 
        {
            rec = tail-2*step-2;
            *max = (*max>step*2+1)? *max:step*2+1;
        } 
        else 
        {
            *mode = 0;
            ret = 1;
        }
    } 
    else if (2 == *mode)
    {
        if (*tail == *(tail-2*step-1)) 
        {
            rec = tail-2*step-1;
            *max = (*max>step*2)? *max:step*2;
        } 
        else 
        {
            *mode = 0;
            ret = 1;
        }
    }
    else //0==mode
    {
        if (1 == len )
        {
            if (*tail == *(tail-1))
            {
                *max = 2;
                rec = tail-1;
            } 
            else 
            {
                ret = 1;
            }
        }
        else 
        {
            if (*tail == *(tail-1)) //abb
            {
                *mode = 2;
                rec = tail-1;
                *max = (*max>2)? *max:2;
            } 
            else if (*tail == *(tail-2)) //aba
            {
                *mode = 1;
                rec = tail-2;
                *max = (*max>2+1)? *max:2+1;
            } 
            else 
            {
                ret = 1;
            }

        }
    }
    printf("tail=%c len=%d step=%d mode=%d max=%d ret=%d rec=%c\n", *tail, len, step, *mode, *max, ret, *rec);
    return ret;
}

char* longestPalindrome(char* s) 
{
    int i = 0;
    char* ret = NULL;
    int step = 0;
    int max = 0;
    int mode = 0; //0:all 1:1apa  2:appa
    int judge = 0;

    rec = s;

    for (i = 1; i < 1000; i++) 
    {
        if (NULL == *(s+i))
        {
            if (1 == i)
            {
                max = 1;
                rec = s;
            }
            break;
        }

        if (0 == isPalindromic(s, i, step, &mode, &max))
        {
            step++;
        } 
        else 
        {
            continue;
        }
    }


    ret = malloc(max+1);
    memset(ret, 0, max+1);
    memcpy(ret, rec, max);
    return ret;
}


