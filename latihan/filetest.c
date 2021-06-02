#include <stdio.h>

int main (){
	FILE *fPtr ;
	char title[10], author[10], yorno ;
	int i = 0, year, flag ;
	
	fPtr = fopen("songlist.txt", "r") ;
	if ((fPtr) == NULL ){
		printf("there is no such file") ;
		fPtr = fopen("songlist.txt", "w+") ;
//		fclose(fPtr) ;
	} else { 
		fclose(fPtr) ;
		fPtr = fopen("songlist.txt", "a") ;
	}
	while ( 1 ){
		printf("Insert song title: ") ;
		scanf("%s", &title) ;
		printf("Insert author: ") ;
		scanf("%s", &author) ;
		printf("Insert song year: ");
		scanf("%d", &year) ;
		i ++ ;
		fprintf(fPtr, "%d \t %s \t\t %s \t\t %d\n", i, title, author, year );
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
