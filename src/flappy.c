/**
 * Created by mihaisandor on 2/19/17.
 */
#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>
#include <string.h>
#include "flappy-help.h"

/* If we are compiling on Windows compile these functions */
#ifdef _WIN32

static char buffer[2048];

/* Fake readline function */
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

/* Otherwise include the editline headers */
#else
#endif

int main(int argc, char** argv) {

  if (argc > 1)
  {
    int result = 0;
    result = help(argc, argv);
    return(result);
  }
    printf ("Welcome to FlappyLang version 0.1. Ctrl + C and type flappy -h for assistance.\n");
  while (1) {
    /* Now in either case readline will be correctly defined */
    char* input = readline("Flappy>> ");
    add_history(input);

    //printf("No you're a %s\n", input);
    free(input);
  }

  return 0;
}
