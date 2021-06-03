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
    char testi[100],singer[100], *token,buf[100],comp[100];
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
	printf("%d", i);
	
	printf("Select Choices (1)ADD, (2)REMOVE :");
	scanf("%d", &cond);

	while (i != 0)
	{
		if (cond == 1)
		{
			if (max == 5)
			{
				printf("Program Tidak Dapat Menampung Lebih dari 5 Lagu, Tidak dapat menambah lagu");
				printf("\n\nDo you want to add/remove another song? (Press any number to continue, 0 if you're satisfied with your current song now)");
				scanf("%d",&i);
				if (i == 0) break;
				printf("Pilih 1 Untuk Add Lagu, Pilih 2 untuk Remove Lagu :");
				scanf("%d", &cond);				
				continue;
			}
			getchar();			
			printf("Add Song Title : ");
		
			gets(testi);
			strcpy(songtitle[max].title, testi);

			printf("Add Song Author : ");
			gets(singer);
			strcpy(songtitle[max].author, singer);
		
			printf("Add Song Year : ");
			scanf("%d", &year);
			songtitle[max].year = year;
			
			max++;
		}
		else if (cond == 2)
		{
			printf("Current Song in your Playlist :\n");
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
			printf("\nCurrent Song After Editing \n\n");
			for (i = 0; i < max ;i++)
			{
				printf("\n%d\t%s\t%s\t%d\n",i+1,songtitle[i].title,songtitle[i].author,songtitle[i].year);
			}			
		}
		printf("\nDo you want to add/remove another song? (Press any number to continue, 0 if you're satisfied with your current song now)");
		scanf("%d",&i);
		if (i == 0) break;
		printf("Pilih 1 Untuk Add Lagu, Pilih 2 untuk Remove Lagu :");
		scanf("%d", &cond);
	}
	printf("\nCurrent Playlist :\n\n");
	for (i = 0; i < max ;i++)
	{
		printf("%d\t%s\t%s\t%d\n",i+1,songtitle[i].title,songtitle[i].author,songtitle[i].year);
	}
	
	printf("Input All of the Playlist into file.txt\n");
	fp = fopen("song.txt", "w");
	for (i = 0; i < max ;i++)
	{
		fprintf(fp,"%d,%s,%s,%d\n",i+1,songtitle[i].title,songtitle[i].author,songtitle[i].year,i);
	}
	printf("\nClose The Filename.txt");
	fclose(fp);
//1,Wonderland,Michael Bay,2020
//2,The Champions,Your Mom,2020
//3,Great Song,Joe Mama,2020
//4,Somebody,Sugondese,2020
	return 0;
}
