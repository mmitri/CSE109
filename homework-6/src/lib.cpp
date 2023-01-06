#include <vector>
#include <stdio.h>
#include "pack109.hpp"

using namespace std;

vec pack109::serialize(bool item) {
  vec bytes;
  if (item == true) {
    bytes.push_back(PACK109_TRUE);
  } else {
    bytes.push_back(PACK109_FALSE);
  }
  return bytes;
}

bool pack109::deserialize_bool(vec bytes) {
  if (bytes.size() < 1) {
     throw;
  }

  if (bytes[0] == PACK109_TRUE) {
    return true;
  } else if (bytes[0] == PACK109_FALSE) {
    return false;
  } else {
    throw;
  }

}

vec pack109::serialize(u8 item) {
  vec bytes;
  bytes.push_back(PACK109_U8);
  bytes.push_back(item);
  return bytes;
}

u8 pack109::deserialize_u8(vec bytes) {
  if (bytes.size() < 2) {
    throw;
  }
  if (bytes[0] == PACK109_U8) {
    return bytes[1];
  } else {
    throw;
  }
}

// The sizeof(u32) is 4 bytes, multiply by 2 to make it 8 half bytes, then it subtracts 2. So it starts at 6
vec pack109::serialize(u32 item){
  vec bytes;
  bytes.push_back(PACK109_U32);
  int i = (sizeof(u32)*2)-2;
  for(i; i >= 0;i -=2){
    int shift = (item >> i * 4);
    u32 byte = shift & 0x000000FF;
    bytes.push_back((u32)byte);
  }
  return bytes;
}

u32 pack109::deserialize_u32(vec bytes){
  if(bytes.size() < 5){
    throw;
  }
  u32 result = 0;
  if(bytes[0] == PACK109_U32){
    int j = (sizeof(u32)*2)-2;
    for (int i = 1; i <= sizeof(u32); i++){
        u32 shifted = (u32) bytes[i] << j * 4;
        result = result | shifted;
        j -= 2;
    }
    return result;
  }else{
    throw;
  }
}

vec pack109::serialize(u64 item){
  vec bytes;
  bytes.push_back(PACK109_U64);
  int i = (sizeof(u64)*2)-2;
  for(i; i >= 0;i -=2){
    int shift = (item >> i * 4);
    u64 byte = shift & 0x00000000000000FF;
    bytes.push_back((u64)byte);
  }
  return bytes;
}

u64 pack109::deserialize_u64(vec bytes){
  if(bytes.size() < 11){
    throw;
  }
  u64 result = 0;
  if(bytes[0] == PACK109_U64){
    int j = (sizeof(u64)*2)-2;
    for (int i = 1; i <= sizeof(u64); i++){
        u64 shifted = (u64) bytes[i] << j * 6;
        result = result | shifted;
        j -= 2;
    }
    return result;
  }else{
    throw;
  }
}

vec pack109::serialize(i8 item){
  vec bytes;
  bytes.push_back(PACK109_I8);
  bytes.push_back(item);
  return bytes;
}

i8 pack109::deserialize_i8(vec bytes){
  if (bytes.size() < 2) {
    throw;
  }
  if (bytes[0] == PACK109_I8) {
    return bytes[1];
  } else {
    throw;
  }
}

vec pack109::serialize(i32 item){
  vec bytes;
  bytes.push_back(PACK109_I32);
  int i = (sizeof(i32)*2)-2;
  for(i; i >= 0;i -=2){
    int shift = (item >> i * 4);
    i32 byte = shift & 0x000000FF;
    bytes.push_back((i32)byte);
  }
  return bytes;
}

i32 pack109::deserialize_i32(vec bytes){
  if(bytes.size() < 5){
    throw;
  }
  i32 result = 0;
  if(bytes[0] == PACK109_I32){
    int j = (sizeof(i32)*2)-2;
    for (int i = 1; i <= sizeof(i32); i++){
        i32 shifted = (i32) bytes[i] << j * 4;
        result = result | shifted;
        j -= 2;
    }
    return result;
  }else{
    throw;
  }
}

vec pack109::serialize(i64 item){
  vec bytes;
  bytes.push_back(PACK109_I64);
  int i = (sizeof(i64)*2)-2;
  for(i; i >= 0;i -=2){
    int shift = (item >> i * 4);
    i64 byte = shift & 0x00000000000000FF;
    bytes.push_back((i64)byte);
  }
  return bytes;
}

i64 pack109::deserialize_i64(vec bytes){
  if(bytes.size() < 11){
    throw;
  }
  i64 result = 0;
  if(bytes[0] == PACK109_I64){
    int j = (sizeof(u64)*2)-2;
    for (int i = 1; i <= sizeof(i64); i++){
        i64 shifted = (i64) bytes[i] << j * 6;
        result = result | shifted;
        j -= 2;
    }
    return result;
  }else{
    throw;
  }
}

vec pack109::serialize(f32 item){
  vec bytes;
  bytes.push_back(PACK109_F32);
  bytes.push_back(item);
  return bytes;
}

f32 pack109::deserialize_f32(vec bytes){
  if(bytes.size() < 2){
    throw;
  }
  if(bytes[0] == PACK109_F32){
    for (int i = (sizeof(int) * 2) - 2; i >= 0; i -= 2){
        unsigned char byte = (unsigned char) (bytes[0] >> i * 4) & 0x000000FF;
        printf("%x\n", ((bytes[0] >> i * 4) & 0x000000FF)); // individual bits of the number
        bytes.push_back(byte);
    }
  }else{
    throw;
  }
}

vec pack109::serialize(f64 item){
  vec bytes;
  bytes.push_back(PACK109_F64);
  bytes.push_back(item);
  return bytes;
}

f64 pack109::deserialize_f64(vec bytes){
  if(bytes.size() < 2){
    throw;
  }
  if(bytes[0] == PACK109_F64){
    for (int i = (sizeof(int) * 2) - 2; i >= 0; i -= 2){
        unsigned char byte = (unsigned char) (bytes[0] >> i * 4) & 0x000000FF;
        printf("%x\n", ((bytes[0] >> i * 4) & 0x000000FF)); // individual bits of the number
        bytes.push_back(byte);
    }
  }else{
    throw;
  }
}

vec pack109::serialize(string item){
  vec bytes;
  bytes.push_back(PACK109_S8);
  // bytes.push_back(item);
  return bytes;
}

string pack109::deserialize_string(vec bytes){
  if(bytes.size() < 2){
    throw;
  }
  if(bytes[0] == PACK109_S8){
    for (int i = (sizeof(int) * 2) - 2; i >= 0; i -= 2){
        unsigned char byte = (unsigned char) (bytes[0] >> i * 4) & 0x000000FF;
        printf("%x\n", ((bytes[0] >> i * 4) & 0x000000FF)); // individual bits of the number
        bytes.push_back(byte);
    }
  }else{
    throw;
  }
}
  
vec pack109::serialize(std::vector<u8> item){
  vec bytes;
  bytes.push_back(PACK109_S8);
  // bytes.push_back(item);
  return bytes;
}

std::vector<u8> pack109::deserialize_vec_u8(vec bytes){
  if(bytes.size() < 2){
    throw;
  }
  if(bytes[0] == PACK109_U8){
    for (int i = (sizeof(int) * 2) - 2; i >= 0; i -= 2){
        unsigned char byte = (unsigned char) (bytes[0] >> i * 4) & 0x000000FF;
        printf("%x\n", ((bytes[0] >> i * 4) & 0x000000FF)); // individual bits of the number
        bytes.push_back(byte);
    }
  }else{
    throw;
  }
}

vec pack109::serialize(std::vector<u64> item){
  vec bytes;
  bytes.push_back(PACK109_U64);
  // bytes.push_back(item);
  return bytes;
}

std::vector<u64> pack109::deserialize_vec_u64(vec bytes){
  if(bytes.size() < 2){
    throw;
  }
  if(bytes[0] == PACK109_U64){
    for (int i = (sizeof(int) * 2) - 2; i >= 0; i -= 2){
        unsigned char byte = (unsigned char) (bytes[0] >> i * 4) & 0x000000FF;
        printf("%x\n", ((bytes[0] >> i * 4) & 0x000000FF)); // individual bits of the number
        bytes.push_back(byte);
    }
  }else{
    throw;
  }
}

vec pack109::serialize(std::vector<f64> item){
  vec bytes;
  bytes.push_back(PACK109_F64);
  // bytes.push_back(item);
  return bytes;
}

std::vector<f64> pack109::deserialize_vec_f64(vec bytes){
  if(bytes.size() < 2){
    throw;
  }
  if(bytes[0] == PACK109_F64){
    for (int i = (sizeof(int) * 2) - 2; i >= 0; i -= 2){
        unsigned char byte = (unsigned char) (bytes[0] >> i * 4) & 0x000000FF;
        printf("%x\n", ((bytes[0] >> i * 4) & 0x000000FF)); // individual bits of the number
        bytes.push_back(byte);
    }
  }else{
    throw;
  }
}

vec pack109::serialize(std::vector<string> item){
  vec bytes;
  bytes.push_back(PACK109_S16);
  // bytes.push_back(item);
  return bytes;
}

std::vector<string> pack109::deserialize_vec_string(vec bytes){

}

vec pack109::serialize(struct Person item){
  vec bytes;
  bytes.push_back(PACK109_M16);
  // bytes.push_back(item);
  return bytes;
}

struct Person pack109::deserialize_person(vec bytes){
  if(bytes.size() < 2){
    throw;
  }
  if(bytes[0] == PACK109_M16){
    for (int i = (sizeof(int) * 2) - 2; i >= 0; i -= 2){
        unsigned char byte = (unsigned char) (bytes[0] >> i * 4) & 0x000000FF;
        printf("%x\n", ((bytes[0] >> i * 4) & 0x000000FF)); // individual bits of the number
        bytes.push_back(byte);
    }
  }else{
    throw;
  }
}

void pack109::printVec(vec &bytes) {
  printf("[ ");
  for (int i = 0; i < bytes.size(); i++) {
    printf("%x ", bytes[i]);
  }
  printf("]\n");
}