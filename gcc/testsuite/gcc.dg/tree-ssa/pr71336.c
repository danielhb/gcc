/* { dg-additional-options -O1 } */
/* { dg-additional-options -fdump-tree-gimple } */

int test (int a) {
    return a & 1 ? 7 : 3;
}

int test2 (int a) {
    return (a & 1) == 0 ? 3 : 7;
}

int test3 (int a) {
    return a & 1 ? 17 : 3;
}

int test4 (int a) {
    return (a & 1) == 0 ? 3 : 17;
}

/* { dg-final { scan-tree-dump-times " goto " 0 gimple } } */
