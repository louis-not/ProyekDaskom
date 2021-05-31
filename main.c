#include <stdio.h>
#include <string.h>

int main (){

	int input;
	char yorno,*playlist_name = "myPlaylist_X";
	
	printf("--------------Playlist Maker--------------\n");
	while (1){
		input = 0 ;
		printf("\nMenu:\n1. Make a playlist\n2. Show available song\n3. Add song\n4. About\n5. Exit");
		printf("\n\nYour option:") ;
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
						playlist_name = "myPlaylist_A" ;
						break;	
					}
					else if (input == 2) {
						playlist_name = "myPlaylist_B" ;
						break ;
					}
					else if (input == 3) {
						playlist_name = "myPlaylist_C" ;
						break ;
					}
					else{
						printf("Wrong input,Please make sure your input is between 0 to 3\nYour option:") ;
						scanf("%d", &input) ;
					} 
				}
				printf("%s\n", playlist_name) ; // for checking only
				printf("\nDISPLAY PLAYLIST\n") ; //replace with function
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
							printf("ADD SONG\n"); // insert function here
							printf("\nDISPLAY PLAYLIST\n") ; //replace with function
						} else if ( input == 2){
							printf("REMOVE SONG\n"); // insert function here
							printf("\nDISPLAY PLAYLIST\n") ; //replace with function
						}
						break ;						
					} else if ( input == 2){
						printf("Are you sure you want to delete this Playlist? (y/n)\n") ;
						scanf("%d",&input);
						scanf("%c", &yorno) ;
							if ( yorno == 'Y' || yorno == 'y'){
								printf("DELETE MEMORY for %s\n", playlist_name); //replace with function
								break ;
							} else if ( yorno == 'N' || yorno == 'n') {
								break;
							}
					} else 	printf("Wrong input,Please make sure your input is between 0 to 3") ;
				}
				break ;
			case 2:
				printf("Triggered 2\n");
				break ;				
			case 3:
				printf("Triggered 3\n");
				break ;
			case 4:
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
