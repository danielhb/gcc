/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-optimized" } */

typedef int si;
typedef unsigned ui;

si f(si a)
{
    ui t = a;
    t = ~t;
    si a1 = t;
    return a1;
}

si f1(si a)
{
    return ~a;
}

/* If everything went as planned g()
   will reduce to 'return 1'.  */
int g(si a)
{
    return f(a) + f1(a) == (si)(2*(~a));
}
/* { dg-final { scan-tree-dump-times " return 1;" 1 "optimized" } } */
