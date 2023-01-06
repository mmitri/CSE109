#include <vector>
#include <stdio.h>
#include "pack109.hpp"

using namespace std;

void write(vec bytes, char* filename) {
   FILE * pFile;
   pFile = fopen(filename,"wb");
   for(int i = 0; i < bytes.size(); i++) {
     putc(bytes[i], pFile);
   }
   fclose(pFile);
  return;
}

vec read(char* filename) {
  FILE * pFile;
  vec buffer;
  int c;
  pFile=fopen(filename,"rb");
  if (pFile==NULL) {
    perror ("Error opening file");
  } else {
    while(1) {
      c = fgetc(pFile);
      if (c == EOF) {
        break;
      }
      buffer.push_back(c);
    }
    fclose(pFile);
  }
  return buffer;
}

int main() {
  struct Person CoreyM = {age: 27, height: 5.8, name: "Corey Montella"};
  auto homework6 = pack109::serialize(CoreyM);
  write(homework6,"person.pack109");
  auto read_homework6 = read("person.pack109");
  auto CoreyMInternet = pack109::deserialize_person(read_homework6);
  pack109::printVec(read_homework6);
  printf("%x\n", CoreyMInternet);
}
