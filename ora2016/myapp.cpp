#include"stdafx.h"
#include"resource.h"
#include"mydlg.h"
#include"myapp.h"
#include"myconst.h"

CString sfname;
CString scon;
typedef int (WINAPI *GET_DATA)(void*);
GET_DATA	get_da=NULL;
int init_env();
BOOL myapp::InitInstance()
{
	//_dupenv_s(); instead of getenv()
	if(init_env()!=0)
		return 0;
	mydlg mdlg(NULL);
	m_pMainWnd=&mdlg;
	mdlg.DoModal();
	return false;
};
UINT get_data(LPVOID lp)
{
	_TGDT *td=(_TGDT*)lp;
	CString str,s1;
	_tagbas tb;
	memset((void*)&tb,0,sizeof(tb));
	memcpy(tb.dbname,td->host,strlen(td->host));
	memcpy(tb.uname,td->user,strlen(td->user));
	memcpy(tb.pwd,td->pwd,strlen(td->pwd));
	int i=sfname.GetLength();
	if(i>sizeof(tb.fname))
	{
		MessageBox(NULL,"filename too long!","err",0);
		return 0;
	}
	memcpy(tb.fname,sfname.GetBuffer(0),i);
	memcpy(tb.conn,scon.GetBuffer(0),scon.GetLength());
/*�µ��ĵã�
��where ����ı��������д�����һ�Ҫ�е����Ű�����������from����ı������������ţ����Ҳ���Ҫ��дת��
column_name,data_type,data_length,data_precision,data_scale
*/
	HMODULE mod=NULL;
//	mod=::LoadLibraryA("oradll.dll");
	mod=::LoadLibraryA("oram4.dll");
	if(mod==NULL)
	{
		MessageBox(NULL,"load library error","err",0);
		return 0;
	}
	get_da=(GET_DATA )::GetProcAddress(mod,"out_result");
//	get_da=(GET_DATA )::GetProcAddress(mod,"get_counts");
	if(get_da==NULL)
	{
		MessageBox(NULL,"get procaddress error","err",0);
		::FreeLibrary(mod);
		return 0;
	}
	get_da((void*)&tb);
	::FreeLibrary(mod);
	return 0;
};
int init_env()
{//�ú���ʵ���������ܣ����path·�����鿴ע�����ע���û�������Ϣ��д��
	char ch[4096],c1[512],c2[512],*c;
	int i,j,k;
	DWORD dw,dw1,reg;
	CString str;
	HKEY key;
	long lret;
//����ʵ��path����·������ӣ���ӵĻ�������ֻ�ڱ���������ʱ��Ч��
//	_dupenv_s()
	c=::getenv("PATH");
	if(c==NULL)
	{
		MessageBox(NULL,_T("ȡ�û�������ʧ��"),_T("���û�����������"),0);
		return 1;
	}
	memset(ch,0,4096);
	memcpy(ch,"PATH=",5);
/*	memcpy(&ch[5],c,strlen(c));
	j=strlen(ch);
	ch[j]=';';j++; */
	j=strlen(ch);
	memset(c1,0,512);
	::GetModuleFileNameA(NULL,c1,512);
	i=strlen(c1);
	for(;i>0;i--)
	{
		if(c1[i]=='\\')
			break;
	}
	k=i+1;
	memcpy(&ch[j],c1,k);
	j=strlen(ch);
	memset(c1,0,512);
	memcpy(c1,"ex_a011\\BIN\\;",strlen("ex_a011\\BIN\\;"));
	i=strlen(c1);
	memcpy(&ch[j],c1,i);
	j=strlen(ch);
	memcpy(&ch[j],c,strlen(c));
	_putenv(ch);//���path���
/*	c=::getenv("PATH");
	str.Format("%s",c);
	MessageBox(NULL,str,"path",0);*/
	reg=REG_SZ;dw=0;//HKEY_LOCAL_MACHINE,����֤������HKEY_CURRENT_USER����������Ȩ�����ƣ�
//����HKEY_LOCAL_MACHINE�Ĳ����ͻ����Ȩ�����⣬�����й���Ա��Ȩ�޲���ִ��:���������ԣ�д�������� KEY_ALL_ACCESS
	lret=::RegCreateKeyExA(HKEY_LOCAL_MACHINE,"SOFTWARE\\tybitsfox\\Oracle11g_home1\\",0,NULL,REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&key,&dw);
	if(lret!=ERROR_SUCCESS)
	{
		MessageBox(NULL,_T("��ע���ʧ��\n��ʹ�ù���Ա�˻����в���"),_T("ע������"),0);
		return 1;
	}
	memset(c1,0,512);
	dw=::GetModuleFileNameA(NULL,c1,512);
	i=strlen(c1);
	for(;i>0;i--)
	{
		if(c1[i]=='\\')
			break;
	}
	i++;
	memset(c2,0,512);
	memcpy(c2,c1,i);
	memset(c1,0,512);
	memcpy(c1,"ex_a011",strlen("ex_a011"));
	memcpy(&c2[i],c1,strlen(c1));
	dw=(DWORD)strlen(c2);
	memset(c1,0,512);dw1=512;
	if(::RegQueryValueExA(key,"ORACLE_HOME",0,&reg,(BYTE*)c1,&dw1)!=ERROR_SUCCESS)
	{
		if(::RegSetValueExA(key,"ORACLE_HOME",0,REG_SZ,(BYTE*)c2,dw)!=ERROR_SUCCESS)
		{
			MessageBoxA(NULL,"����oracle���ݿ���ʵ���ؼ�ֵORACLE_HOMEʧ��","ע������",0);
			::RegCloseKey(key);
			return 1;
		}
	}
	else
	{
		if(strcmp(c1,c2)!=0)
		{
			if(::RegSetValueExA(key,"ORACLE_HOME",0,REG_SZ,(BYTE*)c2,dw)!=ERROR_SUCCESS)
			{
				MessageBoxA(NULL,"�޸�oracle���ݿ���ʵ���ؼ�ֵORACLE_HOMEʧ��","ע������",0);
				::RegCloseKey(key);
				return 1;
			}
		}
	}
	memset(c1,0,256);
	memset(c2,0,256);
	memcpy(c2,"SIMPLIFIED CHINESE_CHINA.ZHS16GBK",strlen("SIMPLIFIED CHINESE_CHINA.ZHS16GBK"));
	dw1=256;reg=REG_SZ;
	dw=strlen(c2);
	if(::RegQueryValueExA(key,"NLS_LANG",0,&reg,(BYTE*)c1,&dw1)!=ERROR_SUCCESS)
	{
		if(::RegSetValueExA(key,"NLS_LANG",0,REG_SZ,(BYTE*)c2,dw)!=ERROR_SUCCESS)
		{
			MessageBoxA(NULL,"����oracle���ݿ���ʵ���ؼ�ֵNLS_LANGʧ��","ע������",0);
			::RegCloseKey(key);
			return 1;
		}
	}
	else
	{
		if(strcmp(c1,c2)!=0)
		{
			if(::RegSetValueExA(key,"NLS_LANG",0,REG_SZ,(BYTE*)c2,dw)!=ERROR_SUCCESS)
			{
				MessageBoxA(NULL,"�޸�oracle���ݿ���ʵ���ؼ�ֵNLS_LANGʧ��","ע������",0);
				::RegCloseKey(key);
				return 1;
			}
		}
	}
	::RegCloseKey(key);
	return 0;
};