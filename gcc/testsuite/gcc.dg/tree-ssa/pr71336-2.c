/* { dg-do run } */
/* { dg-options "-O1" } */

/* Macro adapted from builtin-object-size-common.h  */
#define FAIL() \
  do { \
    __builtin_printf ("Failure at line: %d\n", __LINE__);     \
    abort();						      \
  } while (0)

void abort(void);

int test (int a) {
    return a & 1 ? 7 : 3;
}

int test2 (int a) {
    return a & 1 ? 3 : 7;
}

int test3 (int a) {
    return (a & 1) == 0 ? 3 : 7;
}

int test4 (int a) {
    return (a & 1) == 0 ? 7 : 3;
}

int main (void) {
  if (test (0) != 3)
    FAIL ();
  if (test (1) != 7)
    FAIL ();
  if (test (3) != 7)
    FAIL ();

  if (test2 (0) != 7)
    FAIL ();
  if (test2 (1) != 3)
    FAIL ();
  if (test2 (3) != 3)
    FAIL ();

  if (test3 (0) != 3)
    FAIL ();
  if (test3 (1) != 7)
    FAIL ();
  if (test3 (2) != 3)
    FAIL ();

  if (test4 (0) != 7)
    FAIL ();
  if (test4 (1) != 3)
    FAIL ();
  if (test4 (2) != 7)
    FAIL ();

  return 0;
}
