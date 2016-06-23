/* Hash Implemention
   Header File: hash.h
   Author: Shantanu Jha
*/ 


/* Header Files to include*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// Defining Hash entity
typedef struct hash_ent {
  char* key;
  char* value; 
  struct hash_ent* next;
} h_ent;

typedef struct hashtable_s {
  h_ent **table; 
  int size; // Prime is highly recommended
} hashtable_t;


/* FUNCTIONS... */

// Create a new Hash Table
hashtable_t* create_table(int size);

// Gives hash indexes
int hash(hashtable_t* hashTable, char* key);

// Creates a new entity
h_ent* create_newPair(char* key, char* value);

// Puts value in the table
int put(hashtable_t* hashTable, char* key, char* value);

// Retrieves value from table
char* get(hashtable_t* hashTable, char* key, char* value);

// Free's the space table occupies
void freeTable(hashtable_t* hashTable);

void print(hashtable_t* hashTable);
