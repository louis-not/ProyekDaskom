#include <stdio.h>
#include <string.h>

void DisplayTable(char*) ;
int addSong(char*) ;
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
				printf("\n\nOpening %s\n\n", filename) ;
				DisplayTable(filename) ;
				fp = fopen(filename,"r") ;
				printf("\n------------------------------------------\n") ;
				printf("1. Edit Playlist\n2. Delete Playlist");
				printf("\n\nYour option:");
				input = 0 ;
				scanf("%d", &input) ;
				while (1){
					if ( input == 1){
						printf("\n1. Add Song\n2. Remove song\n\nYour option: ") ;
						input = 0 ;
						scanf("%d", &input) ;
						if ( input == 1){
							do{
								DisplayTable(filename) ;
								printf("ADD SONG\n"); // insert function here
								
								printf("Add another song? (y/n): ") ;
								scanf("%c", &yorno) ;
								system("cls");
							if ( yorno == 'Y' || yorno == 'y') continue ;
							else if ( yorno == 'N' || yorno == 'n') {
								fclose(fp) ;
								break ;
								}
							} while ( 1 ) ;
						} else if ( input == 2){
							do{
								DisplayTable(filename) ;
								printf("REMOVE SONG\n"); // insert function here
								
								printf("Remove another song? (y/n): ") ;
								scanf("%c", &yorno) ;
								system("cls");
							if ( yorno == 'Y' || yorno == 'y') continue ;
							else if ( yorno == 'N' || yorno == 'n'){
								fclose(fp) ;
								break ;
								}
							} while ( 1 ) ;
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
					} else 	printf("Wrong input,Please make sure your input is between 0 to 3") ;
				}
				break ;
			case 2:
				filename = "songlist.txt";
				DisplayTable(filename) ;
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
				printf("Please make sure your input range between 0 to 4\n\n");
		}
	}
	
	return 0 ;
}

void DisplayTable(char *filename){
    FILE *fp = fopen(filename, "r");
    const char s[2] = ",";
    char *token;
    int i;
    if(fp != NULL)
    {
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

int addSong (char *filename){
	FILE *fPtr ;
	char title[21], author[15], yorno ;
	int i=0 , year, flag ;
	
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
		scanf("%[^\n]%*c", title) ;
		printf("Insert author: ") ;
		scanf("\n");
		scanf("%[^\n]%*c", author) ;
		printf("Insert song year: ");
		scanf("%d", &year) ;
//		i++ ;
//		printf("%d,%s,%s,%d\n", i+1, title, author, year );
		fprintf(fPtr, "%d,%s,%s,%d\n", i+1, title, author, year );
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
	return 0 ;
}
