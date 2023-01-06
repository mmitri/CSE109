#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "pack109.hpp"
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <memory>


#define X8  256
#define X16 65536

vec slice(vec& bytes, int vbegin, int vend) {
  auto start = bytes.begin() + vbegin;
  auto end = bytes.begin() + vend + 1;
  vec result(vend - vbegin + 1);
  copy(start, end, result.begin());
  return result;
}

vec pack109::serialize(u8 item) {
  vec bytes;
  bytes.push_back(PACK109_U8);
  bytes.push_back(item);
  return bytes;
}

void pack109::printVec(vec &bytes) {
  printf("[ ");
  for (int i = 0; i < bytes.size(); i++) {
    printf("%x ", bytes[i]);
  }
  printf("]\n");
}

vec pack109::serialize(std::vector<u8> item) {
  vec bytes;
  if (item.size() < X8) {
    bytes.push_back(PACK109_A8);
    u8 size = (u8)item.size();
    bytes.push_back(size);
    for (int i = 0; i < item.size(); i++) {
      vec temp = serialize(item[i]);
      for (int j = 0; j < temp.size(); j++) {
        bytes.push_back(temp[j]);
      }
    }
  } else if (item.size() < X16) {
    bytes.push_back(PACK109_A16);
    u32 item_length = (u32)item.size();
    bytes.push_back((u8)(item_length >> 8));
    bytes.push_back((u8)(item_length));
    for (int i = 0; i < item.size(); i++) {
      vec elem = serialize(item[i]);
      bytes.insert(end(bytes), begin(elem), end(elem));
    }
  } else {
    printf("ERROR: Serialization");
    throw;
  }
  printf("Serializtion Complete!\n");
  return bytes;
}

std::vector<f64> pack109::deserialize_vec_f64(vec bytes) {
  if(bytes.size() < 3) {
    throw;
  }
  int el_size = 9;
  std::vector<f64> result;
  if(bytes[0] == PACK109_A8) {
    int size = el_size * bytes[1];
    for (int i = 2; i < (size + 2); i += el_size) {
      vec sub_vec = slice(bytes, i, i + el_size);
      u64 element = deserialize_f64(sub_vec);
      result.push_back(element);
    }
  } else if(bytes[0] == PACK109_A16) {
    int size = el_size * (((int)bytes[1])<<8 | (int)bytes[2]);
    for(int i = 2; i < (size + 2); i += el_size) {
      vec sub_vec = slice(bytes, i + 1, i + el_size);
      u64 element = deserialize_f64(sub_vec);
      result.push_back(element);
    }
  }
  return result;
}

void writeFiles(vec bytes, char* filename) {
   FILE * pFile;
   pFile = fopen(filename,"wb");
   for(int i = 0; i < bytes.size(); i++) {
     putc(bytes[i], pFile);
   }
   fclose(pFile);
  return;
};

vec readFiles(char* filename) {
  FILE * pFile;
  vec buffer;
  int c;
  pFile=fopen(filename,"rb");
  if (pFile==NULL) {
    perror("ERROR: Reading File\n");
  } else {
    printf("Reading File...\n");
    while(1) {
      c = fgetc(pFile);
      if (c == EOF) {
        break;
      }
      buffer.push_back(c);
    }
    fclose(pFile);
    printf("Reading File Complete!\n");
  }
  
  return buffer;
};