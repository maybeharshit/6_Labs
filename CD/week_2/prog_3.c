#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 2000

void removekeywords(char* buffer,char** KEYWORDS)
{
        int     j       = 0;
        int     count   = 0;
        char    words[SIZE][SIZE];

        printf("Working\n");
        for (int i = 0; i <= (strlen(buffer)); i++) 
        {
                if (buffer[i] == ' ' || buffer[i] == '\0')
                {
                        words[count][j] = '\0'; 
                        count++;
                        j = 0; 
                }
                else 
                {
                        words[count][j] = buffer[i]; 
                        j++; 
                }       
        }
        for(int i = 0; i < count; i++)
        {

                for(int j = 0; j < 32; j++)
                {
                        if(strcmp(words[i],KEYWORDS[j]) == 0)
                                        {
                                                printf("%s\n",strupr(words[i]));
                                        }
                }
        }
}

int main()
{
        char* KEYWORDS[] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};

        FILE*   fpread   = fopen("file_3.c","r");
        char    buffer[SIZE];
        int     a        = fread(buffer,sizeof(char),SIZE,fpread);
        if(a < 0)
        {
                perror("Joever");
                return EXIT_FAILURE;
        }
        removekeywords(buffer,KEYWORDS);        
        return 0;
}
