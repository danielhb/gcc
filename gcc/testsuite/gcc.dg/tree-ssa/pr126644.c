/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-optimized" } */

int f1 (int a)
{
  if ((a & 0xE0000000) != 0)  __builtin_unreachable ();

  return a << 3 >> 3;
}

/* Can't be optimized.  */
int f2 (int a, int b)
{
  return a << 3 >> 3;
}

/* { dg-final { scan-tree-dump-times " << " 1 "optimized" } } */
/* { dg-final { scan-tree-dump-times " >> " 1 "optimized" } } */
