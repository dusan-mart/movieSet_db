#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "movie.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include <error.h>
#include <errno.h>

int getRandom(int lower_bound , int upper_bound);

void addDirector(Sql *sql,int *);
void deleteDirector(Sql *sql);
void printDirector(Sql *sql, int);//second argument 0 to print with IDs and 1 without

void printStudio(Sql *sql);
void addEmployed(Sql *sql,int);


void addMovie(Sql *sql,int *);
void printMovie(Sql *sql, int);
void deleteMovie(Sql *sql);
void addProducing(Sql *sql,int);

void addActor(Sql *sql,int *);
void printActor(Sql *sql, int);
void deleteActor(Sql *sql);

void addActing_job(Sql *sql, int, int*);
void printProducing(Sql *sql);
void addActing_job_EXISTS(Sql *sql, int* , int*);


void movie_budget(Sql *sql);
void actors_movies(Sql *sql);
#endif
