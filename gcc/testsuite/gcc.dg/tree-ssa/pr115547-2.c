/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-optimized" } */

_Bool fn1 (_Bool a, _Bool b, _Bool c) {
    return a != c && (b || (c || a));
}

_Bool fn2 (_Bool a, _Bool b, _Bool c) {
    return a != c && (b || c || a);
}

_Bool fn3 (_Bool a, _Bool b, _Bool c) {
    return a != c && (a || b || c);
}

_Bool fn4 (_Bool a, _Bool b, _Bool c) {
    return a != c && (a || c || b);
}

/* { dg-final { scan-tree-dump-times " != " 4 "optimized" } } */
/* { dg-final { scan-tree-dump-times " \\\| " 0 "optimized" } } */
/* { dg-final { scan-tree-dump-times " & " 0 "optimized" } } */
