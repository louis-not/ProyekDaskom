#include <stdio.h>
#include <string.h>

void main()
{
    FILE *fp = fopen("songlist.txt", "r");
    const char s[2] = ",";
    char *token;
    int i;
    if(fp != NULL){
        char buf[100];
        printf("No\t");
        printf("Judul Lagu\t");
        printf("Penulis Lagu\t");
        printf("Year\n\n");
        while(fgets(buf, sizeof buf, fp) != NULL)
        {
            token = strtok(buf, s);
            for(i=0;i<4;i++)
            {
					if(i<3)
                {   
                    printf("%s",token);
                    if (strlen(token)<2) {
					printf("\t");
					}
                    else if (strlen(token)<8) {
					printf("\t\t");
					}
					else if (strlen(token)<16) {
					printf("\t");
					}
                    token = strtok(NULL,s);
                }
					else {
                    printf("%s\n",token);
                    token = strtok(NULL,s);
                }       
            }
        }
        fclose(fp);
    } else {
        perror("songlist.txt");
    }   
}   
