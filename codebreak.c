#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int need_space_int(int i)
{
  if (!i)
    return 1;

  unsigned int j=1;
  int space = 1;
  while (j<=abs(i))
  {
    space++;
    j*=10;
  }
  return space;
}


int main(int argc, char *argv[])
{
  srand(time(NULL));
  printf("Welcome to CodeBreak (http://houbysoft.com/en/downprog.php#codebreak).\n");
  int min = 1000;
  int max = 10000;
  int deduceme;
  char *deducestr;
  char *statusstr;
  while (1)
  {
    deduceme = rand() % (max - min) + min;
    deducestr = malloc(need_space_int(deduceme)+1);
    statusstr = malloc(need_space_int(deduceme)+1);
    if (!deducestr || !statusstr)
    {
      printf("Error : cannot allocate enough memory. Something is probably very wrong; closing.\n");
      exit(1);
    }
    sprintf(deducestr,"%i",deduceme);
    int i=0;
    char digits[10];
    memset(&digits, 0, 10);
    for (; i<strlen(deducestr); i++)
    {
      if (digits[deducestr[i]-48]==1)
      {
	free(deducestr);
	free(statusstr);
	deduceme = 0;
	break;
      }
      else
	digits[deducestr[i]-48]=1;
    }
    if (deduceme == 0)
      continue;
    else
      break;
  }
  sprintf(statusstr,"");
  int tries_remain = 12;
  int guess = -1;
  while (tries_remain)
  {
    printf("[%s] (%i %s)\n\n",statusstr,tries_remain,tries_remain == 1 ? "try remains" : "tries remain");
    char *guessstr = malloc(need_space_int(max)+1);
    if (!guessstr)
    {
      printf("Error : cannot allocate enough memory. Something is probably very wrong; closing.\n");
      exit(1);
    }
    char first = 1;
    guess = -1;
    while (!(guess >= min && guess < max))
    {
      if (!first)
	printf("Wrong format. Your guess needs to be an integer >= %i and < %i.\n",min,max);
      first = 0;
      fgets(guessstr,need_space_int(max)+1,stdin);
      guessstr[need_space_int(max)] = 0;
      if (guessstr[strlen(guessstr)-1]=='\n')
	guessstr[strlen(guessstr)-1]=0;
      guess = atoi(guessstr);
    }
    if (guess == deduceme)
      break;
    else
    {
      int i=0;
      int correct_pos = 0;
      int correct_num = 0;
      for (; i<strlen(guessstr); i++)
      {
	if (strchr(deducestr,guessstr[i]))
	{
	  if ((strchr(deducestr, guessstr[i]) - deducestr) == i)
	  {
	    correct_pos += 1;
	  } else {
	    correct_num += 1;
	  }
	}
      }
      int incorrect = strlen(deducestr) - correct_pos - correct_num;
      strcpy(statusstr,"");
      while (correct_pos--)
	strcat(statusstr,"*");
      while (correct_num--)
	strcat(statusstr,"o");
      while (incorrect--)
	strcat(statusstr,"-");
      free(guessstr);
    }
    tries_remain--;
  }
  if (tries_remain)
  {
    printf("Congratulations; you won. You had %i more %s.\n",tries_remain-1,tries_remain-1 == 1 ? "try" : "tries");
  } else {
    printf("You lost; the answer was %i.\n",deduceme);
  }
  return 0;
}
