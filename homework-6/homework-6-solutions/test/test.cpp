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
  vec v3{0xa2, 0x43};
  vec bytes3 = pack109::serialize(item1);
  testvec("Test 5 - u8 ser", bytes3, v3);
  
  u8 int_u8 = pack109::deserialize_u8(bytes3);  
  test("Test 6 - u8 de", int_u8, item1);

  // u32

  // u64

  // i8

  // i32

  // i64

  // Test Float

  // f32

  // f64

  // Test Strings

  // s8

  // s16

  // Test Arrays

  // a8

  // a16

  // Test Maps

  // m8

  // m16 

  return 0;
}