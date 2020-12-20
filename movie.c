#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include <error.h>
#include "movie.h"
#include "functions.h"

int main (){
  Sql sql;

  sql.connection = mysql_init(NULL);
  if(mysql_real_connect
      (sql.connection, "localhost", "root", "", "mydb", 0, NULL,
        0) == NULL)
  {
   printf("connection error.");
  }

  int index;
  while(1){
    printf ("%s:\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
                "\n***Best visibility in full screen terminal***\n\n"
                "Choose option",
                "1. adding new director",
                "2. printing all directors",
                "3. removing director",
                "4. adding new movie",
                "5. printing all movies",
                "6. removing movie",
                "7. adding new actor/actress",
                "8. printing all actors/actresses",
                "9. removing actor/actress",
                "10. adding movie role",
                "11. finding budget of movie",
                "12. filmography of an actor/actress",
                "13. interupt");

      	scanf("%d",&index);
        int id_actor;
        int id_director;
        int id_movie;
        char c;
        int id_movie_helper;

        switch (index) {
        	case 1:
        		addDirector(&sql,&id_director);
            printf("Is he part of a major studio?y/n\n");
            getchar();
            c = getchar();
            if(c == 'y'){
              addEmployed(&sql,id_director);
            }
        		break;
        	case 2:
        		printDirector(&sql,1);
        		break;
          case 3:
            deleteDirector(&sql);
            break;
          case 4:
            addMovie(&sql, &id_movie);
            printf("Is movie produced by major studio?y/n\n");
            getchar();
            c = getchar();
            if(c=='y'){
              addProducing(&sql, id_movie);
            }
            break;
          case 5:
            printMovie(&sql, 1);
            break;
          case 6:
            deleteMovie(&sql);
            break;
          case 7:
            addActor(&sql, &id_actor);
            printf("Is actor part of the movie?y/n\n");
            getchar();
            c=getchar();
            if(c == 'y'){
              addActing_job(&sql, id_actor, &id_movie_helper);
            }
            break;
          case 8:
            printActor(&sql, 1);
            break;
          case 9:
            deleteActor(&sql);
            break;
          case 10:
            addActing_job_EXISTS(&sql, &id_movie_helper, &id_actor);
            break;
          case 11:
            movie_budget(&sql);
            break;
          case 12:
            actors_movies(&sql);
            break;
          case 13:
        		exit(EXIT_SUCCESS);
        	default:
        	  printf ("wrong command choice!\n");
          }
  }
 return 0;
}
