/* { dg-additional-options -O2 } */
/* { dg-additional-options -fdump-tree-phiopt3 } */

unsigned f1 (unsigned x, unsigned m)
{
    if (m & 0x008080)
        x >>= 8;

    return x;
}

unsigned f2 (unsigned x, unsigned m)
{
    if (m & 0x008080)
        x <<= 8;

    return x;
}

unsigned f3 (unsigned x, unsigned m)
{
    if (m & 0x008080)
        x |= 8;

    return x;
}
/* { dg-final { scan-tree-dump-times "PHI" 0 phiopt3 } } */