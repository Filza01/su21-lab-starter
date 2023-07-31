// Copyright [2023] <Filza Shahid>

#include <stdio.h>

#define NO_WORDS 2
#define SIZE_WORDS NO_WORDS << 3

typedef struct {
  unsigned long long double_word[NO_WORDS];
} arr_t __attribute__((
    aligned(SIZE_WORDS)));  // align the structure to 16 byte boundary

arr_t store_byte_data[8] = {{0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000}};

arr_t store_byte_expected_data[8] = {{0x00000000000000EF, 0x0000000000000000},
                                     {0x000000000000BE00, 0x0000000000000000},
                                     {0x0000000000AD0000, 0x0000000000000000},
                                     {0x00000000DE000000, 0x0000000000000000},
                                     {0x000000EF00000000, 0x0000000000000000},
                                     {0x0000BE0000000000, 0x0000000000000000},
                                     {0x00AD000000000000, 0x0000000000000000},
                                     {0xDE00000000000000, 0x0000000000000000}};

arr_t store_half_word_data[8] = {{0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000}};

arr_t store_half_word_expected_data[8] = {
    {0x000000000000BEEF, 0x0000000000000000},
    {0x0000000000ADBE00, 0x0000000000000000},
    {0x00000000DEAD0000, 0x0000000000000000},
    {0x000000EFDE000000, 0x0000000000000000},
    {0x0000BEEF00000000, 0x0000000000000000},
    {0x00ADBE0000000000, 0x0000000000000000},
    {0xDEAD000000000000, 0x0000000000000000},
    {0xDE00000000000000, 0x00000000000000EF}};

arr_t store_word_data[8] = {{0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000}};

arr_t store_word_expected_data[8] = {{0x00000000DEADBEEF, 0x0000000000000000},
                                     {0x000000DEADBEEF00, 0x0000000000000000},
                                     {0x0000DEADBEEF0000, 0x0000000000000000},
                                     {0x00DEADBEEF000000, 0x0000000000000000},
                                     {0xF00DC0DE00000000, 0x0000000000000000},
                                     {0x0DC0DE0000000000, 0x00000000000000F0},
                                     {0xC0DE000000000000, 0x000000000000F00D},
                                     {0xDE00000000000000, 0x0000000000F00DC0}};

arr_t store_double_word_data[8] = {{0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000}};

arr_t store_double_word_expected_data[8] = {
    {0xDEADBEEFF00DC0DE, 0x0000000000000000},
    {0xADBEEFF00DC0DE00, 0x00000000000000DE},
    {0xBEEFF00DC0DE0000, 0x000000000000DEAD},
    {0xEFF00DC0DE000000, 0x0000000000DEADBE},
    {0xF00DC0DE00000000, 0x00000000DEADBEEF},
    {0x0DC0DE0000000000, 0x000000DEADBEEFF0},
    {0xC0DE000000000000, 0x0000DEADBEEFF00D},
    {0xDE00000000000000, 0x00DEADBEEFF00DC0}};

int store_byte_test(arr_t *byte_data, int size, arr_t *byte_expected_data) {
  // EF, BE, AD, DE, EF, BE, AD, DE
  // printf("%llx\n", (byte_data+1)->double_word[0]);
  long long unsigned int arr[8] = {0xEF, 0xBE, 0xAD, 0xDE,
                                   0xEF, 0xBE, 0xAD, 0xDE};
  int count = 0;

  for (int i = 0; i < size; i++) {
    if (i > 0) {
      arr[i] = arr[i] << 8 * i;
    }
    (byte_data + i)->double_word[0] = arr[i];
  }

  // printf("{\n");
  for (int i = 0; i < size; i++) {
    if (((byte_data + i)->double_word[0] ==
         (byte_expected_data + i)->double_word[0]) &&
        ((byte_data + i)->double_word[1] ==
         (byte_expected_data + i)->double_word[1])) {
      // printf("{%llX, ", (byte_data+i)->double_word[0]);
      // printf("%llX}\n", (byte_data+i)->double_word[1]);
      continue;
    } else {
      count++;
      printf("(byte_data+%d)={%llX, %llX} mismatched\n", i,
             (byte_data + i)->double_word[0], (byte_data + i)->double_word[1]);
    }
  }
  // printf("}\n");

  if (count == 0) {
    return 1;
  } else {
    return 0;
  }
}  // store_byte_test

int store_half_word_test(arr_t *half_word_data, int size,
                         arr_t *half_word_expected_data) {
  // BEEF, ADBE, DEAD, EFDE, BEEF, ADBE, DEAD, EFDE
  long long unsigned int arr[8] = {0xBEEF, 0xADBE, 0xDEAD, 0xEFDE,
                                   0xBEEF, 0xADBE, 0xDEAD, 0xEFDE};
  long long unsigned int overflow_bits = 0;
  int count = 0;

  for (int i = 0; i < size; i++) {
    if (i > 0) {
      overflow_bits = arr[i] >> (sizeof(long long unsigned int) * 8 - 8 * i);
      (half_word_data + i)->double_word[1] = overflow_bits;
      arr[i] = arr[i] << 8 * i;
    }
    (half_word_data + i)->double_word[0] = arr[i];
  }

  // printf("{\n");
  for (int i = 0; i < size; i++) {
    if (((half_word_data + i)->double_word[0] ==
         (half_word_expected_data + i)->double_word[0]) &&
        ((half_word_data + i)->double_word[1] ==
         (half_word_expected_data + i)->double_word[1])) {
      // printf("{%llX, ", (half_word_data+i)->double_word[0]);
      // printf("%llX}\n", (half_word_data+i)->double_word[1]);
      continue;
    } else {
      count++;
      printf("(half_word_data+%d)={%llX, %llX} mismatched\n", i,
             (half_word_data + i)->double_word[0],
             (half_word_data + i)->double_word[1]);
    }
  }
  // printf("}\n");

  if (count == 0) {
    return 1;
  } else {
    return 0;
  }
}  // store_half_word_test

int store_word_test(arr_t *word_data, int size, arr_t *word_expected_data) {
  // DEADBEEF, F00DC0DE
  long long unsigned int arr[2] = {0xDEADBEEF, 0xF00DC0DE};
  long long unsigned int overflow_bits = 0;
  long long unsigned int data = arr[0];
  int count = 0;

  for (int i = 0; i < size; i++) {
    if (i < (size / 2)) {
      if (i > 0) {
        overflow_bits = arr[0] >> (sizeof(long long unsigned int) * 8 - 8 * i);
        (word_data + i)->double_word[1] = overflow_bits;
        data = arr[0] << 8 * i;
      }
      (word_data + i)->double_word[0] = data;
    } else {
      overflow_bits = arr[1] >> (sizeof(long long unsigned int) * 8 - 8 * i);
      (word_data + i)->double_word[1] = overflow_bits;
      data = arr[1] << 8 * i;
      (word_data + i)->double_word[0] = data;
    }
  }

  // printf("{\n");
  for (int i = 0; i < size; i++) {
    if (((word_data + i)->double_word[0] ==
         (word_expected_data + i)->double_word[0]) &&
        ((word_data + i)->double_word[1] ==
         (word_expected_data + i)->double_word[1])) {
      // printf("{%llX, ", (word_data+i)->double_word[0]);
      // printf("%llX}\n", (word_data+i)->double_word[1]);
      continue;
    } else {
      count++;
      printf("(word_data+%d)={%llX, %llX} mismatched\n", i,
             (word_data + i)->double_word[0], (word_data + i)->double_word[1]);
    }
  }
  // printf("}\n");

  if (count == 0) {
    return 1;
  } else {
    return 0;
  }
}  // store_word_test

int store_double_word_test(arr_t *double_word_data, int size,
                           arr_t *double_word_expected_data) {
  // DEADBEEFF00DC0DE
  long long unsigned int arr[1] = {0xDEADBEEFF00DC0DE};
  long long unsigned int overflow_bits = 0;
  long long unsigned int data = arr[0];
  int count = 0;

  for (int i = 0; i < size; i++) {
    if (i > 0) {
      overflow_bits = arr[0] >> (sizeof(long long unsigned int) * 8 - 8 * i);
      (double_word_data + i)->double_word[1] = overflow_bits;
      data = arr[0] << 8 * i;
      (double_word_data + i)->double_word[0] = data;
    }
    (double_word_data + i)->double_word[0] = data;
  }

  // printf("{\n");
  for (int i = 0; i < size; i++) {
    if (((double_word_data + i)->double_word[0] ==
         (double_word_expected_data + i)->double_word[0]) &&
        ((double_word_data + i)->double_word[1] ==
         (double_word_expected_data + i)->double_word[1])) {
      // printf("{%llX, ", (double_word_data+i)->double_word[0]);
      // printf("%llX}\n", (double_word_data+i)->double_word[1]);
      continue;
    } else {
      count++;
      printf("(double_word_data+%d)={%llX, %llX} mismatched\n", i,
             (double_word_data + i)->double_word[0],
             (double_word_data + i)->double_word[1]);
    }
  }
  // printf("}\n");

  if (count == 0) {
    return 1;
  } else {
    return 0;
  }
}  // store_double_word_test

int main() {
  arr_t *byte_data, *byte_expected_data;
  arr_t *half_word_data, *half_word_expected_data;
  arr_t *word_data, *word_expected_data;
  arr_t *double_word_data, *double_word_expected_data;

  int size = 8;
  int byte_stored, half_word_stored, word_stored, double_word_stored;

  byte_data = store_byte_data;
  byte_expected_data = store_byte_expected_data;
  byte_stored = store_byte_test(byte_data, size, byte_expected_data);
  if (byte_stored == 1) {
    printf("store_byte_test passed.\n");
  } else {
    printf("Failed. There was some error in store_byte_test.\n");
  }

  half_word_data = store_half_word_data;
  half_word_expected_data = store_half_word_expected_data;
  half_word_stored =
      store_half_word_test(half_word_data, size, half_word_expected_data);
  if (half_word_stored == 1) {
    printf("store_half_word_test passed.\n");
  } else {
    printf("Failed. There was some error in store_half_word_test.\n");
  }

  word_data = store_word_data;
  word_expected_data = store_word_expected_data;
  word_stored = store_word_test(word_data, size, word_expected_data);
  if (word_stored == 1) {
    printf("store_word_test passed.\n");
  } else {
    printf("Failed. There was some error in store_word_test.\n");
  }

  double_word_data = store_double_word_data;
  double_word_expected_data = store_double_word_expected_data;
  double_word_stored =
      store_double_word_test(double_word_data, size, double_word_expected_data);
  if (double_word_stored == 1) {
    printf("store_double_word_test passed.\n");
  } else {
    printf("Failed. There was some error in store_double_word_test.\n");
  }

  return 0;
}  // main
