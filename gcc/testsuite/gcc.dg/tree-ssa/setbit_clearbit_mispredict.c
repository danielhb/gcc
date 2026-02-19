/* { dg-additional-options -O2 } */
/* { dg-additional-options -fdump-tree-optimized } */

struct bitmap_obstack;
struct bitmap_head;
typedef struct bitmap_head *bitmap;

typedef unsigned long BITMAP_WORD;

struct bitmap_element {

  BITMAP_WORD bits[((128 + (8
                  * 8 * 1u) - 1) / (8
                  * 8 * 1u))];
};

unsigned
bitmap_set_bit (bitmap head, int bit, struct bitmap_element *ptr,
               unsigned indx, unsigned word_num)
{
  unsigned bit_num = bit % (8 * 8 * 1u);
  BITMAP_WORD bit_val = ((BITMAP_WORD) 1) << bit_num;

  if (ptr != 0)
    {
      unsigned res = (ptr->bits[word_num] & bit_val) == 0;

      if (res)
        ptr->bits[word_num] |= bit_val;
      return res;
    }

  return 1;
}

unsigned
bitmap_clear_bit (bitmap head, int bit, struct bitmap_element *ptr,
                  unsigned indx, unsigned word_num)
{
  unsigned bit_num = bit % (8 * 8 * 1u);
  BITMAP_WORD bit_val = ((BITMAP_WORD) 1) << bit_num;

  if (ptr != 0)
    {
      unsigned res = (ptr->bits[word_num] & bit_val) != 0;

      if (res)
        ptr->bits[word_num] &= ~bit_val;
      return res;
    }

  return 1;
}

/* { dg-final { scan-tree-dump-times " goto " 4 optimized } } */