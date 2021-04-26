#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define StrLen 101
void strswap(char *a, char *b)
{
    char swapstr[1024];
    strcpy(swapstr, a);
    strcpy(a, b);
    strcpy(b, swapstr);
}
//int qsort
int int_partition(int number[], int left, int right)
{
    int i = left - 1;
    int j;
    int tmp;
    for (j = left; j < right; j++)
    {
        if (number[j] <= number[right])
        {
            i++;
            tmp = number[i];
            number[i] = number[j];
            number[j] = tmp;
        }
    }
    tmp = number[i + 1];
    number[i + 1] = number[right];
    number[right] = tmp;
    return i + 1;
}
void int_qsort(int number[], int left, int right)
{
    if (left < right)
    {
        //找到pivot在數列中的索引值
        int q = int_partition(number, left, right);
        //分別對比pivot大跟小的數列做排序(會一直遞迴)
        int_qsort(number, left, q - 1);
        int_qsort(number, q + 1, right);
    }
}
//str qsort
int str_partition(char str[][StrLen], int left, int right)
{
    int i = left - 1;
    int j;
    for (j = left; j < right; j++)
    {
        if (strcmp(str[j], str[right]) <= 0)
        {
            i++;
            // tmp = str[i];
            // str[i] = str[j];
            // str[j] = tmp;
            strswap(str[i], str[j]);
        }
    }
    // tmp = str[i + 1];
    // str[i + 1] = str[right];
    // str[right] = tmp;
    strswap(str[i + 1], str[right]);
    return i + 1;
}
void str_qsort(char str[][StrLen], int left, int right)
{
    if (left < right)
    {
        int q = str_partition(str, left, right);
        str_qsort(str, left, q - 1);
        str_qsort(str, q + 1, right);
    }
}

//int mergesort

int larr[1000000];
int rarr[1000000];
void int_merge(int num[], int lowwer, int mid, int upper)
{
    int lenl = mid - lowwer + 1;
    int lenr = upper - mid;

    for (int i = 0; i < lenl; i++)
    {
        larr[i] = num[lowwer + i];
    }
    for (int i = 0; i < lenr; i++)
    {
        rarr[i] = num[mid + 1 + i];
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = lowwer;
    while (i < lenl && j < lenr)
    {
        if (larr[i] < rarr[j])
        {
            num[k] = larr[i];
            i++;
        }
        else
        {
            num[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < lenl)
    {
        num[k] = larr[i];
        k++;
        i++;
    }
    while (j < lenr)
    {
        num[k] = rarr[j];
        k++;
        j++;
    }
}
void int_mergesort(int num[], int lowwer, int upper)
{
    if (lowwer < upper)
    {
        int mid = (lowwer + upper) / 2;
        int_mergesort(num, lowwer, mid);
        int_mergesort(num, mid + 1, upper);
        int_merge(num, lowwer, mid, upper);
    }
}

//str mergesort
char str_larr[1000000][StrLen];
char str_rarr[1000000][StrLen];
void str_merge(char str[][StrLen], int lowwer, int mid, int upper)
{
    int lenl = mid - lowwer + 1;
    int lenr = upper - mid;

    for (int i = 0; i < lenl; i++)
    {
        //larr[i] = num[lowwer + i];
        strcpy(str_larr[i], str[lowwer + i]);
    }
    for (int i = 0; i < lenr; i++)
    {
        //rarr[i] = num[mid + 1 + i];
        strcpy(str_rarr[i], str[mid + 1 + i]);
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = lowwer;
    while (i < lenl && j < lenr)
    {
        if (strcmp(str_larr[i], str_rarr[j]) < 0)
        {
            //num[k] = larr[i];
            strcpy(str[k], str_larr[i]);
            i++;
        }
        else
        {
            //num[k] = rarr[j];
            strcpy(str[k], str_rarr[j]);
            j++;
        }
        k++;
    }
    while (i < lenl)
    {
        //num[k] = larr[i];
        strcpy(str[k], str_larr[i]);
        k++;
        i++;
    }
    while (j < lenr)
    {
        //num[k] = rarr[j];
        strcpy(str[k], str_rarr[j]);
        k++;
        j++;
    }
}
void str_mergesort(char str[][StrLen], int lowwer, int upper)
{

    if (lowwer < upper)
    {
        int mid = (lowwer + upper) / 2;
        str_mergesort(str, lowwer, mid);
        str_mergesort(str, mid + 1, upper);
        str_merge(str, lowwer, mid, upper);
    }
}
