/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-optimized" } */
const char a[] = "12345";
const char a2[] = "1234";

void f (int i)
{
  if (__builtin_strnlen (&a[i], 7) > 5)
    __builtin_abort ();
}

void f2 (int i)
{
  if (__builtin_strnlen (&a2[i], 7) > 5)
    __builtin_abort ();
}

/* { dg-final { scan-tree-dump-times "strnlen " 0 "optimized" } } */
