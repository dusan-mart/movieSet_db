#ifndef MOVIE_H_
#define MOVIE_H_
#include <mysql.h>


#define QUERY_LENGHT 1024

typedef struct {
	MYSQL *connection;
	MYSQL_RES *result;
	MYSQL_ROW row;
	MYSQL_FIELD *column;
	char query[QUERY_LENGHT];
}Sql;

#endif
