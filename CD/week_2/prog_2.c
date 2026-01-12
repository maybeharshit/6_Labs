#include <stdio.h>
        

int main()
{
	FILE*   fpread  = fopen("file_1.c", "r");
        FILE*   fpwrite = fopen("file_2.c", "w");

        char c = getc(fpread);

        while(c != EOF)
        {
                if(c == '#')
                {
                        while(c != '\n') c = getc(fpread);
                        c = getc(fpread);
                        continue;
                }
                putc(c, fpwrite);
                c = getc(fpread);
        }

        fclose(fpread);
        fclose(fpwrite);

}


