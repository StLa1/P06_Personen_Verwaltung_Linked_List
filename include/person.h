#ifndef PERSON_H
#define PERSON_H

#define NAME_LEN 20

/**
 * A person with a lastName, first lastName, and age.
 */
typedef struct {
  /**
   * The person's last name.
   */
  char lastName[NAME_LEN];
  /**
   * The person's first name.
   */
  char firstName[NAME_LEN];
  /**
   * The person's age.
   */
  int age;
} Person;

/**
 * @brief  Compares two persons in this sequence: 1st=lastName, 2nd=firstName,
 * 3rd=age
 * @param  personA [IN] const reference to 1st person in the comparison
 * @param  personB [IN] const reference to 2nd person in the comparison
 * @return =0 if all record fields are the same
 *         >0 if all previous fields are the same, but for this field, personA
 *         is greater (e.g. "Smith" > "John")
 *         <0 if all previous fields are the same, but for this field, personB
 *         is greater (e.g. "John" > "Smith")
 * @remark strncmp() is used for producing the result of string field
 * comparisons
 * @remark personA->age – personB->age is used for producing the result of age
 * comparison
 */
int person_compare(const void* personA, const void* personB);

/**
 * @brief  Frees the memory allocated for the person.
 * @param  person [IN] pointer to the person
 */
void free_person(Person* person);

/**
 * Prompts the user for a person, i.e. prompts for each of the required fields.
 *
 * @return the person object created based on the user's input
 */
Person* prompt_user_for_person(void);

/**
 * @brief  Returns a string representation of the person.
 * @param  person [IN] const reference to the person
 * @return a string representation of the person
 */
char* person_to_string(const Person* person);

#endif  // PERSON_H
