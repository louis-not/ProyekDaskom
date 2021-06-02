#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ";");
            tok && *tok;
            tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}


int main(int argc, char const *argv[]){
	FILE *file;
	int a,i,kounter=0;
	char buf[1000];
	
	file = fopen("Playlist_Spreadsheet.csv", "r");

	printf("Pilih Playlist yang ingin diisi \nPlaylist_A(input1)\nPlaylist_B(input2)\nPlaylist_C(input3) : ");
	scanf("%d",&a);
	printf("\n\n");
	//	for (i = 0; i < a; i++) token = strtok(NULL, ";");	//'\0' 
    while (fgets(buf, 1024, file))
    {
        char* tmp = strdup(buf);
        printf("Field 3 would be %s\n", getfield(tmp, a));
        // NOTE strtok clobbers tmp
        free(tmp);
	}
	
 	//while( fgets ( buf, 50, file ) != NULL )
    // Keep printing tokens while one of the
    // delimiters present in str[].
        printf("\nClosing the file Playlist_Spreadsheet.csv ") ;
        fclose(file) ;
        return 0;
}

