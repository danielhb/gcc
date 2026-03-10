/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-phiopt1" } */

/* Tests for the pattern
   if cond X (cmp (OP A B) C) (cmp (OP A D) C) ->
   (cmp (op A (cond X B D) C))).  */

#define F(OP,NAME) \
 int NAME##_test (int y, _Bool x) { \
   return x ? (y OP 16) == 0 : (y OP 4) == 0; \
}

F (%, mod)
F (<<, lshift)
F (>>, rshift)

int bit_and_test (int y, _Bool x) {
   return x ? (y & 63) != 1 : (y & 16) != 1;
}

int bit_ior_test (int y, _Bool x) {
   return x ? (y | 3) < 0xF : (y | 8) < 0XF;
}

int bit_xor_test (int y, _Bool x) {
  return x ? (y ^ 3) <= 13 : (y ^ 8) <= 13;
}

int mult_test (int y, _Bool x) {
   return x ? (y * 3) > 0xF : (y * 2) > 0XF;
}
/* { dg-final { scan-tree-dump-times " == 0" 3 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times " != 1" 1 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times " <= 14" 1 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times " <= 13" 1 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times " > 15" 1 "phiopt1" } } */
