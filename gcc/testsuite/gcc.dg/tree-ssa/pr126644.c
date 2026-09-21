/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-optimized" } */

int f1 (int a)
{
  if ((a & 0xF0000000) != 0xF0000000)
    __builtin_unreachable ();

  return a << 3 >> 3;
}

/* Can't be optimized (not enough 1s to preserve sign).  */
int g1 (int a)
{
  if ((a & 0xF0000000) != 0xE0000000)
    __builtin_unreachable ();

  return a << 3 >> 3;
}

int f2 (int a)
{
  if ((a & 0xF0000000) != 0) __builtin_unreachable ();

  return a << 3 >> 3;
}

/* Can't be optimized (not enough 0s to preserve sign).  */
int g2 (int a)
{
  if ((a & 0x10000000) != 0x10000000)
    __builtin_unreachable ();

  return a << 3 >> 3;
}

unsigned int f3 (unsigned int a)
{
  if ((a & 0xE0000000) != 0)  __builtin_unreachable ();

  return a << 3 >> 3;
}

/* Can't be optimized (will lose a bit during lshift).
   This simplifies into a bit_and.  */
unsigned int g3 (unsigned int a)
{
  if ((a & 0xA0000000) != 0)  __builtin_unreachable ();

  return a << 3 >> 3;
}

/* { dg-final { scan-tree-dump-times " << " 2 "optimized" } } */
/* { dg-final { scan-tree-dump-times " >> " 2 "optimized" } } */
/* { dg-final { scan-tree-dump-times " & " 1 "optimized" } } */
