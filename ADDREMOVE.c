#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	char title[100];
	char author[100];
	int year;
	
}Song;
int main(){
	FILE *fp = fopen("song.txt", "r+");
	int i ,kounter = 0,year,a,cond = 0,max,remove;
    char testi[100],author[100], *token,buf[100],comp[100];
    const char s[2] = ",";
    
    Song songtitle[5];
    
    while(fgets(buf, sizeof buf, fp) != NULL)
    {
    	token = strtok(buf, s);
        strcpy(comp,token);
        token = strtok(NULL,s);
	}
	rewind(fp);
	for (i = 0; i < atoi(comp); i++ )
	{
		fgets(buf, sizeof buf, fp);
		{
			token = strtok(buf, s);
            for(a=0;a<4;a++)
            {
                if (a == 1)
                {
                	strcpy(songtitle[i].title, token);
                	token = strtok(NULL,s);
				}
				else if (a == 2)
                {   
                    strcpy(songtitle[i].author, token);
                    token = strtok(NULL,s);
                }       
                else if (a == 3)
                {
                	songtitle[i].year = atoi(token);
                	token = strtok(NULL,s);
				}
				else
				{
					token = strtok(NULL,s);
				}
            }
		}
	}
	fclose(fp);
	max = i;
	
	printf("Select Choices (1)ADD, (2)REMOVE :");
	scanf("%d", &cond);
	getchar();
	while (i != 0)
	{
		if (cond == 1)
		{
			printf("Add Song Title : ");
			fgets(testi,100,stdin);
			strcpy(songtitle[i].title, testi);
		
			printf("Add Song Author : ");
			fgets(author,100,stdin);
			strcpy(songtitle[i].author,author);
		
			printf("Add Song Year : ");
			scanf("%d", &year);
			songtitle[i].year = year;
			max = i;
		}
		else if (cond == 2)
		{
			printf("Current Song in your Playlist :");
			for (i = 0; i < max ;i++)
			{
			printf("\n%d\t%s\t%s\t%d\n",i+1,songtitle[i].title,songtitle[i].author,songtitle[i].year);
			}
			printf("\nSelect which song that you want to remove(enter the song ID),press 0 if you want to change your mind :");
			scanf("%d",&remove);
		
			if (remove > 0)
			{
				remove--;
				for (remove; remove < max; remove++)
				{
					strcpy(songtitle[remove].title,songtitle[remove+1].title);
					strcpy(songtitle[remove].author,songtitle[remove+1].author);
					songtitle[remove].year = songtitle[remove+1].year;
				}
				max--;
				songtitle[max].title[0] = '\0';
				songtitle[max].author[0] = '\0';
				songtitle[max].year = 0;				
			}
			
		}
		printf("Do you want to add/remove another song?");
		scanf("%d",&i);
	}


for (i = 0; i < max ;i++)
	{
		printf("\n%d\t%s\t%s\t%d\n",i+1,songtitle[i].title,songtitle[i].author,songtitle[i].year);
	}


	return 0;
}
