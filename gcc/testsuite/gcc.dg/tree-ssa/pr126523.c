/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-optimized" } */

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef signed char int8;
typedef signed short int16;
typedef signed int int32;

int32 f1 (int32 a)
{
    uint32 t = a;
    t = ~t;
    int32 a1 = t;
    return a1;
}
int32 f1_2 (int32 a) { return ~a; }
int f1_res (int32 a) { return f1 (a) == f1_2 (a);}

int16 f2 (int16 a)
{
    uint32 t = a;
    t = ~t;
    int16 a1 = t;
    return a1;
}
int16 f2_2 (int16 a) { return ~a; }
int f2_res (int16 a) { return f2 (a) == f2_2 (a);}

int8 f3 (int16 a)
{
    uint16 t = a;
    t = ~t;
    int8 a1 = t;
    return a1;
}
int8 f3_2 (int16 a) { return ~(int8)a; }
int f3_res (int16 a) { return f3 (a) == f3_2 (a);}

uint8 f4 (uint16 a)
{
    int32 t = a;
    t = ~t;
    uint8 a1 = t;
    return a1;
}
uint8 f4_2 (uint16 a) { return ~(uint8)a; }
int f4_res (uint16 a) { return f4 (a) == f4_2 (a);}

/* { dg-final { scan-tree-dump-times " return 1;" 4 "optimized" } } */
