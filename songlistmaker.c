#include <stdio.h>
#include <string.h>

int main (){
	FILE *fPtr ;
	char title[21], author[15], yorno ;
	int i=0 , year, flag ;
	
	fPtr = fopen("songlist.txt", "r") ;
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
		printf("%d\t%s\t\t%s\t\t%d\n", i+1, title, author, year );
		fprintf(fPtr, "%d\t%s\t\t%s\t\t%d\n", i+1, title, author, year );
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

