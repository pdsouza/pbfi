/*
 *    Copyright (C) 2013 Preetam D'Souza
 *
 *    This program is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU General Public License
 *    as published by the Free Software Foundation; either version 2
 *    of the License, or (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 *    Email: preetamjdsouza@gmail.com (why you would contact me for this I have no idea)
 */

#include <stdio.h>
#define ARRAY_SIZE 30000
#define STACK_SIZE 10

char a[ARRAY_SIZE] =   {[0 ... ARRAY_SIZE-1] = 0};     /* data */
long jmp[STACK_SIZE] = {[0 ... STACK_SIZE-1] = 0};     /* jmp stack */
char *dp = a;                                          /* data ptr */
int jp = 0;                                            /* jmp ptr */

int main(int argc, char **argv) {
    FILE *fin = stdin;
    int c, br;
    char d;       
     
    if(argc > 1) fin = fopen(argv[1], "r");
    
    while((c = getc(fin)) != EOF) {
        switch(c) {
            case '>': ++dp; break;
            case '<': --dp; break;
            case '+': ++*dp; break;
            case '-': --*dp; break;
            case '.': putchar(*dp); break;
            case ',': while((*dp = getchar()) == '\n'); 
                //printf("Got a char: %c %#x\n", *dp, *dp); 
                break;
            case '[':
                //printf("Saved jmp: %d\n", cmd[jp-1]);
                if(!*dp) {
                    br = 1; 
                    while(br && (d = getc(fin)) != EOF) {
                        if(d == ']') --br;
                        else if(d == '[') ++br;
                    }
                    if(br) goto error;
                }
                else jmp[jp++] = ftell(fin); // save jmp point
                break;
            case ']':
                if(!jp) goto error;
                if(*dp) fseek(fin, jmp[jp-1], SEEK_SET);
                else --jp; 
                break;

            /* ignore anything else */
            default : break;
        }
        //if(c != '\n' && c != ' ')
          //printf("DEBUG | c: %c dp: %d *dp: %#x\n", c, dp, *dp);
    }

    fclose(fin);
    return 0;

    error:
        printf("Error: fix your braces!\n");
        return -1;
}
