/**
 * @file command_handlers.c
 * @brief This file contains the handler functions for each existing command.
 *
 * This file contains the implementation of the handler functions for each
 * existing command.
 *
 * Each handler function takes a pointer to a `Person` struct
 * and returns a boolean indicating whether the command was executed
 * successfully.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "person.h"

LinkedList* globalPersonList = NULL;

/**
 * @brief Initialises the globalPersonList if it does not exist.
 */
static void initialiseList(void) {
  if (globalPersonList == NULL) {
    globalPersonList = createNewLinkedList();
  }
}

bool execute_insert_command(void* personToInsert) {
  Person* person = (Person*)personToInsert;
  initialiseList();
  if (contains(globalPersonList, person, person_compare)) {
    printf("Duplicate person not inserted.\n");
    return false;
  }
  insertAtEnd(globalPersonList, person, false, person_compare);
  sort(globalPersonList, person_compare);
  // sortedInsert(globalPersonList, person, person_compare);
  return true;
}

bool execute_remove_command(void* personToRemove) {
  Person* person = (Person*)personToRemove;
  initialiseList();
  for (size_t i = 0; i < globalPersonList->size; i++) {
    Person* currentPerson = (Person*)getNodeAtIndex(globalPersonList, i)->data;
    if (strcmp(currentPerson->lastName, person->lastName) == 0 &&
        strcmp(currentPerson->firstName, person->firstName) == 0 &&
        currentPerson->age == person->age) {
      deleteAtIndex(globalPersonList, i);
      return true;
    }
  }
  return false;
}

bool execute_show_command(void* personToShow) {
  Person* person = (Person*)personToShow;
  initialiseList();
  if (globalPersonList->size == 0) {
    printf("The list is empty.\n");
    return true;
  }
  for (size_t i = 0; i < globalPersonList->size; i++) {
    Person* currentPerson = (Person*)getNodeAtIndex(globalPersonList, i)->data;
    printf("%i \t %s \n", i, person_to_string(currentPerson));
  }
  return true;
}

bool execute_clear_command(void* personToClear) {
  Person* person = (Person*)personToClear;
  initialiseList();
  deleteList(globalPersonList);
  return true;
}

bool execute_end_command(void* personToEnd) {
  printf("Thanks for using the program!");
  exit(0);
}
