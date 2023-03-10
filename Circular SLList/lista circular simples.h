typedef struct cslnode CSLNode;
typedef struct csllist CSLList;
CSLList *csllCreate();
int csllDestroy(CSLList *l);
int csllInsertAfterSpec(CSLList *l, void *key, void *data, int (*cmp)(void *, void *));
int csllInsertAsFirst(CSLList *l, void *data);
int csllInsertAsLast(CSLList *l, void *data);
void *csllRemoveSpec(CSLList *l, void *data,int (*cmp)(void *, void *));
void *csllQuery(CSLList *l, void *key, int (*cmp)(void *, void *));
void *csllGetFirst(CSLList *l);
void *csllGetNext(CSLList *l);
