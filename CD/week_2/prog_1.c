#include <stdio.h>


int main()
{

        FILE*   fpread  = fopen("file_1.txt","r");
        FILE*   fpwrite = fopen("file_1_processed.txt","w");
        char    c       = getc(fpread);

        while(c != EOF)
        {
                if(c == ' ')
                {
                        putc(c, fpwrite);
                        while(c == ' ') c = getc(fpread);
                }
                putc(c, fpwrite);
                c = getc(fpread);
        }

        fclose(fpread);
        fclose(fpwrite);

        return 0;

}

