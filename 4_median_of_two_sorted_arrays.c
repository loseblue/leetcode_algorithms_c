double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int idx1 = 0;
    int idx2 = 0;
    int idx3 = 0;
    int i = 0;
    int tmp1,tmp2 = 0;
    double result = 0.0;

    int* rec = NULL;
    rec = (int*)malloc(sizeof(int) * (nums1Size+nums2Size));
    memset(rec, 0, sizeof(int) * (nums1Size+nums2Size));

    while (idx1<nums1Size || idx2<nums2Size)
    {
        tmp1 = (idx1<nums1Size) ? *(nums1+idx1):-1;
        tmp2 = (idx2<nums2Size) ? *(nums2+idx2):-1;

        if (-1 == tmp1)
        {
            rec[idx3] = tmp2;
            idx2++;
            idx3++;
            continue;
        }
        if (-1 == tmp2)
        {
            rec[idx3] = tmp1;
            idx1++;
            idx3++;
            continue;
        }

        if (tmp1 < tmp2)
        {
            rec[idx3] = tmp1;
            idx1++;
        }
        else
        {
            rec[idx3] = tmp2;
            idx2++;
        }
        idx3++;
    }

    if (0 == (nums1Size+nums2Size)%2)
    {
        result = (double)(*(rec+((nums1Size+nums2Size)/2)) + *(rec+((nums1Size+nums2Size)/2-1)))/2;
    }
    else
    {
        result = *(rec+((nums1Size+nums2Size)/2));
    }
    return result;
}
