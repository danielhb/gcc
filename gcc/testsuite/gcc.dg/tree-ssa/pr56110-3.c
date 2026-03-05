/* { dg-additional-options -O2 } */
/* { dg-additional-options -fdump-tree-phiopt3 } */

#define EQ_ZERO(opname, OP)		\
__attribute__((noinline,noclone))	\
int eqzero_##opname(int m) {		\
  if (m == 0)				\
    m = m OP 2;				\
  return m;				\
}

#define NE_ZERO(opname, OP)		\
__attribute__((noinline,noclone))	\
int nezero_##opname(int m) {		\
  if (m != 0)				\
    return m;				\
  else					\
    m = m OP 2;    			\
  return m;				\
}

EQ_ZERO(lshift, <<)
EQ_ZERO(rshift, >>)
EQ_ZERO(bit_and, &)
EQ_ZERO(mult, *)

NE_ZERO(lshift, <<)
NE_ZERO(rshift, >>)
NE_ZERO(bit_and, &)
NE_ZERO(mult, *)

/* { dg-final { scan-tree-dump-times "PHI" 0 phiopt3 } } */
/* { dg-final { scan-tree-dump-times " == " 0 phiopt3 } } */
/* { dg-final { scan-tree-dump-times " != " 0 phiopt3 } } */
