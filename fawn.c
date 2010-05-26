/*    (c) 2010 Jan Dlabal <dlabaljan@gmail.com>                               */
/*                                                                            */
/*     This file is part of Fawn.                                             */
/*                                                                            */
/*     Fawn is free software: you can redistribute it and/or modify           */
/*     it under the terms of the GNU General Public License as published by   */
/*     the Free Software Foundation, either version 3 of the License, or      */
/*     any later version.                                                     */
/*                                                                            */
/*     Fawn is distributed in the hope that it will be useful,                */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of         */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          */
/*     GNU General Public License for more details.                           */
/*                                                                            */
/*     You should have received a copy of the GNU General Public License      */
/*     along with Fawn. If not, see <http://www.gnu.org/licenses/>.           */

/*
  This program is an experimental variation of the "cadavre exquis" surrealist game, but using a computer with a large dictionnary.
  Compile with gcc fawn.c and have fun!

  Lists of nouns, verbs, adjectives and adverbs are taken from the Princeton WordNet dictinonary to which the following license applies:

This software and database is being provided to you, the LICENSEE, by Princeton University under the following license. By obtaining, using and/or copying this software and database, you agree that you have read, understood, and will comply with these terms and conditions.: Permission to use, copy, modify and distribute this software and database and its documentation for any purpose and without fee or royalty is hereby granted, provided that you agree to comply with the following copyright notice and statements, including the disclaimer, and that the same appear on ALL copies of the software, database and documentation, including modifications that you make for internal use or for distribution. WordNet 3.0 Copyright 2006 by Princeton University. All rights reserved. THIS SOFTWARE AND DATABASE IS PROVIDED "AS IS" AND PRINCETON UNIVERSITY MAKES NO REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED. BY WAY OF EXAMPLE, BUT NOT LIMITATION, PRINCETON UNIVERSITY MAKES NO REPRESENTATIONS OR WARRANTIES OF MERCHANT- ABILITY OR FITNESS FOR ANY PARTICULAR PURPOSE OR THAT THE USE OF THE LICENSED SOFTWARE, DATABASE OR DOCUMENTATION WILL NOT INFRINGE ANY THIRD PARTY PATENTS, COPYRIGHTS, TRADEMARKS OR OTHER RIGHTS. The name of Princeton University or Princeton may not be used in advertising or publicity pertaining to distribution of the software and/or database. Title to copyright in this software, database and any associated documentation shall at all times remain with Princeton University and LICENSEE agrees to preserve same.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
  Generate these with awk 'END { print NR }' and the fawn.* files
 */
#define ADVS 4510
#define ADJS 21508
#define VERBS 11558
#define NOUNS 117827

#define BUF_LEN 64

#define error(str) printf(str);exit(1)


void usage()
{
  printf("Usage : fawn [COUNT] WORD_TYPE_1 WORD_TYPE_2 ... WORD_TYPE_N\n  Where COUNT is an optional argument specifying how many sentences to generate and WORD_TYPE is one of : n v b a for noun, verb, adverb and adjective respectively.\nFawn will then print a sentence obeying the model given.\n\nCurrently the engine is extremely limited, so do not expect this to yield correct sentences every time and for every model. A recommended example model is n b v n (adjectives need more work).\n");
}


void clean(char *s)
{
  s[strlen(s)-1] = 0;
  unsigned int i = 0;
  for (; i < strlen(s); i++)
  {
    if (s[i] == '_')
      s[i] = ' ';
  }
}


int main(int argc, char *argv[])
{
  srand(time(NULL));
  if (argc < 2)
  {
    usage();
    return 1;
  }
  char start = 1;
  unsigned int loop = 1;
  if (isdigit(argv[1][0]))
  {
    loop = atoi(argv[1]);
    start++;
  }
  unsigned int m = 0;
  for (; m < loop; m++)
  {
    unsigned int i = start, j;
    unsigned int random;
    char buf[BUF_LEN];
    FILE *fr;
    for (; i<argc; i++)
    {
      switch (argv[i][0])
      {
      case 'n':
	random = rand() % NOUNS;
	fr = fopen("fawn.nouns","r");
	if (!fr)
	  exit(2);
	for (j = 0; j < random; j++)
	{
	  fgets(buf,64,fr);
	}
	clean(buf);
	printf("%s %s%c",i==start ? "The" : "the",buf,argc==i+1 ? '.' : ' ');
	fclose(fr);
	break;

      case 'v':
	random = rand() % VERBS;
	fr = fopen("fawn.verbs","r");
	if (!fr)
	  exit(2);
	for (j = 0; j < random; j++)
	{
	  fgets(buf,64,fr);
	}
	clean(buf);
	char mwords = 0;
	for (j = 0; j < strlen(buf); j++)
	{
	  if (buf[j]!=' ')
	    printf("%c",buf[j]);
	  else
	  {
	    mwords = 1;
	    if (buf[j-1]=='e')
	      printf("d ");
	    else
	      printf("ed ");
	  }
	}
	if (!mwords)
	{
	  if (buf[j-1]=='e')
	    printf("d");
	  else
	    printf("ed");
	}
	printf("%c",argc==i+1 ? '.' : ' ');
	fclose(fr);
	break;

      case 'b':
	random = rand() % ADVS;
	fr = fopen("fawn.advs","r");
	if (!fr)
	  exit(2);
	for (j = 0; j < random; j++)
	{
	  fgets(buf,64,fr);
	}
	clean(buf);
	printf("%s%c",buf,argc==i+1 ? '.' : ' ');
	fclose(fr);
	break;

      case 'a':
	random = rand() % ADJS;
	fr = fopen("fawn.adjs","r");
	if (!fr)
	  exit(2);
	for (j = 0; j < random; j++)
	{
	  fgets(buf,64,fr);
	}
	clean(buf);
	printf("%s%c",buf,argc==i+1 ? '.' : ' ');
	fclose(fr);
	break;

      default:
	printf("\nError : %c is not a valid word type.\n",argv[i][0]);
	return 3;
	break;
      }
    }
    printf("\n");
  }
  return 0;
}
