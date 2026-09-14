/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-phiopt1" } */

int f1 (int y, _Bool x)
{
    return y % (4 << x) == 0;
}
/* { dg-final { scan-tree-dump-times " ? 7 : 3;" 1 "phiopt1" } } */

int f2 (int y, _Bool x)
{
    return y % (4 >> x) == 0;
}
/* { dg-final { scan-tree-dump-times " ? 1 : 3;" 1 "phiopt1" } } */

int f3 (int y, _Bool x)
{
    return y % (8 << (x * 2)) == 0;
}
/* { dg-final { scan-tree-dump-times " ? 31 : 7;" 1 "phiopt1" } } */

int f4 (int y, _Bool x)
{
    return y % (8 >> (x * 2)) == 0;
}
/* { dg-final { scan-tree-dump-times " ? 1 : 7;" 1 "phiopt1" } } */

/* Note: ranger needs at least -O2 to figure out that
   "(4 >> (x + 1))" is a pow2.  */
int f5 (int y, _Bool x)
{
    return y % (4 >> (x + 1)) == 0;
}
/* { dg-final { scan-tree-dump-times " -1;" 1 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times " >> " 1 "phiopt1" } } */

/* { dg-final { scan-tree-dump-times " \& " 5 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times " \% " 0 "phiopt1" } } */
