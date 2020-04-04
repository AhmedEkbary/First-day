#include <stdio.h>
#include "DlinkedList.h"

struct client* createClient(int data)
{

    struct client* pClient = (struct client*) malloc(sizeof(struct client));

    if(pClient != NULL)
    {

        pClient->data = data;

        ClientNo++;

    }

    return pClient;
}


int addClient(int data)
{

    struct client* pClient = createClient(data);

    if(pClient)
    {
        // First Element Case.
        if(pHead == NULL)
        {

            pHead = pTail = pClient;

        }
        // Last Element Case. == Not First Element Case.
        else
        {

            //pTail->pNext = pClient
            pClient->pPrev = pTail;
            pTail = pClient;
            pClient->pPrev->pNext = pTail;

        }
        return 1;
    }
    return 0;
}


int insertClient(int data, int index)
{
    if(index == ClientNo)
    {
        return(addClient(data));
    }
    else if(index == 0)
    {
        struct client* pClient = createClient(data);
        if(pClient)
        {
            pHead->pPrev =  pClient;
            pClient->pNext = pHead;
            pHead = pClient;
            return 1;
        }
        else
        {
            return 0;
        }

    }

    else
    {
        struct client* pClient = createClient(data);
        if(pClient)
        {
            struct client* pCur = pHead;
            for(int i =0 ; i <index; i++)
            {

                pCur = pCur->pNext;

            }

            pCur->pPrev->pNext = pClient;
            pClient->pPrev = pCur->pPrev;
            pClient->pNext = pCur;
            pCur->pPrev = pClient;
            return 1;

        }

        return 0;
    }


}
int removeClient(int index)
{
    if(index == (ClientNo-1))
    {   struct client* pCur = pTail;
            pTail = pTail -> pPrev;
        pTail -> pNext = NULL;
        free(pCur);
    }
    else if(index == 0)
    {   struct client* pCur = pHead;
            pHead=pHead -> pNext;
            pHead ->pPrev=NULL;
       free(pCur);
    }
    else
    {   struct client* pCur = pHead;
            for(int i=0 ;i<index ;i++){
                pCur=pCur -> pNext;
            }
            pCur -> pPrev -> pNext= pCur -> pNext;
            pCur -> pNext -> pPrev=pCur -> pPrev;
            free(pCur);
    }
ClientNo--;
return 1;
}
