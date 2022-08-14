/**
 * @file StringFunctions.h
 * @author Yusuf Savaş (yusufsss4@gmail.com)
 * @brief String Functions
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef STRING_FUNC_H
#define STRING_FUNC_H

/**
 * @brief Find the frequency of characters in a string that you searched.
 * 
 * @param str 
 * @param searchCharacter 
 * @return int 
 */
int numberOfCharactersInString(char *str, char searchCharacter);

/**
 * @brief Remove all the characters in a String except Alphabets
 * 
 * @param source 
 * @return int 
 */
int removeNonAlphaCharacters(char *source);


/**
 * @brief Calculate the length of a string without using strlen
 * 
 * @param source 
 * @return int 
 */
int lengthOfString(char *source);

/**
 * @brief Concatenate two strings without using strcat
 * 
 * @param str1 
 * @param str2 
 * @return char* 
 */
char* strConcat(char *str1, char *str2);


/**
 * @brief Copy a string manually without using strcpy
 * 
 * @param source 
 * @param destination 
 * @return int 
 */
int strCopy(char **source, char* *destination);

/**
 * @brief Find the substring of a given string
 * 
 * @param source 
 * @param from 
 * @param n 
 * @param target 
 * @return int 
 */
int substring(char *source, int from, int n, char *target);


#endif