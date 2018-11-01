#include <stdio.h>  //standard-input-output
#include <stdlib.h> //standard-library
#include <string.h> //string-library

#define cmd_add 1
#define cmd_list_today 2
#define cmd_new_day 3
#define cmd_last_seven_days 4
#define cmd_help 5

typedef struct _day_
{
  char **list_of_food;//char** - liste von strings
  int date;
} day;


//foreward-declarations:
char *read_user_input();

void print_todays_food(day today);

void print_welcome_message();

void print_help_message();

int get_user_command();


int main()
{
  print_welcome_message();
  get_user_command();
  day today;
  today.list_of_food = (char **) malloc(sizeof(char *) * 128);
  if (today.list_of_food == NULL)
  {
    return -1;
  }

  int counter = 0;
  while (counter < 11)
  {
    today.list_of_food[counter] = read_user_input();
    counter++;
  }
  print_todays_food(today);
  return 0;
}

//Function to read input from user
char *read_user_input()
{
  printf("Please enter your food:\n");
  char *input = (char *) malloc(64); //malloc liefert void* => casten auf char*
  if (input == NULL)
  {
    exit(-1); //beendet das Programm -- ̣nicht erlaubt in ESP `\_(o.o)_/`
  }
  fgets(input, 63, stdin);
  return input;
}

void print_todays_food(day today)
{
  for (int i = 0; i < 11; i++)
  {
    printf("%d: %s\n", i, today.list_of_food[i]);
  }
}

void print_welcome_message()
{
  printf("Welcome to the food-manager!\n");
  printf("What would you like to do?\n");
  print_help_message();
}

void print_help_message()
{
  printf("1) add - to add new food\n");
  printf("2) nomnomnom - shows list of already eaten food of the day\n");
  printf("3) new_day - creates a new day for listing new food\n");
  printf("4) list7 - lists the food consumend on the last seven days\n");
  printf("5) help - displays this help message\n");
}

int get_user_command()
{
  while(1)
  {
    char command_input[64]; //shortcut: compiler sollte alle 64 speicherstellen mit 0 füllen (im Stack)
    fgets(command_input, 63, stdin);
    if (strcmp(command_input, "add\n") == 0)
    {
      return cmd_add;
    }
    if (strcmp(command_input, "nomnomnom\n") == 0)
    {
      return cmd_list_today;
    }
    if (strcmp(command_input, "new_day\n") == 0)
    {
      return cmd_new_day;
    }
    if (strcmp(command_input, "list7\n") == 0)
    {
      return cmd_last_seven_days;
    }
    if (strcmp(command_input, "help\n") == 0)
    {
      return cmd_help;
    }
    printf("Your input was not correct. Please try again.\n");
  }
}