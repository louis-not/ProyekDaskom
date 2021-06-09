#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	char title[100];
	char author[100];
	int year;
	
}Song;


void getdata(char *filename, Song *songg,int *max);

int main(){
	int i,max,songID,songtitlebefore,songtitlemax;
    Song songlist[15];
    Song songtitle[5];
    char *filename;
	char yorno,cond1;

    getdata("songlist.txt", songlist,&max);
    printf("\nRead From Memory!\n\n");
	for (i = 0; i < max ;i++)
	{
		printf("%d\t%s\t%s\t%d\n",i+1,songlist[i].title,songlist[i].author,songlist[i].year);
	}
	
	printf("\nINPUT my_Playlist(A/B/C) in filename HERE!\n");
    filename = "myPlaylist_A.txt";
    printf("\nRead From Playlist!\n\n");
    getdata(filename, songtitle,&songtitlemax);   
	for (i = 0; i < songtitlemax ;i++)
	{
		if (songtitlemax == 1) printf("%d\t%s\t%s\t%d\n",i+1,songtitle[i].title,songtitle[i].author,songtitle[i].year);
		else printf("%d\t%s\t%s\t%d\n",i+1,songtitle[i].title,songtitle[i].author,songtitle[i].year);
		
		
		
	} 
	songtitlebefore = songtitlemax;

	do
	{
		printf("\n\nAdd Song from Memory\n");
		printf("Take a Look at your current myPlaylist and our memory created for you!\n");
		printf("Which song do you want to add into your playlist?(input songlist number) : ");
		scanf("%d", &songID);

		printf("You Choose %s to add to your playlist\n",songlist[songID-1].title);
		printf("Continue ? (y/n) : ");
		scanf(" %c", &yorno);
		if (yorno == 'y' || yorno == 'Y') 
		{	
			strcpy(songtitle[songtitlemax].title,songlist[songID-1].title) ;
			strcpy(songtitle[songtitlemax].author,songlist[songID-1].author);
			songtitle[songtitlemax].year = songlist[songID-1].year ;
			songtitlemax++;
		}

		printf("\n\nCurrent Playlist\n\n");	
		for (i = 0; i < songtitlemax ;i++)
		{
			printf("%d\t%s\t%s\t%d\n",i+1,songtitle[i].title,songtitle[i].author,songtitle[i].year);
		} 

		printf("Continue ? (y/n) : ");
		scanf(" %c", &yorno);		
		if (songtitlemax == 5) 
		{
			printf("Maximum Playlist Song Detected"); 
			break;
		}
	} 	while (yorno == 'y' || yorno == 'Y');
	
	printf("\nInput All of the Playlist into file.txt\n");
	FILE *fp = fopen(filename, "w"); // kalo 'a' filenya jadi kedouble2 ntar isinya
	for (i = songtitlebefore; i < songtitlemax ;i++)
	{
		fprintf(fp,"%d,%s,%s,%d\n",i+1,songtitle[i].title,songtitle[i].author,songtitle[i].year,i);
	}
	printf("\nClose The Filename.txt");
	fclose(fp);
	
	return 0;
}


void getdata(char *filename, Song *songg,int *max)
{
	FILE *fp = fopen(filename, "r");
	int i,year,a,cond = 0,remove,comp = 0;
    char testi[100],singer[100], *token,buf[100];
    const char s[2] = ",";
   
	while(fgets(buf, sizeof buf, fp) != NULL) 
	{
	comp++;
	}
	if (comp == 0) printf("Empty Playlist Detected!");
	rewind(fp);

	for (i = 0; i <comp  ; i++ )
	{
		fgets(buf, sizeof buf, fp);
		{
			token = strtok(buf, s);
           	for(a=0;a<4;a++)
        	{
            	if (a == 1)
                {
                	strcpy(songg[i].title, token);
                	token = strtok(NULL,s);
				}
				else if (a == 2)
                {   
                	strcpy(songg[i].author, token);
                   	token = strtok(NULL,s);
               	}       
                else if (a == 3)
                {
                	songg[i].year = atoi(token);
                	token = strtok(NULL,s);
				}
				else
				{
					token = strtok(NULL,s);
				}
            }
		}
	}
	*max = comp;
	fclose(fp);
}



