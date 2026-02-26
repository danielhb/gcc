/* { dg-additional-options -O2 } */
/* { dg-additional-options -fdump-tree-optimized } */

typedef unsigned char uint8_t;
typedef signed char int8_t;

uint8_t f1(int8_t a)
{
    int8_t b = a << 4;
    return b == -128;
}

uint8_t f2(int8_t a)
{
    int8_t b = a << 4;
    return b != -128;
}

uint8_t f3(int8_t a)
{
    int8_t b = a << 6;
    return b == -128;
}

uint8_t f4(int8_t a)
{
    int8_t b = a << 7;
    return b == -128;
}

uint8_t f5(int8_t a)
{
    int8_t b = a << 1;
    return b == -128;
}
/* { dg-final { scan-tree-dump-times " & 15;" 2 optimized } } */
/* { dg-final { scan-tree-dump-times " & 3;" 1 optimized } } */
/* { dg-final { scan-tree-dump-times " & 1;" 1 optimized } } */
/* { dg-final { scan-tree-dump-times " & 127;" 1 optimized } } */
/* { dg-final { scan-tree-dump-times " << " 0 optimized } } */
