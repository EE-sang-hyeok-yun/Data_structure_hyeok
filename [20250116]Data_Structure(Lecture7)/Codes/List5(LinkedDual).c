typedef int element;

typedef struct listNode
{
    element data;
    struct listNode *front;
    struct listNode *rear;
} listNode;
typedef struct
{
    listNode *head;
    int length;
} listType;

void dInsertNode(listNode *before, listNode *newNode)
{
    newNode->front = before->front;
    newNode->rear = before;
    before->front->rear = newNode;
    before->front = newNode;
}
void dremoveNode(listNode *preHeadNode, listNode *removedNode)
{
    if (preHeadNode == removedNode)
        return;
    removedNode->rear->front = removedNode->front;
    removedNode->front->rear = removedNode->rear;
    free(removedNode);
    return;
}