/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-optimized" } */

unsigned char f1_and (unsigned int a)
{
  unsigned char t = a;
  t = t & 123;
  return t;
}

unsigned char f2_and (unsigned int a)
{
  a = a & 123;
  unsigned char t = a;
  return t;
}

int f_and (unsigned int t)
{
  return f1_and (t) == f2_and (t);
}

unsigned char f1_ior (unsigned int a)
{
  unsigned char t = a;
  t = t | 1;
  return t;
}

unsigned char f2_ior (unsigned int a)
{
  a = a | 1;
  unsigned char t = a;
  return t;
}

int f_ior(unsigned int t)
{
  return f1_ior (t) == f2_ior (t);
}

unsigned char f1_xor (unsigned int a)
{
  unsigned char t = a;
  t = t ^ 123;
  return t;
}

unsigned char f2_xor (unsigned int a)
{
  a = a ^ 123;
  unsigned char t = a;
  return t;
}

int f_xor (unsigned int t)
{
  return f1_xor (t) == f2_xor (t);
}

/* { dg-final { scan-tree-dump-times " return 1;" 3 "optimized" } } */
