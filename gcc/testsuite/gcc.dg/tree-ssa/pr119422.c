/* { dg-additional-options -O2 } */
/* { dg-additional-options -fdump-tree-optimized } */

typedef enum my_bool {
   val0 = 0,
   val1 = 1
} my_bool;

int gg (unsigned u, my_bool b)
{
  return u <= (u <= (unsigned)b);
}
/* { dg-final { scan-tree-dump-times " >= " 1 "optimized" } } */
