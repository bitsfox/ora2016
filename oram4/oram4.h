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

//����ʹ�ö�̬Proc����4ʵ�ֵ�һ��oracle���ݿ���ʺ������������Ϊtxt�ļ���
_declspec(dllexport) int WINAPI out_result(void *v);
//�������ĳ�ʼ������
int init_data(void *vd);
//����ĺ������嶼�Ƿ�������ʹ�õľ��幦�ܺ���,���赼�����û�
//SQLDAָ����ڴ���亯��
int alloc_da();
//SQLDAָ����ڴ��ͷź���
void free_da();
//��ִ̬��SQL�Ĵ�������
void sql_error(char *ch);
//SQLDA�ṹָ��bind_dp�ĸ�ֵ����
void set_sql_b();
//SQLDA�ṹָ��sel_dp�ĸ�ֵ����
void set_sql_s();
//analysis conn whether or not a select operator
int analysis_conn();

