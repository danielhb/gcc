/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-phiopt1" } */

#define F(OP,NAME) \
 int NAME##_test (int y, _Bool x) { \
   return y OP (4 << (x * 3)); \
}

#define F2(OP,NAME) \
 int NAME##_test2 (int y, _Bool x) { \
   return y OP ((4 << (x * 3)) + 1); \
}

#define F3(OP,NAME) \
 int NAME##_test3 (int y, _Bool x) { \
   return y OP (32 >> (x * 3)); \
}

#define F4(OP,NAME) \
 int NAME##_test4 (int y, _Bool x) { \
   return y OP ((32 >> (x * 3)) + 1); \
}

#define F5(OP,NAME) \
 int NAME##_test5 (int y, _Bool x) { \
   return y OP ((x << 2) + 3); \
}

#define F6(OP,NAME) \
 int NAME##_test6 (int y, _Bool x) { \
   return y OP (7 - (x << 2)); \
}

/* Same patterns from above but switching operands */
#define F_alt(OP,NAME) \
 int NAME##_test_alt (int y, _Bool x) { \
   return (4 << (x * 3)) OP y; \
}

#define F_alt2(OP,NAME) \
 int NAME##_test_alt2 (int y, _Bool x) { \
   return ((4 << (x * 3)) + 1) OP y; \
}

#define F_alt3(OP,NAME) \
 int NAME##_test_alt3 (int y, _Bool x) { \
   return (32 >> (x * 3)) OP y; \
}

#define F_alt4(OP,NAME) \
 int NAME##_test_alt4 (int y, _Bool x) { \
   return ((32 >> (x * 3)) + 1) OP y; \
}

#define F_alt5(OP,NAME) \
 int NAME##_test_alt5 (int y, _Bool x) { \
   return ((x << 2) + 3) OP y; \
}

#define F_alt6(OP,NAME) \
 int NAME##_test_alt6 (int y, _Bool x) { \
   return (7 - (x << 2)) OP y; \
}

#define T(OP,NAME) \
  F (OP, NAME) \
  F2 (OP, NAME) \
  F3 (OP, NAME) \
  F4 (OP, NAME) \
  F5 (OP, NAME) \
  F6 (OP, NAME) \
  F_alt (OP, NAME) \
  F_alt2 (OP, NAME) \
  F_alt3 (OP, NAME) \
  F_alt4 (OP, NAME) \
  F_alt5 (OP, NAME) \
  F_alt6 (OP, NAME)

T (+, plus)
T (-, minus)
T (*, mult)
T (|, bit_and)
T (|, bit_ior)
T (^, bit_xor)
T (/, div)
T (%, mod)
T (<<, lshift)
T (>>, rshift)

/* { dg-final { scan-tree-dump-times "PHI <32" 20 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times "PHI <33" 20 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times "PHI <4" 20 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times "PHI <5" 20 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times "PHI <7" 20 "phiopt1" } } */
/* { dg-final { scan-tree-dump-times "PHI <3\\(" 20 "phiopt1" } } */
