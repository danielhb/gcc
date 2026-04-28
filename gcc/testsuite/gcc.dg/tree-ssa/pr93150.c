/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-forwprop" } */

unsigned foo (unsigned x)
{
  return (x & 0xF) == 4 & (((x & 0xA) == 8) | ((x & 0x7) == 3));
}

unsigned foo2 (unsigned x)
{
  return (x & 0xF) != 4 | (((x & 0xA) != 8) & ((x & 0x7) != 3));
}

/* { dg-final { scan-tree-dump-times " == " 2 "forwprop1" } } */
/* { dg-final { scan-tree-dump-times " != " 2 "forwprop1" } } */
/* { dg-final { scan-tree-dump-times " & " 5 "forwprop1" } } */
/* { dg-final { scan-tree-dump-times " \\| " 1 "forwprop1" } } */
