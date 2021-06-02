#include <stdio.h>
#include <string.h>

int main (){
	FILE *fPtr ;
	char title[21], author[15], yorno ;
	int i , year, flag ;
	
	fPtr = fopen("songlist.txt", "r") ;
	if ((fPtr) == NULL ){
		printf("songlist.txt created\n") ;
		fPtr = fopen("songlist.txt", "w+") ;
//		fclose(fPtr) ;
	} else { 
		fclose(fPtr) ;
		fPtr = fopen("songlist.txt", "a") ;
		for (i = getc(fPtr); i != EOF; i = getc(fPtr))
        if (i == '\n') 
            i++ ;
	}
	while ( 1 ){
		printf("Insert song title: ") ;
		fgets(title,21,stdin);
		printf("Insert author: ") ;
		fgets(author,15,stdin);
		printf("Insert song year: ");
		scanf("%d", &year) ;
		
		i ++ ;
		fprintf(fPtr, "%d,%s,%s,%d\n", i, title, author, year );
		while(1){
			printf("Do you want to insert another song? (y/n): ") ;
			scanf("%c", &yorno) ;
			scanf("%c", &yorno) ;
			if ( yorno == 'Y' || yorno == 'y') {
				printf("\n") ;
				flag = 1 ;
			} else if ( yorno == 'N' || yorno == 'n'){
				flag = 0 ;
				printf("Program quit") ;
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

