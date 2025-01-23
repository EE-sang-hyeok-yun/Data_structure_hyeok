void insertFirst(listNode **preHead, listNode *node)
{
    if (*preHead == NULL)
    {
        *preHead = node;
        node->link = node;
    }
    else
    {
        node->link = (*preHead)->link;
        (*preHead)->link = node;
    }
    return;
}
void insertLast(listNode **preHead, listNode *node)
{
    if (*preHead == NULL)
    {
        *preHead = node;
        node->link = node;
    }
    else
    {
        node->link = (*preHead)->link;
        (*preHead)->link = node;
        *preHead = node;
    }
    return;
}