#ifndef _MY_ORACLE_PROCESS_
#include"D:\app\Administrator\product\11.1.0\db_1\precomp\public\sqlda.h"
#include"D:\app\Administrator\product\11.1.0\db_1\precomp\public\sqlca.h"
#include"D:\app\Administrator\product\11.1.0\db_1\precomp\public\oraca.h"
#include"D:\app\Administrator\product\11.1.0\db_1\precomp\public\sqlcpr.h"
#endif
//this define is used for SQL_SINGLE_RCTX
#ifndef dvoid
#define	dvoid				void
#endif

#define ITEM_LIMIT			40
#define	INDICATOR_LIMIT		30
#define VALUE_LIMIT			30
#define	BUF_SZ				4096
#define FNAME_SZ			2048

SQLDA *sel_dp,*bind_dp;
unsigned char	buf[BUF_SZ];
char	fname[FNAME_SZ];

//这是使用动态Proc方法4实现的一个oracle数据库访问函数，结果导出为txt文件。
_declspec(dllexport) int WINAPI out_result(void *v);
//主函数的初始化函数
int init_data(void *vd);
//下面的函数定义都是方法四所使用的具体功能函数,无需导出给用户
//SQLDA指针的内存分配函数
int alloc_da();
//SQLDA指针的内存释放函数
void free_da();
//动态执行SQL的错误处理函数
void sql_error(char *ch);
//SQLDA结构指针bind_dp的赋值函数
void set_sql_b();
//SQLDA结构指针sel_dp的赋值函数
void set_sql_s();
//analysis conn whether or not a select operator
int analysis_conn();

