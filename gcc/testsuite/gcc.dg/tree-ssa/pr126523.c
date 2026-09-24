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

int g(si a)
{
    return f(a) + f1(a) == (si)(2*(~a));
}

ui f3(ui a)
{
    si t = a;
    t = ~t;
    ui a1 = t;
    return a1;
}

ui f4(ui a)
{
    return ~a;
}

ui g2(ui a)
{
    return f3(a) == f4(a);
}

/* { dg-final { scan-tree-dump-times " return 1;" 2 "optimized" } } */
