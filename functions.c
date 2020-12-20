#include "functions.h"

#define KCYN  "\x1B[36m"
#define RESET "\033[0m"
#define KMAG  "\x1B[35m"

//using global counters to generate id
//another considered option was generating random numbers and checking availability
//but for a larger dataset, too many unnecessary checks
int director_id_counter = 500;
int movie_id_counter = 1;
int actor_id_counter = 1050;

int getRandom(int lower_bound , int upper_bound)
{
  int num = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
  return num;
}

void addDirector(Sql *sql,int *id_director){
  printDirector(sql, 1);
  printf("Insert directors name, surname and country of origin:\n");

  int id;


  id = director_id_counter;
  director_id_counter++;

  char* country;
  char* name;
  char* surname;
  scanf("%ms%ms%ms", &name, &surname, &country);
  *id_director = id;
  sprintf(sql->query,"insert into Director (id_Director,Name,Surname,Country) values (%d,'%s','%s','%s');",id, name, surname, country);

  if (mysql_query(sql->connection, sql->query)) {
    	printf ("Inserting director failed.\n");
      exit (EXIT_FAILURE);
  }

  free(country);
  free(name);
  free(surname);
}

void deleteDirector(Sql *sql){
  printDirector(sql, 0);
  printf("Enter Id of director to remove:\n");

  int id;
  scanf("%i",&id);
  sprintf (sql->query, "delete from Director where id_Director=%i;", id);

  if (mysql_query(sql->connection, sql->query)) {
   printf ("Removal of Director failed.\n");
   exit (EXIT_FAILURE);
  }

 printf ("Directors after removal:\n\n");
 printDirector(sql, 1);
 printf("\n\n");

}

void printDirector(Sql *sql, int start){

  sprintf (sql->query, "select * from Director;");
  if (mysql_query(sql->connection, sql->query)) {
    printf ("Printing all directors failed.\n");
    exit (EXIT_FAILURE);
  }

  sql->result = mysql_use_result(sql->connection);
  sql->column = mysql_fetch_fields(sql->result);

  int n = mysql_field_count(sql->connection);
  int i;
  for (i = start; i < n; i++) {
    if(i > 1)
      printf("\t");
    printf ("%s\t\t\t\t\t", sql->column[i].name);
  }
  printf ("\n\n");

  while ((sql->row = mysql_fetch_row(sql->result))) {
    for (i = start; i < n; i++)
    {
      int printed = printf ("%s", sql->row[i]);

      if(printed < 8)
        printf("\t\t\t\t\t\t");
      else if(printed < 16)
        printf("\t\t\t\t\t");
      else if(printed < 24)
        printf("\t\t\t\t");
      else
        printf("\t\t\t");

    }
    printf ("\n");
  }
  printf ("\n\n");
}

void printStudio(Sql *sql){

  sprintf (sql->query, "select * from Studio;");

  if (mysql_query(sql->connection, sql->query)) {
    printf ("Studio printing failed.\n");
    exit (EXIT_FAILURE);
  }

  sql->result = mysql_use_result(sql->connection);
  sql->column = mysql_fetch_fields(sql->result);

  int n = mysql_field_count(sql->connection);
  int i = 0;

  for (i = 0; i < n; i++) {
    if(i == 2)
      printf ("\t");
    printf ("%s\t\t\t\t\t", sql->column[i].name);
  }
  printf ("\n\n");

  while ((sql->row = mysql_fetch_row(sql->result))) {
    int i;
    for (i = 0; i < n; i++)
    {
    int printed = printf ("%s", sql->row[i]);
    if(printed < 8)
      printf("\t\t\t\t\t\t");
    else if(printed < 16)
      printf("\t\t\t\t\t");
    else if(printed < 24)
      printf("\t\t\t\t");
    else
      printf("\t\t\t");
    }
    printf ("\n");
  }
  printf ("\n\n");

}

void addEmployed(Sql *sql,int id_director){
    int id_studio;
  	int sal;
    printStudio(sql);
    printf("\nInsert studios Id and directors salary:\n");

    scanf("%d%d", &id_studio, &sal);
    sprintf(sql->query,"insert into Employed values (%d,%d,%d);",id_director, sal , id_studio);

    if (mysql_query(sql->connection, sql->query)) {
      	printf ("Adding in Employed failed.\n");
      	exit (EXIT_FAILURE);
    }
    return;
}

void addMovie(Sql *sql,int *id_movie){
  printf("Enter movie name:\n");
  char *name= NULL;
  size_t len;
  getchar();
  int ch_read = getline(&name, &len, stdin);
  name[ch_read-1] = '\0';

  printMovie(sql, 1);
  printDirector(sql, 0);
  printf("Insert start and end date of filming(format:yyyy-mm-dd) and Id of director\n");

  char* start;
  char* end;
  int id_director;

  *id_movie = movie_id_counter;
  movie_id_counter++;

  scanf("%ms%ms%d", &start, &end, &id_director);


  sprintf(sql->query,"insert into Movie (id_Movie,Name,Filming_start,Filming_end,Director_id_Director) values (%d,'%s','%s','%s',%d);"
              ,*id_movie, name, start, end, id_director);

  if (mysql_query(sql->connection, sql->query)) {
      printf ("Adding movie failed.\n");
      exit (EXIT_FAILURE);
  }

  free(name);
  free(start);
  free(end);
}

void printMovie(Sql *sql, int start){
  sprintf (sql->query, "select id_Movie,Duration,m.Name,Surname,d.Name\
              from Movie m join Director d\
              on d.id_Director=m.Director_id_Director;");

  if (mysql_query(sql->connection, sql->query)) {
    printf ("print ver_1 failed.\n");
    exit (EXIT_FAILURE);
  }

  sql->result = mysql_use_result(sql->connection);
  sql->column = mysql_fetch_fields(sql->result);

  int n = mysql_field_count(sql->connection);
  int i;
  for (i = start; i < n; i++) {
    if(start == 0 &&  i == 1)
      printf("\t\t\t");
    if(i > 1)
      printf("\t\t\t");
    if(i > 2)
      printf("\t");
    printf ("%s\t\t", sql->column[i].name);
  }
  printf ("\n\n");

  while ((sql->row = mysql_fetch_row(sql->result))) {
    int i;
    for (i = start; i < n; i++)
    {
      int printed = printf ("%s", sql->row[i]);
      if(printed < 8)
        printf("\t\t\t\t\t\t");
      else if(printed < 16)
        printf("\t\t\t\t\t");
      else if(printed < 24)
        printf("\t\t\t\t");
      else
        printf("\t\t\t");

    }
    printf ("\n");
  }
  printf ("\n\n");

}

void deleteMovie(Sql *sql){
  printMovie(sql, 0);
  printf("insert Id of a movie to delete);\n");

  int id;
  scanf("%i", &id);
  sprintf (sql->query, "delete from Movie where id_Movie=%i;", id);

  if (mysql_query(sql->connection, sql->query)) {
   printf ("movie delete failed.\n");
   exit (EXIT_FAILURE);
  }

 printf ("Movies after removal:\n\n");
 printMovie(sql, 1);
 printf("\n\n");

}

void addProducing(Sql *sql,int id_movie){
  printStudio(sql);
  printf("insert id of studio which is producing movie:\n");
  int id;
  scanf("%d", &id);
  sprintf(sql->query,"insert into Producing (Movie_id_Movie,Studio_id_Studio, Budget) values (%d,%d,%d);"
  , id_movie, id, 0);

  if (mysql_query(sql->connection, sql->query)) {
      printf ("add producing query failed.\n");
      exit (EXIT_FAILURE);
  }
}


void addActor(Sql *sql,int *id_actor){
  printActor(sql, 1);
  printf("insert actor/actress name and surname:\n");
  char* name;
  char* surname;

  *id_actor = actor_id_counter;
  actor_id_counter++;

  scanf("%ms%ms", &name, &surname);

  sprintf(sql->query,"insert into Actor values (%d,'%s','%s');"
          , *id_actor, name, surname);

  if (mysql_query(sql->connection, sql->query)) {
      printf ("add actor query failed\n");
      exit (EXIT_FAILURE);
  }
  free(name);
  free(surname);

}

void printActor(Sql *sql, int start){
  sprintf (sql->query, "select * from Actor;");

  if (mysql_query(sql->connection, sql->query)) {
    printf ("print actor query failed.\n");
    exit (EXIT_FAILURE);
  }

  sql->result = mysql_use_result(sql->connection);
  sql->column = mysql_fetch_fields(sql->result);

  int n = mysql_field_count(sql->connection);
  int i = 0;
  for (i = start; i < n; i++) {
    if(i == 2)
      printf("\t");
    printf ("%s\t\t\t\t\t", sql->column[i].name);
  }
  printf ("\n\n");

  while ((sql->row = mysql_fetch_row(sql->result))) {
    for (i = start; i < n; i++)
    {
      int printed = printf ("%s",sql->row[i]);
      if(printed < 8)
        printf("\t\t\t\t\t\t");
      else if(printed < 16)
        printf("\t\t\t\t\t");
      else if(printed < 24)
        printf("\t\t\t\t");
      else
        printf("\t\t\t");
    }
    printf ("\n");
  }
  printf ("\n\n");

}

void deleteActor(Sql *sql){
  printActor(sql, 0);
  printf("insert actor/actress id for removal;\n");

  int id;
  scanf("%d", &id);
  sprintf (sql->query, "delete from Actor where id_Actor=%i;", id);
  if (mysql_query(sql->connection, sql->query)) {
   printf ("delete actor query failed.\n");
   exit (EXIT_FAILURE);
  }

 printf ("Actors after removal:\n\n");
 printActor(sql, 1);
 printf("\n\n");
}

void addActing_job(Sql *sql,int id_act,int *id_movie){
  printMovie(sql, 0);
  printf("insert movie Id and actor role and contract value:\n");
  char* role;
  int id;
  int contract;
  scanf("%d%ms%d", &id, &role, &contract);
  *id_movie = id;

  sprintf(sql->query,"insert into Acting_job values (%d,%d,'%s',%d);"
              , id, id_act, role, contract);

  if (mysql_query(sql->connection, sql->query)) {
      printf ("add acting job query failed.\n");
      exit (EXIT_FAILURE);
  }
}


void printProducing(Sql *sql){
  sprintf (sql->query, "select * from Producing;");
  if (mysql_query(sql->connection, sql->query)) {
    printf ("print producing query failed.\n");
    exit (EXIT_FAILURE);
  }

  sql->result = mysql_use_result(sql->connection);
  sql->column = mysql_fetch_fields(sql->result);

  int n = mysql_field_count(sql->connection);
  int i;
  for (i = 0; i < n; i++) {
    printf ("%s\t\t", sql->column[i].name);
  }
  printf ("\n\n");

  while ((sql->row = mysql_fetch_row(sql->result))) {
    int i;
    for (i = 0; i < n; i++)
      printf ("%s\t\t\t", sql->row[i]);
    printf ("\n");
  }
  printf ("\n\n");
}

void addActing_job_EXISTS(Sql *sql, int *id_movie_out, int *id_actor_out){
  printMovie(sql, 0);
  printActor(sql, 0);

  printf("insert  actor ID, movie ID, actors role and contract:\n");
  char* role;
  int id_movie;
  int id_actor;
  int contract;
  scanf("%d%d%ms%d", &id_actor, &id_movie, &role, &contract);

  *id_movie_out = id_movie;
  *id_actor_out = id_actor;

  sprintf(sql->query,"insert into Acting_job values (%d,%d,'%s',%d);",id_movie, id_actor, role, contract);


  if (mysql_query(sql->connection, sql->query)) {
      printf ("add acting job exists query failed.\n");
      exit (EXIT_FAILURE);
  }
  free(role);
}

void movie_budget(Sql *sql){
  printMovie(sql, 0);
  printf("insert movie id:");
  int id;
  scanf("%d",&id);
  sprintf (sql->query, "select m.Name, p.Budget\
                        from Producing p join Movie m on m.id_Movie=p.Movie_id_Movie\
                        where Movie_id_Movie=%d;",id);
  if (mysql_query(sql->connection, sql->query)) {
    printf ("movie budget query failed.\n");
    exit (EXIT_FAILURE);
  }

  sql->result = mysql_use_result(sql->connection);

  sql->column = mysql_fetch_fields(sql->result);

  int n = mysql_field_count(sql->connection);
  int i;
  for (i = 0; i < n; i++) {
    printf ("%s\t\t\t", sql->column[i].name);
  }
  printf ("\n\n");

  while ((sql->row = mysql_fetch_row(sql->result))) {
    int i;
    for (i = 0; i < n; i++)
      printf ("%s\t\t", sql->row[i]);
    printf ("\n");
  }
  printf ("\n\n");
}

void actors_movies(Sql *sql){
  printActor(sql, 0);
  printf("insert actor id:");
  int id;
  scanf("%d",&id);
  sprintf (sql->query, "select m.name,a.role\
          from Movie m join Acting_job a on m.id_Movie = a.Movie_id_Movie\
          where Actor_id_Actor=%d;",id);
  if (mysql_query(sql->connection, sql->query)) {
    printf ("actors movies query failed.\n");
    exit (EXIT_FAILURE);
  }

  sql->result = mysql_use_result(sql->connection);

  sql->column = mysql_fetch_fields(sql->result);

  int n = mysql_field_count(sql->connection);
  int i=0;
  for (i = 0; i < n; i++) {
    printf ("%s\t\t\t", sql->column[i].name);
  }
  printf ("\n\n");

  while ((sql->row = mysql_fetch_row(sql->result))) {
    int i;
    for (i = 0; i < n; i++)
      printf ("%s\t\t", sql->row[i]);
    printf ("\n");
  }
  printf ("\n\n");
}
