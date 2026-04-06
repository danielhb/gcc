/* { dg-do compile } */
/* { dg-options "-O2 -mabi=lp64 -march=rv64g_zbb_zicond -mbranch-cost=99" } */
/* { dg-skip-if "" { *-*-* } { "-ftracer" } } */
/* { dg-final { scan-assembler-not "czero.eqz\t" } } */

static long
pcount (long b)
{
  int c = 0;
  while (b)
    {
      b &= b - 1;
      c++;
    }
  return c;
}

long
foo_pcount(long a, long b)
{
  int op_a = pcount(a);
  int op_b = pcount(b);
  int sub = op_a - op_b;

  op_b = b ? op_b : 0;
  op_a = b ? 0 : sub;
  return op_a + op_b;
}

static int
pcountw (int b)
{
  int c = 0;
  while (b)
    {
      b &= b - 1;
      c++;
    }
  return c;
}

int
foo_pcountw(int a, int b)
{
  int op_a = pcountw(a);
  int op_b = pcountw(b);
  int sub = op_a - op_b;

  op_b = b ? op_b : 0;
  op_a = b ? 0 : sub;
  return op_a + op_b;
}

typedef unsigned int uint;
typedef unsigned long ulong;

#define T(RETTYPE, OPTYPE, OP, NAME)\
 RETTYPE NAME##_##RETTYPE##_##OPTYPE (OPTYPE a, OPTYPE b, OPTYPE c)\
 { OPTYPE op_a = a OP c;\
   OPTYPE op_b = b OP c;\
   OPTYPE sub = op_a - op_b;\
   op_b = b ? op_b : 0;\
   op_a = b ? 0 : sub;\
   return op_a + op_b; }

T (int, int, *, mul)
T (long, int, *, mul)
T (int, long, *, mul)
T (long, long, *, mul)

T (uint, int, *, mul)
T (ulong, int, *, mul)
T (uint, long, *, mul)
T (ulong, long, *, mul)

T (int, uint, *, mul)
T (long, uint, *, mul)
T (int, ulong, *, mul)
T (long, ulong, *, mul)

T (uint, uint, *, mul)
T (ulong, uint, *, mul)
T (uint, ulong, *, mul)
T (ulong, ulong, *, mul)

T (int, int, &, and)
T (long, int, &, and)
T (int, long, &, and)
T (long, long, &, and)

T (uint, int, &, and)
T (ulong, int, &, and)
T (uint, long, &, and)
T (ulong, long, &, and)

T (int, uint, &, and)
T (long, uint, &, and)
T (int, ulong, &, and)
T (long, ulong, &, and)

T (uint, uint, &, and)
T (ulong, uint, &, and)
T (uint, ulong, &, and)
T (ulong, ulong, &, and)

T (int, int, <<, lshift)
T (long, int, <<, lshift)
T (int, long, <<, lshift)
T (long, long, <<, lshift)

T (uint, int, <<, lshift)
T (ulong, int, <<, lshift)
T (uint, long, <<, lshift)
T (ulong, long, <<, lshift)

T (int, uint, <<, lshift)
T (long, uint, <<, lshift)
T (int, ulong, <<, lshift)
T (long, ulong, <<, lshift)

T (uint, uint, <<, lshift)
T (ulong, uint, <<, lshift)
T (uint, ulong, <<, lshift)
T (ulong, ulong, <<, lshift)

T (int, int, >>, rshift)
T (long, int, >>, rshift)
T (int, long, >>, rshift)
T (long, long, >>, rshift)

T (uint, int, >>, rshift)
T (ulong, int, >>, rshift)
T (uint, long, >>, rshift)
T (ulong, long, >>, rshift)

T (int, uint, >>, rshift)
T (long, uint, >>, rshift)
T (int, ulong, >>, rshift)
T (long, ulong, >>, rshift)

T (uint, uint, >>, rshift)
T (ulong, uint, >>, rshift)
T (uint, ulong, >>, rshift)
T (ulong, ulong, >>, rshift)
