/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-optimized" } */

int f1 (int y, _Bool x)
{
    return y % (4 << x) == 0;
}
/* { dg-final { scan-tree-dump-times " ? 7 : 3;" 1 "optimized" } } */

int f2 (int y, _Bool x)
{
    return y % (4 >> x) == 0;
}
/* { dg-final { scan-tree-dump-times " ? 1 : 3;" 1 "optimized" } } */

int f3 (int y, _Bool x)
{
    return y % (8 << (x * 2)) == 0;
}
/* { dg-final { scan-tree-dump-times " ? 31 : 7;" 1 "optimized" } } */

int f4 (int y, _Bool x)
{
    return y % (8 >> (x * 2)) == 0;
}
/* { dg-final { scan-tree-dump-times " ? 1 : 7;" 1 "optimized" } } */

int f5 (int y, int n)
{
  if (n != 2 && n != 8) __builtin_unreachable () ;
  return y % n == 0;
}

/* Negative test: shouldn't be simplified.  */
int f6 (int y, int n)
{
  if (n < 1 || n > 4) return 0;
  return y % n == 0;
}

/* { dg-final { scan-tree-dump-times " \& " 5 "optimized" } } */
/* { dg-final { scan-tree-dump-times " \% " 1 "optimized" } } */
