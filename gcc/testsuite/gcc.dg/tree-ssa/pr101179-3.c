/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-phiopt1" } */

int test (int y, _Bool x) {
  return y % (x ? 16 : 4) == 0;
}

/* { dg-final { scan-tree-dump-times " PHI <15" 1 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times " PHI <16" 0 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times " & " 1 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times " % " 0 "phiopt1" } } */
