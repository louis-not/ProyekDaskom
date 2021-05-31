#include <stdio.h>
#include <string.h>

int main (){

	int input;
	char *playlist_name = "myPlaylist_X";
	
	printf("--------------Playlist Maker--------------\n");
	while (1){
		input = 0 ;
		printf("Menu:\n1. Make a playlist\n2. Show available song\n3. Add song\n4. Exit");
		printf("\n\nYour option:") ;
		scanf("%d", &input) ;
		switch (input) {
			case 1:
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
				printf("%s\n", playlist_name) ;
				printf("\nDISPLAY PLAYLIST\n") ; //replace with function
				printf("\n------------------------------------------\n") ;
				printf("1. Edit Playlist\n2. Delete Playlist");
				printf("\n\nYour option:");
				scanf("%d", &input) ;
				switch (input){
					case 1:
						printf("Edit this playlist\n") ;
						break ;
					case 2:
						printf("Are you sure you want to delete this Playlist?\n") ;	
						break ;
					default:
						printf("Wrong input,Please make sure your input is between 0 to 3") ;
						break ;						
				}
				break ;
			case 2:
				printf("Triggered 2\n");
				break ;				
			case 3:
				printf("Triggered 3\n");
				break ;
			case 4:
				printf("Triggered 4\n");
				return 0;
			default:
				printf("\nWrong Input\n") ;
				printf("Please make sure your input range between 0 to 4\n\n");
		}
	}
	
		
	return 0 ;
}
