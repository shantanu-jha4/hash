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
  add(hashTable, "Engr", "Civil");
  add(hashTable, "Engr", "Electrical");
  
  //printf("%s\n", get(hashTable, "CompSci"));
  printf("%s\n", get(hashTable, "Engr", "Mechanical"));
  printf("%s\n", get(hashTable, "Engr", "Electrical"));
  printf("%s\n", get(hashTable, "Engr", "Civil"));
  printf("%s\n", get(hashTable, "Lit", "Lord of the flies"));
  freeTable(hashTable);
  return 0;
}
