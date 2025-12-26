/* { dg-do compile } */
/* { dg-options "-fdump-tree-optimized" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-fno-fat-lto-objects" } { "" } } */

int f (unsigned y)
{
  return __builtin_popcount (y & -y);
}

int f2 (int y)
{
  return __builtin_popcount (y & -y);
}

/* { dg-final { scan-tree-dump-times "popcount" 0 "optimized" } } */
