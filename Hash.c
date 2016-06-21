/* Hash Implementation
   C file: Hash.c
   Author: Shantanu Jha
*/

// Header Files
#include "Hash.h"
#include <assert.h>
hashtable_t* create_table(int size) {
  hashtable_t* hashTable = (hashtable_t*) malloc (sizeof(hashtable_t));
  if (hashTable == NULL)
	return NULL;
  
  hashTable->table = malloc (sizeof(h_ent*) * size);
  if (hashTable->table == NULL)
	return NULL;

  int i;
  for (i = 0; i < size; i++) {
    hashTable->table[i] = (h_ent*) malloc (sizeof(h_ent));
  }

  hashTable->size = size;
  return hashTable;
}

int hash(hashtable_t* hashTable, char* key) {
  int hashVal = 0;
  int i;
  for (i = 0; key[i]; i++)
    hashVal += key[i];
  return hashVal % hashTable->size;
}

h_ent* create_newPair(char* key, char* value) {
  h_ent* ent = (h_ent*) malloc (sizeof(h_ent));
  if (ent == NULL)	
	return NULL;
  ent->key = strdup(key);
  ent->value = strdup(value);
  return ent;
}

int put(hashtable_t* hashTable, char* key, char* value) {
  if (!hashTable || !key || !value)
	return 0;
  
  h_ent* newPair = NULL;
  h_ent* ent = NULL;
  h_ent* last = NULL;
  
  int index = hash(hashTable, key); 
  ent = hashTable->table[index]; //Checking if an element is already there in table[index]
  while (ent && ent->key) { 
    if (strcmp(key, ent->key) == 0) {
        break;
   }
    last = ent;
    ent = ent->next;
  }
  
  if (ent && ent->key && strcmp(ent->key, key) == 0) {
     int bin = hash(hashTable, ent->key);
     hashTable->table[bin]->next->value = strdup(value);
     hashTable->table[bin]->next->key = ent->key;
     return 1;

  }
  
  else {    // Entity does not exist
    newPair = create_newPair(key, value);
    newPair->next = hashTable->table[index];
    hashTable->table[index] = newPair; 
    return 1;
  }
  free(newPair);
  free(ent);
  free(last);
  return 0;
}

char* get(hashtable_t* hashTable, char* key) {
  h_ent* ent = NULL;
  int index = hash(hashTable, key);
  ent = hashTable->table[index]; 
  while (ent && ent->key) { 
    if (strcmp(key, ent->key) == 0)
	break; 
    ent = ent->next;
  }
  if (ent) {
    if (ent->next && ent->next->value) {
         return ent->next->value;
     }   
     else
         return ent->value;
}
return NULL;
}

void freeTable(hashtable_t* hashTable) {
  if (hashTable == NULL || hashTable->table == NULL) {
    printf("Memory already freed\n");
    return;
  }
  int i;
  for (i = 0; i<hashTable->size; i++) {
    if (hashTable->table[i] == NULL)
      free(hashTable->table[i]);
  }
  free(hashTable->table);
  free(hashTable);
  printf("Memory freed\n");
}
