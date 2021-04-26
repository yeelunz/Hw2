#include "creat.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#define Size 1000000
#define StrLen 101

char tmpstr[128];
int arr[Size];
char str[Size][StrLen];
int idx = 0;
int main()
{
    //qsort
    FILE *intData;
    FILE *strData;
    struct timeval start;
    struct timeval end;
    unsigned long diff;
    strData = fopen("dataset2.txt", "w");
    intData = fopen("dataset1.txt", "w");
    int_creat100wData(intData);
    str_creat100wData(strData);
    fclose(intData);
    fclose(strData);
    strData = fopen("dataset2.txt", "r");
    intData = fopen("dataset1.txt", "r");
    while (fgets(tmpstr, 128, intData))
    {
        arr[idx] = atoi(tmpstr);
        idx++;
    }
    idx = 0;
    while (fgets(tmpstr, 128, strData))
    {
        strcpy(str[idx], tmpstr);
        idx++;
    }
    gettimeofday(&start, NULL);
    int_qsort(arr, 0, Size-1);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec; // 實際的時間差
    printf("qsort int:%ld us (equal %f sec)\n", diff, diff / 1000000.0);

    gettimeofday(&start, NULL);
    str_qsort(str, 0, Size-1);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec; // 實際的時間差
    printf("qsort str:%ld us (equal %f sec)\n", diff, diff / 1000000.0);
    fclose(intData);
    fclose(strData);

    //mergesort
    idx = 0;
    strData = fopen("dataset2.txt", "r");
    intData = fopen("dataset1.txt", "r");
    while (fgets(tmpstr, 128, intData))
    {
        arr[idx] = atoi(tmpstr);
        idx++;
    }
    idx = 0;
    while (fgets(tmpstr, 128, strData))
    {
        strcpy(str[idx], tmpstr);
        idx++;
    }
    gettimeofday(&start, NULL);
    int_mergesort(arr, 0, Size-1);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec; // 實際的時間差
    printf("mergesort int:%ld us (equal %f sec)\n", diff, diff / 1000000.0);

    gettimeofday(&start, NULL);
    str_mergesort(str, 0, Size-1);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec; // 實際的時間差
    printf("mergesort str:%ld us (equal %f sec)\n", diff, diff / 1000000.0);
    fclose(intData);
    fclose(strData);
}

// for (int i = 0; i < 10; i++)
// {
//     printf("%d\n", arr[i]);
// }
// for (int i = 0; i < 10; i++)
// {
//     printf("%s\n", str[i]);
// }