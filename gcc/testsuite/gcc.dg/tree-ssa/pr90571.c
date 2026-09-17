/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-optimized" } */

int f() { return 0; }
int g() { return 1; }

int t0(_Bool b)
{
  return (b ? &f : &g)();
}

/* { dg-final { scan-tree-dump-times " = PHI " 0 "optimized" } } */
