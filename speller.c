
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.c"
#include "dictionary.h"
#define DICTIONARY_H


// remove non-alphabetic characters and convert to lower case
void trimWord(char *word) {
  int k = 0;
  for (int i = 0; i < (int) strlen(word); i++) {
    if (isalpha(word[i])) {
      word[k] = tolower(word[i]);
      k++;
    }
  }
  word[k] = '\0';
}

int isSymbol(char c){
  if ((c=='.') || (c==',') || (c=='\'') || (c=='-') || (c=='\"') || (c==':') || (c==';') || (c=='!') || (c=='?') || (c=='!') || (c=='(') || (c==')')){
    return 0;
  }
  return 1;
}

int addToWord(char c, char *word, int len){
  word[len] = c; 
  len++;

  return len;
}

int main(int argc, char *argv[]) {
  char word[LENGTH + 1] = "";

  //read in the dictionary
  dict *dictionary = newEmptyDict();
  while (scanf("%45s",word) && word[0] != '!') {
    trimWord(word);
    addWord(word,dictionary);
  }

  int counter = 0; // number of unknown words

  
  //int index = 0;
  int c = EOF;
  int wordLen=0;

  while ((c = getchar()) && c != EOF) {
    if (isSymbol(c)==1){
      if (!check(word, dictionary)){
        counter++;
        printf("%s\n",word);
        //free(word);
      }
    }else{
      wordLen = addToWord(c, word, wordLen);
      printf("%s\n", word);
    }

  }

  //print number of unknown words
  printf("%d\n", counter);

  freeDict(dictionary);
  return 0;
}
