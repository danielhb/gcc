/* { dg-additional-options -O2 } */
/* { dg-additional-options -fdump-tree-cselim } */

int bitset1 (int n, int bit)
{
  int arr[16];

  int bitshift = 1 << bit;

  if ((arr[n] & bitshift) == 0)
    arr[n] |= bitshift;

  return arr[n];
}

int bitset2 (int n)
{
  int arr[16];

  int bit = 0x4;

  if ((arr[n] & bit) == 0)
    arr[n] |= bit;

  return arr[n];
}

int bitset3 (int n)
{
  int arr[16];

  int bits = 0xF;

  if ((arr[n] & bits) == 0)
    arr[n] |= bits;

  return arr[n];
}

int bitclear1 (int n, int bit)
{
  int arr[16];

  int bitshift = 1 << bit;

  if ((arr[n] & bitshift) != 0)
    arr[n] &= ~bitshift;

  return arr[n];
}

int bitclear2 (int n)
{
  int arr[16];

  int bit = 0x4;

  if ((arr[n] & bit) != 0)
    arr[n] &= ~bit;

  return arr[n];
}

int bitclear3 (int n)
{
  int arr[16];

  int bits = 0xF;

  if ((arr[n] & bits) != 0)
    arr[n] &= ~bits;

  return arr[n];
}

/* bitset3 won't be optimized all willl kept its branch.  */
/* { dg-final { scan-tree-dump-times "goto" 2 cselim } } */
