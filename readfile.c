#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2,
  YEARS_LEFT_AND_NAME = 3
} Mode;

typedef struct {
  char first_name[30]; //defined the structure 
  char last_name[30];
  char major[30];
  int  year;
  int  years_left;
} Student;

void print_student(Mode m, Student s) { 
  switch (m) {
    case NAME_ONLY:
      printf("%s %s\n", s.first_name, s.last_name); 
    break;
	case MAJOR_AND_NAME:
	  printf("%s %s %s\n",s.major, s.first_name, s.last_name);
	break;
	case YEAR_AND_NAME:
	  printf("%d %s %s\n",s.year, s.first_name, s.last_name);
	break;
	case YEARS_LEFT_AND_NAME:
	  printf("%d %s %s\n",s.years_left, s.first_name, s.last_name);
	break;
  }
}
int main ( int argc, char *argv[] )
{
    if ( argc != 2 ) //there should be two arguments only
    {
        printf( "insert filename!" );
    }
    else
    {
    FILE *fp = fopen(argv[1], "r");		
		Student s[256];
        char buffer[256];
        char *stru;
        int x = 0;
        int ind;
	int m;
        while (fgets(buffer,255,fp)) {
                printf("%s",buffer); //start from beginning of buffer

                stru = strtok(buffer," "); //reads from buffer to initial space
                strcpy(s[x].first_name,stru); //records as first name
                stru = strtok(NULL," "); //continues to read to the next space
                strcpy(s[x].last_name,stru);
                stru = strtok(NULL," ");
                strcpy(s[x].major,stru);
                stru = strtok(NULL,"\n"); //reads up to newline
                s[x].year = atoi(stru);
                x++; //repeat
                }
			printf("\nIndex of Student?");
			scanf("%d", &ind);
			printf("Mode?");
			scanf("%d", &m);
			print_student(m,s[ind]);	
        fclose(fp);      
	}
	return(0);
			
}
