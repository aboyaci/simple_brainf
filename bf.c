/*
	Ali Boyaci
	
	Simple brainf interpreter
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODE_SIZE 1000
#define DATA_SIZE 1000

char code[CODE_SIZE];
int  data[DATA_SIZE];

int pc=0;
int dp=0;
int code_len = 0;

int find_forward_matching_bracket()
{
	int i = 0;
	int level = 0;

	for(i=pc+1; i<code_len; i++)
	{
		if (code[i] == '[')
			level++;
		else if (code[i] == ']')
		{
			if (level > 0)
				level--;
			else
				return i;
		}
	}

	return -1;
}

int find_backward_matching_bracket()
{
	int i = 0;
	int level = 0;

	for(i=pc-1; i>=0; i--)
	{
		if (code[i] == ']') 
			level++;
		else if (code[i] == '[') {
			if (level > 0)
				level--;
			else
				return i;
		}
	}

	return -1;
}

int run_bf()
{

	char c;

	while(pc < code_len)
	{
		c = code[pc];

		switch(c)
		{
			case '>': 	++dp; break;
            case '<': 	--dp; break;
            case '+': 	++data[dp]; break;
            case '-': 	--data[dp]; break;
            case '.': 	putchar(data[dp]); break;
            case ',': 	data[dp] = (unsigned char) getchar(); break;
            case '[': 	if(data[dp] == 0)
            				pc = find_forward_matching_bracket();
            			break;
            case ']': 	if(data[dp] != 0)
							pc = find_backward_matching_bracket();
						break;
		}

		if (pc < 0)
		{
			printf("Error matching brackets!\n");
			return -1;
		}

		pc++;
	}

	return 0;
}

int main(int argc, char** args)
{
	FILE *f;

	if (argc != 2)
	{
		fprintf (stderr, "usage: %s file\n", args[0]);

		return EXIT_FAILURE;
	}
	
	f = fopen(args[1], "r");

	if (f == NULL)
	{
		fprintf (stderr, "file %s is not valid\n", args[1]);

		return EXIT_FAILURE;
	}	

	memset(code, 0, sizeof(char)*CODE_SIZE);
	memset(data, 0, sizeof(int)*DATA_SIZE);

	code_len = fread(code, 1, CODE_SIZE, f);

	fclose(f);

	return run_bf();
}