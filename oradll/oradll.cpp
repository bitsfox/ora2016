#include"../ora2016/stdafx.h"
#include"oradll.h"


#pragma comment(lib,".\\orasql11.lib")
#ifdef __cplusplus
extern "C" {
#endif
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[10];
};
static const struct sqlcxp sqlfpn =
{
    9,
    "oradll.pc"
};


static unsigned int sqlctx = 39291;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
            void  *sqhstv[4];
   unsigned int   sqhstl[4];
            int   sqhsts[4];
            void  *sqindv[4];
            int   sqinds[4];
   unsigned int   sqharm[4];
   unsigned int   *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,852,0,0,
5,0,0,1,0,0,32,44,0,0,0,0,0,1,0,
20,0,0,0,0,0,27,71,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,10,0,0,
51,0,0,3,0,0,17,81,0,0,1,1,0,1,0,1,97,0,0,
70,0,0,3,0,0,11,96,0,0,1,1,0,1,0,1,32,0,0,
89,0,0,3,0,0,14,113,0,0,1,0,0,1,0,2,32,0,0,
108,0,0,3,0,0,15,141,0,0,0,0,0,1,0,
123,0,0,4,0,0,30,142,0,0,0,0,0,1,0,
138,0,0,3,0,0,19,171,0,0,1,1,0,1,0,3,32,0,0,
157,0,0,3,0,0,20,187,0,0,1,1,0,1,0,3,32,0,0,
};




#ifdef __cplusplus
}
#endif

char mm[4096];
/* EXEC SQL BEGIN DECLARE SECTION; */ 

	char	dyn_stat[1024];
	/* EXEC SQL VAR dyn_stat IS STRING(1024); */ 

/* EXEC SQL END DECLARE SECTION; */ 


SQLDA *select_dp,*bind_dp;
#define MAX_ITEMS			40
#define	MAX_VNAME_LEN		30
#define	MAX_INAME_LEN		30
void free_dp()
{
	int i;
    for (i = 0; i < MAX_ITEMS; i++)
    {    
        if (bind_dp->V[i] != (char *) 0)
            free(bind_dp->V[i]);
        free(bind_dp->I[i]);   /* MAX_ITEMS were allocated. */
        if (select_dp->V[i] != (char *) 0)
            free(select_dp->V[i]);
        free(select_dp->I[i]); /* MAX_ITEMS were allocated. */
    }
    /* Free space used by the descriptors themselves. */
    SQLSQLDAFree( SQL_SINGLE_RCTX, bind_dp);
    SQLSQLDAFree( SQL_SINGLE_RCTX, select_dp);
};
void sql_error(char *msg)
{
 printf("%s\n%s\n", msg,(char *)sqlca.sqlerrm.sqlerrmc);
 free_dp();
 /* EXEC SQL ROLLBACK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 0;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


 exit(0);
};
int alloc_desc(int size,int max_vname_len,int max_iname_len);
void set_bind_v();
void set_select_v();
//这也是首个测试proc使用"select * from..."方法的函数
_declspec(dllexport) int WINAPI get_counts(void *vd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	char uname[20],pwd[20],dbname[60],conn[1024],res[5][100];
	/* EXEC SQL END DECLARE SECTION; */ 

	int i,j;
	CString str,fname,s1,s2;
	_tagbas *tb=(_tagbas*)vd;
	memset((void*)&uname,0,sizeof(uname));
	memset((void*)&pwd,0,sizeof(pwd));
	memset((void*)&dbname,0,sizeof(dbname));
	memset((void*)&conn,0,sizeof(conn)); //like "select count(*) from user_tab_columns where table_name ="
	for(i=0;i<5;i++)
		memset((void*)&res[i],0,100);
	memcpy((void*)&uname,tb->uname,strlen(tb->uname));
	memcpy((void*)&pwd,tb->pwd,strlen(tb->pwd));
	memcpy((void*)&dbname,tb->dbname,strlen(tb->dbname));
	memcpy((void*)&conn,tb->conn,sizeof(tb->conn));
	fname.Format(tb->fname);//文件名，由于要导出的数据量可能很大，所以数据不往主程序传送了，直接保存进文件
	/* EXEC SQL CONNECT :uname IDENTIFIED BY :pwd USING :dbname; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )10;
 sqlstm.offset = (unsigned int  )20;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)uname;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )20;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)pwd;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )20;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)dbname;
 sqlstm.sqhstl[2] = (unsigned int  )60;
 sqlstm.sqhsts[2] = (         int  )60;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlstm.sqlcmax = (unsigned int )100;
 sqlstm.sqlcmin = (unsigned int )2;
 sqlstm.sqlcincr = (unsigned int )1;
 sqlstm.sqlctimeout = (unsigned int )0;
 sqlstm.sqlcnowait = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if(sqlca.sqlcode<0)
	{
		str.Format(_T("errno: %ld %s"),sqlca.sqlcode,(CString)(sqlca.sqlerrm.sqlerrmc));
		MessageBox(NULL,str,"ora02.dll",0);
		return -1;
	}
	if(alloc_desc(MAX_ITEMS,MAX_VNAME_LEN,MAX_INAME_LEN)==1)
		sql_error("alloc error");
//	_snprintf(conn,1024,"SELECT COUNT(*) FROM USER_TAB_COLUMNS WHERE TABLE_NAME = '%s'","TEST01");
	/* EXEC SQL PREPARE sqlconn FROM :conn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )51;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)conn;
 sqlstm.sqhstl[0] = (unsigned int  )1024;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if(sqlca.sqlcode<0)
	{
		str.Format(_T("errno: %ld %s"),sqlca.sqlcode,(CString)(sqlca.sqlerrm.sqlerrmc));
		MessageBox(NULL,str,_T("prepare error"),0);
		return -1;
	}	
	/* EXEC SQL DECLARE cur_sp CURSOR FOR sqlconn; */ 

	if(sqlca.sqlcode<0)
	{
		str.Format(_T("errno: %ld %s"),sqlca.sqlcode,(CString)(sqlca.sqlerrm.sqlerrmc));
		MessageBox(NULL,str,_T("declare cursor error"),0);
		return -1;
	}
	set_bind_v();
	/* EXEC SQL OPEN cur_sp USING DESCRIPTOR bind_dp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )70;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (         void  *)bind_dp;
 sqlstm.sqhstl[0] = (unsigned int  )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if(sqlca.sqlcode<0)
	{
		str.Format(_T("errno: %ld %s"),sqlca.sqlcode,(CString)(sqlca.sqlerrm.sqlerrmc));
		MessageBox(NULL,str,_T("open cursor error"),0);
		return -1;
	}
	set_select_v();
	str.Empty();
	CFile file;
	if(!file.Open("d:\\aooo.txt",CFile::modeReadWrite|CFile::modeCreate))
	{
		sql_error("open file error");
	}
	while(1)
	{
		/* EXEC SQL WHENEVER NOT FOUND DO break; */ 

		/* EXEC SQL FETCH cur_sp USING DESCRIPTOR select_dp; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )89;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)select_dp;
  sqlstm.sqhstl[0] = (unsigned int  )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
}


		if(sqlca.sqlcode<0)
		{//-1405 允许空的列值
			if(sqlca.sqlcode!=-1405)
			{
				str.Format(_T("errno: %ld %s"),sqlca.sqlcode,(CString)(sqlca.sqlerrm.sqlerrmc));
				MessageBox(NULL,str,"ora02.dll",0);
				break;	
			}
		}
		memset((void*)&mm,0,sizeof(mm));
		j=0;
		for(i=0;i<select_dp->F;i++)
		{
			str.Format("%s\t",select_dp->V[i]);
			if((j+str.GetLength())>4096)
				sql_error("too long!!");
			memcpy((char*)&mm[j],str.GetBuffer(0),str.GetLength());
			j+=str.GetLength();						
		}
		mm[j-1]=0xd;mm[j]=0xa;
		file.Write(mm,j+1);
	}
	file.Close();
	if(str.IsEmpty())
	{MessageBox(NULL,"ooooo","aaa",0);}
	free_dp();
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE cur_sp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )108;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL COMMIT WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )123;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return 0;
};
int alloc_desc(int size,int max_vname_len,int max_iname_len)
{
	int i;
	if((bind_dp=SQLSQLDAAlloc(0,size,max_vname_len,max_iname_len)) == (SQLDA *)0)
	{
		return 1;
	}
	bind_dp->N =MAX_ITEMS;
	if((select_dp=SQLSQLDAAlloc(SQL_SINGLE_RCTX,size,max_vname_len,max_iname_len)) == (SQLDA*)0)
	{
		return 1; //error
	}
	select_dp->N = MAX_ITEMS;
	for(i=0;i<MAX_ITEMS;i++)
	{
		bind_dp->I[i]	= (short *)malloc(sizeof(short));
		bind_dp->V[i]	= (char *)malloc(sizeof(char));
		select_dp->I[i] = (short *)malloc(sizeof(short));
		select_dp->V[i] = (char *)malloc(1);
	}
	return 0;
};
void set_bind_v()
{
	int i;
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("set_select_v"); */ 

	/* EXEC SQL DESCRIBE BIND VARIABLES FOR sqlconn INTO bind_dp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )138;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)bind_dp;
 sqlstm.sqhstl[0] = (unsigned int  )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("set_select_v");
}


	if(bind_dp->F<0)
	{
		MessageBox(NULL,"columns is too long","err",0);
		return;
	}
	bind_dp->N = bind_dp->F;
	for(i=0;i<bind_dp->N;i++)
	{
		bind_dp->T[i]=1;
	}
};
void set_select_v()
{
	int i,null_ok,precision,scale;
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("set_select_v"); */ 

	/* EXEC SQL DESCRIBE SELECT LIST FOR sqlconn INTO select_dp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )157;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)select_dp;
 sqlstm.sqhstl[0] = (unsigned int  )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("set_select_v");
}


	if(select_dp->F<0)
	{
		MessageBox(NULL,"columnsaaaa is too long","err",0);
		return;		
	}
	select_dp->N = select_dp->F;
	for(i=0;i<select_dp->F;i++)
	{
//		SQLColumnNullCheck((unsigned short *)&(select_dp->T[i]), (unsigned short *)&(select_dp->T[i]), &null_ok);
		sqlnul((unsigned short *)&(select_dp->T[i]), (unsigned short *)&(select_dp->T[i]), &null_ok);	
		switch(select_dp->T[i])
		{
		case 1:	//char	type
			break;
		case 2: //number type
		    sqlprc((unsigned int *)&(select_dp->L[i]), &precision, &scale);
			//SQLNumberPrecV6( SQL_SINGLE_RCTX,(unsigned long *)&(select_dp->L[i]), &precision, &scale);
		    if (precision == 0) 
			 	precision = 40;

   	        if (scale > 0)//转换数字类型为浮点型
	           select_dp->L[i] = sizeof(float);
	        else//否则为整型
	            select_dp->L[i] = sizeof(int);
	        break;
	    case  8 : /* LONG datatype */
	        select_dp->L[i] = 240;
	        break;
	    case 11 : /* ROWID datatype */
	        select_dp->L[i] = 18;
	      break;
	   case 12 : /* DATE datatype */
	       select_dp->L[i] = 9;
	       break;
	   case 23 : /* RAW datatype */
	       break;
	   case 24 : /* LONG RAW datatype */
	      select_dp->L[i] = 240;
	      break;
		};
//	  if (select_dp->T[i] != 2)
//	      select_dp->V[i] = (char *) realloc(select_dp->V[i],select_dp->L[i] + 1);  
//	  else
//	       select_dp->V[i] = (char *) realloc(select_dp->V[i],select_dp->L[i]);
//	  if (select_dp->T[i] != 24 && select_dp->T[i] != 2)
//	      select_dp->T[i] = 1;
	      /* Coerce the datatypes of NUMBERs to float or int depending on
        the scale. */
//	  if (select_dp->T[i] == 2)
//	      if (scale > 0)
//	         select_dp->T[i] = 4;  /* float */
//		  else
//             select_dp->T[i] = 3;  /* int */
	select_dp->V[i] = (char *)realloc(select_dp->V[i], select_dp->L[i]+1);
 	select_dp->V[i][select_dp->L[i]] =0;//加上终止符
	select_dp->T[i] = 1;//把所有类型转换为字符型
	}
};
