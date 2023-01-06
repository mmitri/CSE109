#include <stdexcept>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include"pack109.hpp"

template <class T>
int test(const char* label, T lhs, T rhs) {
  printf("%s: ", label);
  if (lhs==rhs) {
    printf("Passed\n");
    return 1;
  } else {
    printf("Failed\n");
    printf("  lhs=%x\n", lhs);
    printf("  rhs=%x\n", rhs);
    exit(1);
  }
}

int testvec(const char* label, vec lhs, vec rhs) {
  printf("%s: ", label);
  if (lhs==rhs) {
    printf("Passed\n");
    return 1;
  } else {
    printf("Failed\n");
    printf("  lhs="); pack109::printVec(lhs); printf("\n");
    printf("  rhs="); pack109::printVec(rhs); printf("\n");
    exit(1);
  }
}


int main() {

  // Test bool

  // True
  vec v1{0xa0};
  vec bytes1 = pack109::serialize(true);
  testvec("Test 1 - true ser", bytes1, v1);

  bool bool_true = pack109::deserialize_bool(bytes1);
  test("Test 2 - true de", bool_true, true);
 

  // False
  vec v2{0xa1};
  vec bytes2 = pack109::serialize(false);
  testvec("Test 3 - false ser", bytes2, v2);

  bool bool_false = pack109::deserialize_bool(bytes2); 
  test("Test 4 - false de", bool_false, false);

  // Test Integers

  // u8
  u8 item1 = 0x42;
  vec v3{0xa2, 0x42};
  vec bytes3 = pack109::serialize(item1);
  testvec("Test 5 - u8 ser", bytes3, v3);
  
  u8 int_u8 = pack109::deserialize_u8(bytes3);  
  test("Test 6 - u8 de", int_u8, item1);

  // u32
  u32 item2 = 0xABCDEF12;
  vec v4{0xa3, 0xAB, 0xCD, 0xEF, 0x12};
  vec bytes4 = pack109::serialize(item2);
  testvec("Test 7 - u32 ser", bytes4, v4);

  u32 int_u32 = pack109::deserialize_u32(bytes4);
  test("Test 8 - u32 de", int_u32, item2);

  // u64
  u64 item3 = 0xAABBCCDDEEFF1234;
  vec v5{0xa4,0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x12, 0x34};
  vec bytes5 = pack109::serialize(item3);
  testvec("Test 9 - u64 ser", bytes5, v5);

  u64 int_u64 = pack109::deserialize_u64(bytes5);
  test("Test 10 - u64 de", int_u64, item3);

  // i8
  i8 item4 = 0xA5;
  vec v6{0xa5,0xA5};
  vec bytes6 = pack109::serialize(item4);
  testvec("Test 11 - i8 ser", bytes6, v6);

  i8 int_i8 = pack109::deserialize_i8(bytes6);
  test("Test 12 - i8 de", int_i8, item4);

  // i32
  i32 item5 = 0xC41684A4;
  vec v7{0xa6, 0xC4, 0x16, 0x84, 0xA4};
  vec bytes7 = pack109::serialize(item5);
  testvec("Test 13 - i32 ser", bytes7, v7);

  i32 int_i32 = pack109::deserialize_i32(bytes7);
  test("Test 14 - i32 de", int_i32, item5);

  // i64
  i64 item6 = 0xEDE8DFBD2B0AD862;
  vec v8{0xa7, 0xED, 0xE8, 0xDF, 0xBD, 0x2B, 0x0A, 0xD8, 0x62};
  vec bytes8 = pack109::serialize(item6);
  testvec("Test 15 - i64 ser", bytes8, v8);

  i64 int_i64 = pack109::deserialize_i64(bytes8);
  test("Test 16 - i64 de", int_i64, item6);

  // Test Float

  // f32
  f32 item7 = 0xC378C000;
  vec v9{0xa8, 0xC3, 0x78, 0xC0, 0x00};
  vec bytes9 = pack109::serialize(item7);
  testvec("Test 17 - f32 ser", bytes9, v9);

  f32 int_f32 = pack109::deserialize_f32(bytes9);
  test("Test 18 - f32 de", int_f32, item7);

  // f64
  f64 item8 = 0x3FD5555555555555;
  vec v10{0xa9, 0x3F, 0xD5, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55};
  vec bytes10 = pack109::serialize(item8);
  testvec("Test 19 - f64 ser", bytes10, v10);

  f64 int_f64 = pack109::deserialize_f64(bytes10);
  test("Test 20 - f64 de", int_f64, item8); 

  // Test Strings

  // s8
  string item9 = "Hello World";
  vec v11{0xaa,0xBE};
  vec bytes11 = pack109::serialize(item9);
  testvec("Test 21 - s8 ser", bytes9, v9);

  string int_s8 = pack109::deserialize_string(bytes11);
  test("Test 22 - s8 de", int_s8, item9);

  // s16
  string item10 = "Pizza";
  vec v12{0xab,0xBE};
  vec bytes12 = pack109::serialize(item10);
  testvec("Test 23 - s16 ser", bytes12, v12);

  string int_s16 = pack109::deserialize_string(bytes12);
  test("Test 24 - s16 de", int_s16, item10);

  // Test Arrays

  // a8
  std::vector<u8> item11 = {0x42};
  vec v13{0xac, 0x04, 0xa2, 0x01, 0xa2, 0x02, 0xa2, 0x03, 0xa2, 0x42};
  vec bytes13 = pack109::serialize(item11);
  testvec("Test 25 - a8 ser", bytes13, v13);

  std::vector<u8> int_a8 = pack109::deserialize_vec_u8(bytes13);
  test("Test 26 - a8 de", int_a8, item11);

  // a64
  std::vector<u64> item12 = {0,1,12,3,45,1212,131234,512};
  vec v14{0xad,0xBE};
  vec bytes14 = pack109::serialize(item12);
  testvec("Test 27 - a64 ser", bytes14, v14);

  std::vector<u64> int_a64 = pack109::deserialize_vec_u64(bytes14);
  test("Test 28 - a64 de", int_a64, item12);

  // Test Maps
  
  // m8
  Person item13 = {age: 10, height: 3.4, name: "Ann"};
  vec v15{0xae,0xBE};
  vec bytes15 = pack109::serialize(item13);
  testvec("Test 29 - m8 ser", bytes15, v15);

  Person int_m8 = pack109::deserialize_person(bytes15);
  test("Test 30 - m8 de", int_m8, item13);

  // m16 
  Person item14 = {age: 21, height: 6.2, name: "John"};
  vec v16{0xaf,0xBE};
  vec bytes16 = pack109::serialize(item14);
  testvec("Test 31 - m8 ser", bytes15, v15);

  Person int_m16 = pack109::deserialize_person(bytes16);
  test("Test 32 - m8 de", int_m16, item14);
  return 0;
}