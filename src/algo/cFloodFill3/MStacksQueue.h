#ifndef MSTACKSQUEUE_H_
#define MSTACKSQUEUE_H_

#include <stdbool.h>

#include "CellStack.h"

struct MStacksQueueNode {
    struct MStacksQueueNode *ahead;
    struct MStacksQueueNode *behind;
    struct CellStack *data;
};

struct MStacksQueue {
    struct MStacksQueueNode *front;
    struct MStacksQueueNode *back;
};

bool isEmpty(struct MStacksQueue);
void pop(struct MStacksQueue);
void push(struct MStacksQueue, struct CellStack *);
struct CellStack * front(struct MStacksQueue);

#endif // MSTACKSQUEUE_H_
