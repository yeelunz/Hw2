#include"creat.h"
#include<stdio.h>
#include<stdlib.h>
#define Datasize 1000000

int getRandChar()
{
    int ch;
    ch = rand() % 2;
    if (ch)
    {
        ch = rand() % 26;
        ch += 'A';
        return ch;
    }
    else
    {
        ch = rand() % 26;
        ch += 'a';
        return ch;
    }
}

void int_creat100wData(FILE*dataset)
{
    srand(10);
    for (int i = 0;i<Datasize;i++)
    {
        fprintf(dataset,"%d\n",rand());
    }
}

void str_creat100wData(FILE*dataset)
{
    srand(10);
    for (int i = 0;i<Datasize;i++)
    {
        for (int j = 0;j<99;j++)
        {
            fprintf(dataset,"%c",getRandChar());
        }
        fprintf(dataset,"\n");
    }
}