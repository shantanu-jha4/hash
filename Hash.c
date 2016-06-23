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
  
  int index = hash(hashTable, key); 
  ent = hashTable->table[index]; //Checking if an element is already there in table[index]
  while (ent && ent->key) { 
    if (strcmp(key, ent->key) == 0) { 
	break;
   }
    ent = ent->next;
  }
  
  if (ent && ent->key && strcmp(ent->key, key) == 0) {
     int bin = hash(hashTable, ent->key);
     h_ent* temp = hashTable->table[bin];
     while (temp) { 
       temp = temp->next; 
     }
     h_ent* temp_ent = create_newPair(key, value);
     temp = temp_ent;
     temp->next = hashTable->table[bin];
     hashTable->table[bin] = temp;
     return 1;
  }
  else {    // Entity does not exist
    newPair = create_newPair(key, value);
    hashTable->table[index] = newPair;
    hashTable->table[index]->next = NULL;
    return 1;
  }
  free(newPair);
  free(ent);
  return 0;
}

char* get(hashtable_t* hashTable, char* key, char* value) {
  h_ent* ent = NULL;
  int index = hash(hashTable, key);
  ent = hashTable->table[index]; 
  while (ent && ent->key) { 
    if (strcmp(key, ent->key) == 0)
	break; 
    ent = ent->next;
  }
  if (ent && strcmp(key, ent->key) == 0) { 
     while (ent) {
       if (strcmp(ent->value,value) == 0)
	   return ent->value;
       ent = ent->next;
     }
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
