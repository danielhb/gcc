/* { dg-do run } */
/* { dg-options "-O1" } */

void abort(void);

/* Macro adapted from builtin-object-size-common.h  */
#define FAIL()                                            \
  do {                                                    \
    __builtin_printf ("Failure at line: %d\n", __LINE__); \
    abort ();                                             \
  } while (0)

#define TEST(name,T1,T2,T_RET)          \
__attribute__((noinline,noclone))       \
T_RET test_##name(T1 a) {               \
  T2 t = a;                             \
  t = ~t;                               \
  T_RET ret = t;                        \
  return ret;                           \
}

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

typedef char int8_t;
typedef short int16_t;
typedef int int32_t;

/* (convert:int (bit_not A)) */
TEST(s8_u8_s32,  int8_t, uint8_t,  int32_t)
TEST(u8_s8_s32, uint8_t,  int8_t,  int32_t)

/* (convert:uint (bit_not A)) */
TEST(s8_u8_u32,  int8_t, uint8_t, uint32_t)
TEST(u8_s8_u32, uint8_t,  int8_t, uint32_t)

/* (bit_not (convert:uint8 A)) */
TEST(s16_u8_s8,  int16_t, uint8_t,  int8_t)
TEST(u16_u8_s8, uint16_t, uint8_t,  int8_t)

/* (bit_not (convert:int8 A)) */
TEST(s16_s8_u8,  int16_t,  int8_t, uint8_t)
TEST(u16_s8_u8, uint16_t,  int8_t, uint8_t)

int main ()
{
  int8_t s8 = 0xFD;
  int8_t s8_not = ~s8;
  uint8_t u8 = 0xFE;
  int8_t u8_not = ~u8;
  int16_t s16 = 0xFFFD;
  uint16_t u16 = 0xFFFE;

  /* (convert:int (bit_not A)) */
  if (test_s8_u8_s32 (s8) != (int32_t)s8_not)
    FAIL();
  if (test_u8_s8_s32 (u8) != (int32_t)u8_not)
    FAIL();

  /* (convert:uint (bit_not A)) */
  if (test_s8_u8_u32 (s8) != (uint32_t)s8_not)
    FAIL();
  if (test_u8_s8_u32 (u8) != (uint32_t)u8_not)
    FAIL();

  /* (bit_not (convert:int8 A)) */
  uint8_t s16_ucast = (uint8_t)s16;
  uint8_t s16_ucast_not = ~s16_ucast;
  if (test_s16_u8_s8 (s16) != s16_ucast_not)
    FAIL();
  uint8_t u16_ucast = (uint8_t)u16;
  uint8_t u16_ucast_not = ~u16_ucast;
  if (test_u16_u8_s8 (u16) != u16_ucast_not)
    FAIL();

  /* (bit_not (convert:uint8 A)) */
  int8_t s16_scast = (uint8_t)s16;
  int8_t s16_scast_not = ~s16_scast;
  if (test_s16_s8_u8 (s16) != s16_scast_not)
    FAIL();
  uint8_t u16_scast = (uint8_t)u16;
  uint8_t u16_scast_not = ~u16_scast;
  if (test_u16_s8_u8 (u16) != u16_scast_not)
    FAIL();

  return 0;
}
