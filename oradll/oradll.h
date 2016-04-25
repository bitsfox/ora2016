#include"D:\app\Administrator\product\11.1.0\db_1\precomp\public\sqlda.h"
#include"D:\app\Administrator\product\11.1.0\db_1\precomp\public\sqlca.h"
#include"D:\app\Administrator\product\11.1.0\db_1\precomp\public\oraca.h"
#include"D:\app\Administrator\product\11.1.0\db_1\precomp\public\sqlcpr.h"
//this define is used for SQL_SINGLE_RCTX
#ifndef dvoid
#define	dvoid				void
#endif
typedef struct _TAGBAS
{
	char	uname[20];
	char	pwd[20];
	char	dbname[60];
	char	conn[1024];
	char	fname[1024];
}_tagbas;



_declspec(dllexport) int WINAPI get_counts(void *vd);
//_declspec(dllexport) int WINAPI get_result(void *vd);