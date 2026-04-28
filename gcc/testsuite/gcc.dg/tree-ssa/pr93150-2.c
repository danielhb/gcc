/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-forwprop" } */

unsigned foo (unsigned a)
{
  return ((a & 12) == 8) & ((a & 7) == 3);
}

unsigned foo2 (unsigned a)
{
  return ((a & 12) != 8) | ((a & 7) != 3);
}

/* { dg-final { scan-tree-dump-times " & " 2 "forwprop1" } } */
/* { dg-final { scan-tree-dump-times " == " 1 "forwprop1" } } */
/* { dg-final { scan-tree-dump-times " != " 1 "forwprop1" } } */
