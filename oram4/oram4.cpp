#include"../ora2016/stdafx.h"
#include"../ora2016/myconst.h"
#include"oram4.h"



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
           char  filnam[9];
};
static const struct sqlcxp sqlfpn =
{
    8,
    "oram4.pc"
};


static unsigned int sqlctx = 19499;


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
5,0,0,0,0,0,27,28,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,10,0,0,
36,0,0,2,0,0,17,41,0,0,1,1,0,1,0,1,97,0,0,
55,0,0,2,0,0,11,56,0,0,1,1,0,1,0,1,32,0,0,
74,0,0,2,0,0,14,76,0,0,1,0,0,1,0,2,32,0,0,
93,0,0,2,0,0,15,120,0,0,0,0,0,1,0,
108,0,0,3,0,0,30,121,0,0,0,0,0,1,0,
123,0,0,4,0,0,32,197,0,0,0,0,0,1,0,
138,0,0,2,0,0,19,205,0,0,1,1,0,1,0,3,32,0,0,
157,0,0,2,0,0,20,219,0,0,1,1,0,1,0,3,32,0,0,
};




#ifdef __cplusplus
}
#endif

/* EXEC SQL BEGIN DECLARE SECTION; */ 

char uname[20],pwd[20],dbname[60],conn[1024];
/* EXEC SQL END DECLARE SECTION; */ 

_declspec(dllexport) int WINAPI out_result(void *v)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	unsigned char *p;
	int i,j,k;
	CString str;
	CFile file;
	if(init_data(v))
		return -1;
	/* EXEC SQL CONNECT :uname IDENTIFIED BY :pwd USING :dbname; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )10;
 sqlstm.offset = (unsigned int  )5;
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
	if(alloc_da())
	{
		str.Format(_T("errno: %s"),"alloc error");
		MessageBox(NULL,str,"oram4.dll",0);
		return -1;
	}
	/* EXEC SQL PREPARE sqlconn FROM :conn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )36;
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
	set_sql_b();
	/* EXEC SQL OPEN cur_sp USING DESCRIPTOR bind_dp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )55;
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
	if(analysis_conn())
		goto bind_end;
	set_sql_s();
	if(!file.Open(fname,CFile::modeReadWrite|CFile::modeCreate))
		sql_error("open file error");
	memset(buf,0,sizeof(buf));
	i=strlen(conn);
	memcpy(buf,conn,i);
	buf[i]=0xd;buf[i+1]=0xa;
	file.Write(buf,(i+2));
	while(1)
	{
		/* EXEC SQL WHENEVER NOT FOUND DO break; */ 

		/* EXEC SQL FETCH cur_sp USING DESCRIPTOR sel_dp; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )74;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)sel_dp;
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
		j=0;memset(buf,0,sizeof(buf));
		p=buf;
		for(i=0;i<sel_dp->F;i++)
		{
			if(*(sel_dp->I[i])==-1)  //NULL
			{
				*(p++)=0x20; *p=0x9;
				j+=2;continue;
			}
			k=(sel_dp->L[i]);
			if((j+k) >= (BUF_SZ-1)) //for return
				sql_error("record length is too long!");
			memcpy(p,(unsigned char*)(sel_dp->V[i]),k);
			p+=k;
			for(;k>1;k--)
			{
				if((*(--p) == 0x20) || (*(p) == 0))
					*(p)=0;
				else
				{
					p++;p++;
					break;
					}
			}
			j+=k+1;
			buf[j-1]='\t';
		}
		buf[j-1]=0xd;buf[j]=0xa;
		file.Write(buf,j+1);
	}
	file.Close();
bind_end:
	free_da();
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE cur_sp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )93;
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
 sqlstm.offset = (unsigned int  )108;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	MessageBox(NULL,"perfect job! and wish you have a nice day ;)","From dll",0);
	return 0; //perfect!!
};
int init_data(void *vd)
{
	_tagbas *tb=(_tagbas*)vd;	
	memset((void*)&uname,0,sizeof(uname));
	memset((void*)&pwd,0,sizeof(pwd));
	memset((void*)&dbname,0,sizeof(dbname));
	memset((void*)&conn,0,sizeof(conn)); //like "select count(*) from user_tab_columns where table_name ="
	memcpy((void*)&uname,tb->uname,strlen(tb->uname));
	memcpy((void*)&pwd,tb->pwd,strlen(tb->pwd));
	memcpy((void*)&dbname,tb->dbname,strlen(tb->dbname));
	memcpy((void*)&conn,tb->conn,sizeof(tb->conn));
	CTime tma=CTime::GetTickCount();
	int i;
	CString str,s1;
	memset(fname,0,sizeof(fname));
	::GetModuleFileNameA(NULL,fname,sizeof(fname));
	s1.Format(fname);
	i=s1.ReverseFind('\\');
	str=s1.Left(i+1);
	s1=tma.Format("oracle_to_mysql20%y%m%d%H%M%S.txt");
	str+=s1;
	memset(fname,0,sizeof(fname));
	i=str.GetLength();
	if(i>=FNAME_SZ)
	{
		MessageBox(NULL,"file path is too long!","from dll",0);
		return 1;
	}
	memcpy(fname,str.GetBuffer(0),i);
	return 0;
};
//SQLDA指针的内存分配函数
int alloc_da()
{
	int i;
	if((bind_dp=SQLSQLDAAlloc(SQL_SINGLE_RCTX,ITEM_LIMIT,VALUE_LIMIT,INDICATOR_LIMIT)) == (SQLDA *)0)
		return 1;
	bind_dp->N =ITEM_LIMIT;
	if((sel_dp=SQLSQLDAAlloc(SQL_SINGLE_RCTX,ITEM_LIMIT,VALUE_LIMIT,INDICATOR_LIMIT)) == (SQLDA*)0)
		return 1; //error
	sel_dp->N = ITEM_LIMIT;
	for(i=0;i<ITEM_LIMIT;i++)
	{
		bind_dp->I[i]	= (short *)malloc(sizeof(short));
		bind_dp->V[i]	= (char *)malloc(sizeof(char));
		sel_dp->I[i] = (short *)malloc(sizeof(short));
		sel_dp->V[i] = (char *)malloc(1);
	}
	return 0;
};
//SQLDA指针的内存释放函数
void free_da()
{
	int i;
    for (i = 0; i < ITEM_LIMIT; i++)
    {    
        if (bind_dp->V[i] != (char *) 0)
            free(bind_dp->V[i]);
        free(bind_dp->I[i]);   /* ITEM_LIMIT were allocated. */
        if (sel_dp->V[i] != (char *) 0)
            free(sel_dp->V[i]);
        free(sel_dp->I[i]); /* ITEM_LIMIT were allocated. */
    }
    /* Free space used by the descriptors themselves. */
    SQLSQLDAFree( SQL_SINGLE_RCTX, bind_dp);
    SQLSQLDAFree( SQL_SINGLE_RCTX, sel_dp);
};
//动态执行SQL的错误处理函数
void sql_error(char *ch)
{
	printf("%s\n%s\n", ch,(char *)sqlca.sqlerrm.sqlerrmc);
	free_da();
	/* EXEC SQL ROLLBACK RELEASE; */ 

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


	exit(0);
};
//SQLDA结构指针bind_dp的赋值函数
void set_sql_b()
{
	int i;
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("set_sql_b"); */ 

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
 if (sqlca.sqlcode < 0) sql_error("set_sql_b");
}


	if(bind_dp->F<0)
		sql_error("columns is too long");
	bind_dp->N = bind_dp->F;
	for(i=0;i<bind_dp->N;i++)
	{
		bind_dp->T[i]=1;
	}
};
//SQLDA结构指针sel_dp的赋值函数
void set_sql_s()
{
	int i,null_ok,precision,scale;
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("set_sql_s"); */ 

	/* EXEC SQL DESCRIBE SELECT LIST FOR sqlconn INTO sel_dp; */ 

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
 sqlstm.sqhstv[0] = (         void  *)sel_dp;
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
 if (sqlca.sqlcode < 0) sql_error("set_sql_s");
}


	if(sel_dp->F<0)
		sql_error("columnsaaaa is too long");
	sel_dp->N = sel_dp->F;
	for(i=0;i<sel_dp->F;i++)
	{
//		SQLColumnNullCheck((unsigned short *)&(sel_dp->T[i]), (unsigned short *)&(sel_dp->T[i]), &null_ok);
		sqlnul((unsigned short *)&(sel_dp->T[i]), (unsigned short *)&(sel_dp->T[i]), &null_ok);	
		switch(sel_dp->T[i])
		{
		case 1:	//char	type
			break;
		case 2: //number type
		    sqlprc((unsigned int *)&(sel_dp->L[i]), &precision, &scale);
			//SQLNumberPrecV6( SQL_SINGLE_RCTX,(unsigned long *)&(sel_dp->L[i]), &precision, &scale);
		    if (precision == 0) 
			 	precision = 40;
   	        if (scale > 0)//转换数字类型为浮点型
	           sel_dp->L[i] = sizeof(float);
	        else//否则为整型
	            sel_dp->L[i] = sizeof(int);
	        break;
	    case  8 : /* LONG datatype */
	        sel_dp->L[i] = 240;
	        break;
	    case 11 : /* ROWID datatype */
	        sel_dp->L[i] = 18;
	      break;
	   case 12 : /* DATE datatype */
	       sel_dp->L[i] = 9;
	       break;
	   case 23 : /* RAW datatype */
	       break;
	   case 24 : /* LONG RAW datatype */
	      sel_dp->L[i] = 240;
	      break;
		};
		sel_dp->V[i] = (char *)realloc(sel_dp->V[i], sel_dp->L[i]+1);
		sel_dp->V[i][sel_dp->L[i]] =0x20;//加上终止符
		sel_dp->T[i] = 1;//把所有类型转换为字符型
	}
};
//analysis conn whether or not a select operator
int analysis_conn()
{
	CString str;str.Format(conn);
	str.MakeUpper();
	char ch[1025];
	memset(ch,0,sizeof(ch));
	memcpy(ch,str.GetBuffer(0),str.GetLength());
	if(strstr(ch,"SELECT")!=NULL)
		return 0;		//需要继续执行sel_dp
	else
		return 1;		//执行完bind_dp即可退出。
};










