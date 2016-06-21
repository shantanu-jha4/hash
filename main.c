/* Hash Implementation
   C File: main.c
   Author: Shantanu Jha
*/

//Header files
#include "Hash.h"

void add (hashtable_t* hashTable, char* key, char* value) {
   if (put(hashTable, key, value) == 1)
      printf("Add Successful\n");
   else
      printf("Add Failed\n");
}

int main() {
  hashtable_t* hashTable = create_table(67);
  add(hashTable, "CompSci", "Security");
  add(hashTable, "Engr", "Mechanical");
  add(hashTable, "Lit", "Lord of the flies");
  //print(hashTable);
  printf("%s\n", get(hashTable, "CompSci"));
  printf("%s\n", get(hashTable, "Engr"));
  printf("%s\n", get(hashTable, "Lit"));
  freeTable(hashTable);
  return 0;
}
