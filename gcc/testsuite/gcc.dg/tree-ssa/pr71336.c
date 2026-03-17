/* { dg-additional-options -O1 } */
/* { dg-additional-options -fdump-tree-gimple } */

int test (int a) {
  return a & 1 ? 7 : 3;
}

int test2 (int a) {
  return (a & 1) == 0 ? 3 : 7;
}

int test3 (int a) {
  return a & 1 ? 3 : 7;
}

int test4 (int a) {
  return (a & 1) == 0 ? 7 : 3;
}

int test5 (int a) {
  return a & 1 ? 17 : 3;
}

int test6 (int a) {
  return (a & 1) == 0 ? 3 : 17;
}
/* { dg-final { scan-tree-dump-times " << 2;" 4 gimple } } */
/* { dg-final { scan-tree-dump-times " 7 - " 2 gimple } } */
/* { dg-final { scan-tree-dump-times " \\+ 3;" 2 gimple } } */
/* { dg-final { scan-tree-dump-times " = 3;" 2 gimple } } */
/* { dg-final { scan-tree-dump-times " = 17;" 2 gimple } } */
/* { dg-final { scan-tree-dump-times " goto " 6 gimple } } */
