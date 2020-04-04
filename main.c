#include <stdio.h>
#include <stdlib.h>
#include "DlinkedList.h"


int i = 0;

int main()
{

    for( i= 0; i < 50; i++)
    {
        addClient(i);
        //printf("Data = %d\n", pTail->data);
    }

    struct client* pCur = pHead;


    if(insertClient(99, 0))
    {
        printf("Success\n");
        pCur = pHead;
    }
    else
    {
        printf("Failed\n");
    }
    removeClient(49);
    removeClient(49);

    pCur=pHead;
    for(i =0 ; i <ClientNo; i++)
    {
        printf("Data = %d\n", pCur->data);
        pCur = pCur->pNext;
    }
    return 0;
}


