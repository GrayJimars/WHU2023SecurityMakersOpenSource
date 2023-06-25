#include <stdio.h>
#include <string.h>
//#include "run.h"

int main()
{
	const char *name_program = "./program";
	const char *name_in = "./in.txt";
	const char *name_out = "./out.txt";
	const char *name_right = "./right.txt";
	run(name_program, name_in, name_out);
	FILE *fpright = fopen(name_right, "r");
	FILE *fpout = fopen(name_out, "r");

    char right, out;
    int accept = 1;
    while(1){
        right = getc(fpright);
        out = getc(fpout);
        if(right == EOF || out == EOF){
            break;
        }
        if(right != out){
            accept = 0;
            break;
        }
    }
    
    if(right != EOF){
        if(right != '\n' || getc(fpright) != EOF){
            accept = 0;
        }
    }
    if(out != EOF){
        if(out != '\n' || getc(fpout) != EOF){
            accept = 0;
        }
    }
    
    if(accept){
        printf("Accept");
    }else{
        printf("Wrong Answer");
    }

	fclose(fpout);
	fclose(fpright);
	return 0;
}
