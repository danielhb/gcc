/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-phiopt1" } */

typedef unsigned uint;

int f1 (int y, _Bool x)
{
  return y % (x ? 16 : 4) == 0;
}

/* We can't turn this into bit_and because there's no
   guarantee 'y' is a positive val.  */
int f2 (int y, _Bool x)
{
  return y % (x ? 16 : 4);
}

uint f3 (uint y, _Bool x)
{
  return y % (x ? 16 : 4) == 0;
}

uint f4 (uint y, _Bool x)
{
  return y % (x ? 16 : 4);
}

/* { dg-final { scan-tree-dump-times " \& " 3 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times " \% " 1 "phiopt1" } } */
