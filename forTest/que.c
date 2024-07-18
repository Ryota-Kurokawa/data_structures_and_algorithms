#include<stdio.h>
#include<stdlib.h>

// キューの実装
typedef struct
{
  int data[1000];
  int head;
  int tail;
} Queue;

Queue *createQueue()
{
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->head = 0;
  q->tail = 0;
  return q;
}

void enqueue(Queue *q, int x)
{
  q->data[q->tail] = x;
  q->tail++;
}

int dequeue(Queue *q)
{
  int x = q->data[q->head];
  q->head++;
  return x;
}

int isEmpty(Queue *q)
{
  return q->head == q->tail;
}

int main()
{
  Queue *q = createQueue();
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  printf("%d\n", dequeue(q));
  printf("%d\n", dequeue(q));
  printf("%d\n", dequeue(q));
  return 0;
}