#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char const *argv[]){
	FILE *file;
	int a,i,kounter=0;
	char buf[1000];
	
	file = fopen("Playlist_Spreadsheet.csv", "r+");

	printf("Pilih Playlist yang ingin diisi \nPlaylist_A(input1)\nPlaylist_B(input2)\nPlaylist_C(input3) : ");
	scanf("%d",&a);
	printf("\n\n");
	while (fgets(buf,1000,file) != NULL){
		char *token = strtok(buf, ";");
		for (i = 1; i < a; i++) token = strtok(NULL, ";");	//'\0' 
		if (kounter == 0) printf("%s\n\n",token);
		else {
			printf(" %s \n", token);
		}
		kounter++;
	}
	
 	//while( fgets ( buf, 50, file ) != NULL )
    // Keep printing tokens while one of the
    // delimiters present in str[].
        printf("\nClosing the file Playlist_Spreadsheet.csv ") ;
        fclose(file) ;
        return 0;
}

