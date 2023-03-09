typedef struct cdlnode CDLNode;
typedef struct cdllist CDLList;
CDLList *cdllCreate();
int cdllDestroy(CDLList *l);
int cdllInsertAfterSpec(CDLList *l, void *key, void *data, int (*cmp)(void *, void *));
void *cdllRemoveSpec(CDLList *l, void *data,int (*cmp)(void *, void *));
void *cdllQuery(CDLList *l, void *key, int (*cmp)(void *, void *));
void *cdllGetFirst(CDLList *l);
void *cdllGetNext(CDLList *l);
