/* { dg-additional-options -O1 } */
/* { dg-additional-options -fdump-tree-optimized } */

int test (int a) {
    return a & 1 ? 7 : 3;
}

int test2 (int a) {
    return (a & 1) == 0 ? 3 : 7;
}

/* Will not be simplified.  */
int test3 (int a) {
    return a & 1 ? 17 : 3;
}

/* Will not be simplified.  */
int test4 (int a) {
    return (a & 1) == 0 ? 3 : 17;
}

/* { dg-final { scan-tree-dump-times " << " 2 optimized } } */
/* { dg-final { scan-tree-dump-times " goto " 4 optimized } } */
 