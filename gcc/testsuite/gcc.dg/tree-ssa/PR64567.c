/* { dg-additional-options -O2 } */
/* { dg-additional-options -fdump-tree-phiopt } */

#define F1 0x04
#define F2 0x08

int bar(unsigned flags);

int foo(unsigned flags)
{
  if (flags & (F1 | F2))
    flags &= ~(F1 | F2);
  return bar(flags);
}

int baz(unsigned flags)
{
  if (!(flags & F1))
    flags |= F1;
  return bar(flags);
}

/* { dg-final { scan-tree-dump-times " PHI " 0 phiopt2 } } */
