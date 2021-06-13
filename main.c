#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char title[100];
	char author[100];
	int year;
}Song;

void DisplayTable(char*) ;
int addSong(char*) ;
void addplaylist(char*) ;
void removeplaylist(char *) ;

int main (){

	int input;
	char yorno, *filename;
	FILE *fp;

	while (1){
		input = 0 ;
		printf("--------------Playlist Maker--------------\n\n");
		printf("Menu:\n1. Make a playlist\n2. Show available song\n3. Add song\n4. About\n5. Exit");
		printf("\n\nYour option: ") ;
		scanf("%d", &input) ;
		switch (input) {
			case 1:
				input = 0 ;
				printf("\n------------------------------------------\n");
				printf("Available Playlist:\n1. myPlaylist A\n2. myPlaylist B\n3. myPlaylist C\n");
				printf("\nChoose a playlist:");
				scanf("%d", &input) ;
				system("cls") ;
				while (1){
					if ( input == 1) {
						filename = "myPlaylist_A.txt" ;
						break;	
					}
					else if (input == 2) {
						filename = "myPlaylist_B.txt" ;
						break ;
					}
					else if (input == 3) {
						filename = "myPlaylist_C.txt" ;
						break ;
					}
					else{
						printf("Wrong input,Please make sure your input is between 0 to 3\nYour option:") ;
						scanf("%d", &input) ;
					} 
				}
				printf("Opening %s\n\n", filename) ;
				DisplayTable(filename) ;
				fp = fopen(filename,"r") ;
				printf("\n------------------------------------------\n") ;
				printf("1. Edit Playlist\n2. Delete Playlist\n3. Cancel");
				printf("\n\nYour option:");
				input = 0 ;
				scanf("%d", &input) ;
				while (1){
					if ( input == 1){
						printf("\n1. Add Song\n2. Remove song\n3. Cancel\n\nYour option: ") ;
						input = 0 ;
						scanf("%d", &input) ;
						if ( input == 1){
							system("cls");
//								printf("ADD SONG\n"); 
							
							do{
								addplaylist(filename) ;
								// insert function here
								printf("Add another song? (y/n): ") ;
								scanf(" %c", &yorno) ;
								system("cls");
								if ( yorno == 'Y' || yorno == 'y') continue ;
								else if ( yorno == 'N' || yorno == 'n') {
								fclose(fp) ;
								break ;
								}
							} while ( 1 ) ;

						} else if ( input == 2){
							do{
								system("cls");
								DisplayTable(filename) ;
//								printf("REMOVE SONG\n"); // insert function here
								removeplaylist(filename) ;
								printf("\nRemove another song? (y/n): ") ;
								scanf("%d",&input) ;
								scanf("%c", &yorno) ;
							if ( yorno == 'Y' || yorno == 'y') continue ;
							else if ( yorno == 'N' || yorno == 'n'){
								system("cls") ;
								fclose(fp) ;
								break ;
								}
							} while ( 1 ) ;
						}else if ( input == 3){
							system ("cls") ;
							fclose(fp) ;
							break ;
						}
						break ;						
					} else if ( input == 2){
						printf("Are you sure you want to delete this Playlist? (y/n)\n") ;
						scanf("%d",&input);
						scanf("%c",&yorno) ;
							if ( yorno == 'Y' || yorno == 'y'){
								fclose(fp) ;
								fp = fopen(filename,"w") ;
								fclose(fp) ;
								fp = fopen(filename,"r") ;
								printf("DELETE MEMORY for %s\n", filename); //replace with function
								system("cls") ;
								break ;
							} else if ( yorno == 'N' || yorno == 'n') {
								system("cls") ;
								break;
							}
					} else if ( input == 3){
						system ("cls") ;
						fclose(fp) ;
						break ;
					} else 	printf("Wrong input,Please make sure your input is between 0 to 3") ;
				} 
				break ;
			case 2:
				system("cls") ;
				printf("Your Songs:\n");
				printf("\n") ;
				filename = "songlist.txt";
				DisplayTable(filename) ;
//				printf("Play a song?\n") ;
				printf("\n") ;
				break ;				
			case 3:
				system("cls");
				filename = "songlist.txt" ;
				while ( addSong(filename)) ;
				break ;
			case 4:
				system("cls") ;
				printf("-------------- Kelompok Oreo -------------\n");
				printf("This program is made by:\n1.Louis Mayco Dillon Wijaya \t/ 1906379296\n2.Raihan Muhammad Syahran \t/ 1906379301\n3.Verel Sormin \t\t\t/ 1906379333\n") ;
				break ;
			case 5:
				printf("GoodBye!\n") ;
				return 0 ;
			default:
				printf("\nWrong Input\n") ;
				printf("Please make sure your input range between 0 to 5\n\n");
		}
	}
	return 0 ;
}

void DisplayTable(char *filename){
    FILE *fp = fopen(filename, "r");
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
        perror(filename);
    }       
}   

int addSong (char *filename){
	FILE *fPtr ;
	Song input ;
	char yorno ;
	int i=0 , flag ;
	
	fPtr = fopen(filename, "r") ;
	if ((fPtr) == NULL ){
		printf("songlist.txt created\n") ;
		fPtr = fopen("songlist.txt", "w+") ;
//		fclose(fPtr) ;
	} else { 
		for (yorno = getc(fPtr); yorno != EOF; yorno = getc(fPtr)){
		    if (yorno == '\n') 
            i++ ;
//			printf("%d\n",i);	
		}
		fclose(fPtr) ;
		fPtr = fopen("songlist.txt", "a") ;
	}
	while ( 1 ){
		printf("Insert song title: ") ;
		scanf("\n");
		scanf("%[^\n]%*c", input.title) ;
		printf("Insert author: ") ;
		scanf("\n");
		scanf("%[^\n]%*c", input.author) ;
		printf("Insert song year: ");
		scanf("%d", &input.year) ;
//		i++ ;
//		printf("%d,%s,%s,%d\n", i+1, title, author, year );
		fprintf(fPtr, "%d,%s,%s,%d\n", i+1, input.title, input.author, input.year );
		while(1){
			printf("Do you want to insert another song? (y/n): ") ;
			scanf("%c", &yorno) ;
			scanf("%c", &yorno) ;
			if ( yorno == 'Y' || yorno == 'y') {
				printf("\n") ;
				flag = 1 ;
			} else if ( yorno == 'N' || yorno == 'n'){
				flag = 0 ;
				system("cls") ;
//				printf("Program quit") ;
				fclose(fPtr) ;
				return 0 ;
			} else {
				flag = 0;
				printf("invalid input");
				continue;
			}
			if (flag == 1) break ;		
		}
	}
	fclose(fPtr) ;
	return 0 ;
}

void addplaylist (char *filename){
	FILE *fp = fopen("songlist.txt", "r");
	int i,a,cond = 0,comp = 0,max,songID,songtitlebefore,songtitlemax;;
    char testi[100],singer[100], *token,buf[100];
    const char s[2] = ",";
    Song songlist[15];
	while(fgets(buf, sizeof buf, fp) != NULL) 
	{
	comp++;
	}
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
                	strcpy(songlist[i].title, token);
                	token = strtok(NULL,s);
				}
				else if (a == 2)
                {   
                	strcpy(songlist[i].author, token);
                   	token = strtok(NULL,s);
               	}       
                else if (a == 3)
                {
                	songlist[i].year = atoi(token);
                	token = strtok(NULL,s);
				}
				else
				{
					token = strtok(NULL,s);
				}
            }
		}
	}
	max = comp;
	fclose(fp);
	comp = 0;
	fp = fopen(filename, "r");
    Song songtitle[5];
 	while(fgets(buf, sizeof buf, fp) != NULL) 
	{
	comp++;
	}
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
	songtitlemax = comp;
	fclose(fp); 

	char yorno;
	system("cls") ;
	if (songtitlemax == 5) 
	{
		printf("Maximum storage exceeded for this playlist,\nplease make room by removing a song\n\n");
	}
	else
	{
		printf("song from your memory: \n");
		DisplayTable("songlist.txt") ;

		printf("Which song do you want to add into your playlist?(input songlist number) : ");
		scanf("%d", &songID);
		
		if (songID > 0 && songID < max) 
		{
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
			fp = fopen(filename, "w");
			for (i = 0; i < songtitlemax ;i++)
			{
			fprintf(fp,"%d,%s,%s,%d\n",i+1,songtitle[i].title,songtitle[i].author,songtitle[i].year,i);
			}
			fclose(fp);
			printf("\n\nCurrent Song After Editing :\n\n");
			DisplayTable(filename);
		}
		else printf("\n\nSong Number Doesn't Exist!\n");
	}

}

void removeplaylist( char *filename){
	FILE *fp = fopen(filename, "r");
	int i,a,max,remove;
    char *token,buf[100],comp[100]; 
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
	printf("\nSelect which song that you want to remove(by number): ");
	scanf("%d",&remove);
	if (remove > 0 && remove < max)
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
	else if (remove > max  || remove < 0 ) printf("\n\nSong Number Doesn't Exist!\n");
	printf("\nCurrent Song After Editing \n\n");
	fp = fopen(filename, "w");
	for (i = 0; i < max ;i++)
	{
		fprintf(fp,"%d,%s,%s,%d\n",i+1,songtitle[i].title,songtitle[i].author,songtitle[i].year,i);
	}
	fclose(fp);
	DisplayTable(filename);
//	printf("Input All of the Playlist into %s\n", filename);
//	printf("\nClose %s\n", filename);

}



