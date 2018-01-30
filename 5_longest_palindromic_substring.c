void prepareString(char* s, char* des)
{
    int i = 0;
    while (i<2000 && NULL!=*(s+i))
    {
        *(des+2*i) = '#';
        *(des+2*i+1) = *(s+i);
        i++;
    }
}
char* longestPalindrome(char* s)
{
    char des[2000];
    memset(&des, 0, 2000);
    prepareString(s, des);
    return des;
}
