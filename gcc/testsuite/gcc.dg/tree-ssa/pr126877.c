/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-optimized" } */

signed f (signed a, signed b)
{
    if (a == b)
    {
      signed c = a + b;
      return c&1;
    }
    return 1;
}

unsigned f1 (unsigned a, unsigned b)
{
    if (a == b)
    {
      unsigned c = a + b;
      return c&1;
    }
    return 1;
}

/* { dg-final { scan-tree-dump-times " != " 2 "optimized" } } */
/* { dg-final { scan-tree-dump-times " & " 0 "optimized" } } */
/* { dg-final { scan-tree-dump-times " \\+ " 0 "optimized" } } */
