/* { dg-do run } */
/* { dg-options "-O2" } */

/* Macro adapted from builtin-object-size-common.h  */
#define FAIL() \
  do { \
    __builtin_printf ("Failure at line: %d\n", __LINE__);    \
    abort();                                                 \
  } while (0)

void abort(void);

unsigned f1 (unsigned x, unsigned m, unsigned n)
{
  if (x & 1)
    m >>= 2;
  return m + n;
}

unsigned f2 (unsigned x, unsigned m, unsigned n)
{
  if (x & 1)
    m <<= 2;
  return m + n;
}

unsigned f3 (unsigned x, unsigned m, unsigned n)
{
  if (x & 1)
    m |= 2;
  return m + n;
}

int main (void) {
  if (f1 (0, 4, 1) != 5)
    FAIL ();
  if (f1 (1, 4, 1) != 2)
    FAIL ();

  if (f2 (0, 2, 1) != 3)
    FAIL ();
  if (f2 (1, 2, 1) != 9)
    FAIL ();

  if (f3 (0, 4, 1) != 5)
    FAIL ();
  if (f3 (1, 4, 1) != 7)
    FAIL ();

  return 0;
}