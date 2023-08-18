#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int front;
    int rear;
    int size;
    int entry[10];
}Queue;

void CreateQueue(Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}

void Append(Queue *pq, int e)
{
    pq->rear=(pq->rear+1)%10;
    pq->entry[pq->rear]=e;
    pq->size++;
}

void Serve(Queue *pq, int *pe)
{
    *pe=pq->entry[pq->front];
    pq->front=(pq->front+1)%10;
    pq->size--;
}

int QueueFull(Queue *pq)
{
    return (pq->size==10);
}

int QueueEmpty(Queue *pq)
{
    return(pq->size==0);
}

int QueueSize(Queue *pq)
{
    return pq->size;
}

void ClearQueue(Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}

void TraverseQueue(Queue *pq, void (*pf)(int))
{
    int pos,s;
    for(pos=pq->front,s=0;s<pq->size;s++)
    {
    (*pf)(pq->entry[pos]);
    pos=(pos+1)%10;
    }
}

int main()
{
    Queue q;
    CreateQueue(&q);
if (!QueueFull(&q))
{
    Append(&q,1);
    Append(&q,5);
    Append(&q,60);
}
else
    printf("Queue is Full");

if (!QueueEmpty(&q))
{
    int x, y, z;
    Serve(&q,&x);
    Serve(&q,&y);
    Serve(&q,&z);
    printf("%d\n",x);
    printf("%d\n",y);
    printf("%d\n",z);
}
else
    printf("Queue is Empty");
    return 0;
}
