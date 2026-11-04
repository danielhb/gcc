/* { dg-do compile } */
/* { dg-options "-O2 -fno-tree-dominator-opts -fdump-tree-phiopt2-details -fdump-tree-phiopt3-details" } */

/* The value computed in the conditional block is 0 when the condition
   fails to hold, so the block can be executed unconditionally.  */

int f (int x)
{
  return x ? (x & 85) != 0 : 0;
}

int g (int x)
{
  return x == 0 ? 0 : (x * 3) & 6;
}

/* Must not be transformed: the value differs, or speculation is unsafe.  */
int h1 (int x) { return x ? (x & 85) != 0 : 1; }
int h2 (int x, int *p) { return x ? *p : 0; }
int h3 (int x, int y) { return x ? y / x : 0; }

/* { dg-final { scan-tree-dump-times "assumption replacement" 1 "phiopt2" } } */
/* { dg-final { scan-tree-dump-times "assumption replacement" 1 "phiopt3" } } */
