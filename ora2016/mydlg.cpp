#include"stdafx.h"
#include"mydlg.h"
#include"myconst.h"

extern UINT get_data(LPVOID lp);
extern CString sfname;			//保存本程序所在目录路径。
extern CString scon;
BEGIN_MESSAGE_MAP(mydlg,CDialog)
	ON_BN_CLICKED(IDC_BUTTON3,onsave)
	ON_BN_CLICKED(IDC_BUTTON2,onload)
	ON_BN_CLICKED(IDC_BUTTON1,onrun)
END_MESSAGE_MAP()

CArray<_TGDT,_TGDT&> ay;
_TGDT tg;
unsigned char buf[4096];

BOOL mydlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	ay.RemoveAll();
	if(!analysis_db())
		PostQuitMessage(0);
	CString str="\t\t\t\t说明\n1、目标数据库的配置文件在本程序自带的oracle客户端的tnsnames.ora中。\n2、本程序不止可以导出表数据，还可导出表结构。";
	str+="\n3、导出的数据以txt文件的形式保存在本目录下，记录的组织格式适应于mysql的load data infile。\n4、本程序牛逼的不行（超级牛力），";
	str+="可以整表导出也可按字段或条件导出;还可以执行CREATE，INSERT，UPDATE，DELETE命令...\n5、本程序的限制：每条记录的字段数量不超过20条，";
	str+="每个字段名称长度不超过20字节，若要突破限制，请付费取得。\n\n\n\n\n\t\t Author: tybitsfox 2016-4-22 email:tybitsfox@163.com";
	SetDlgItemText(IDC_STATIC1,str);
	CComboBox *box=(CComboBox *)GetDlgItem(IDC_COMBO1);
	box->ResetContent();
	int i,j;
	i=ay.GetCount();
	if(i>0)
	{
		for(j=0;j<i;j++)
		{
			memset((void*)&tg,0,sizeof(tg));
			tg=ay.GetAt(j);
			str.Format(tg.host);
			box->AddString(str);
		}
		box->SetCurSel(0);
		tg=ay.GetAt(0);
		str.Format(tg.host);
		SetDlgItemText(IDC_EDIT2,str);
		str.Format(tg.user);
		SetDlgItemText(IDC_EDIT3,str);
		str.Format(tg.pwd);
		SetDlgItemText(IDC_EDIT4,str);
		str.Format(tg.tbname);
		SetDlgItemText(IDC_EDIT5,str);
	}
	return true;
};
afx_msg void mydlg::OnOK()
{
	CDialog::OnOK();
};
afx_msg void mydlg::OnCancel()
{
	CDialog::OnCancel();
};
BOOL mydlg::analysis_db()
{
	char cname[2048];
	uc auc;
	unsigned char *p;
	CString str;
	int i,j,k;
	memset(cname,0,sizeof(cname));
	if(::GetModuleFileNameA(NULL,cname,sizeof(cname))<=0)
	{
		MessageBox("getmodulefilename error!");
		return false;
	}
	i=strlen(cname);
	for(j=(i-1);j>0;j--)
	{
		if(cname[j]!='\\')
			cname[j]=0;
		else
			break;
	}
	str.Format(cname);
	str+=INI_FILE;
	sfname=str;
	CFile file;
	if(!file.Open(str,CFile::modeRead))
		return true;
	memset(buf,0,sizeof(buf));
	i=file.Read((void*)&buf,sizeof(buf));
	file.Close();
	if(i<=0)
	{
		MessageBox("read ini file error!");
		return false;
	}
	j=sizeof(tg);
	if((i%j)!=0)
	{
		MessageBox("Bad ini file!");
		file.Close();
		return false;
	}
	auc.u=MIX_CODE;
	for(k=0;k<i;k+=4)
	{
		buf[k]^=auc.c[0];buf[k+1]^=auc.c[1];
		buf[k+2]^=auc.c[2];buf[k+3]^=auc.c[3];
	}
	k=i/j;p=buf;
	for(j=0;j<k;j++)
	{
		memset((void *)&tg,0,sizeof(tg));
		memcpy((void *)&tg,p,sizeof(tg));
		ay.Add(tg);p+=sizeof(tg);
	}
	return true;
};
afx_msg void mydlg::onsave()
{
	CString str,s1,s2,s3;
	int i,j;
	uc auc;
	auc.u=MIX_CODE;
	GetDlgItemText(IDC_EDIT2,str);
	if(str.IsEmpty())
	{
		MessageBox("input database name");
		return;
	}
	GetDlgItemText(IDC_EDIT3,s1);
	if(s1.IsEmpty())
	{
		MessageBox("input login name");
		return;
	}
	GetDlgItemText(IDC_EDIT4,s2);
	if(s2.IsEmpty())
	{
		MessageBox("input login password");
		return;
	}
	GetDlgItemText(IDC_EDIT5,s3);
	if(s3.IsEmpty())
	{
		MessageBox("input table name");
		return;
	}
	if(str.GetLength()>sizeof(tg.host))
	{
		MessageBox("db name is too long!!");
		return;
	}
	if(s1.GetLength()>sizeof(tg.user))
	{
		MessageBox("user name is too long!");
		return;
	}
	if(s2.GetLength()>sizeof(tg.pwd))
	{
		MessageBox("password is too long");
		return;
	}
	if(s3.GetLength()>sizeof(tg.tbname))
	{
		MessageBox("table name is too long");
		return;
	}
	memset((void*)&tg,0,sizeof(tg));
	memcpy((void*)&(tg.host),str.GetBuffer(0),str.GetLength());
	memcpy((void*)&(tg.user),s1.GetBuffer(0),s1.GetLength());
	memcpy((void*)&(tg.pwd),s2.GetBuffer(0),s2.GetLength());
	memcpy((void*)&(tg.tbname),s3.GetBuffer(0),s3.GetLength());
	memset((void*)&buf,0,sizeof(buf));
	memcpy((void*)&buf,(void*)&tg,sizeof(tg));
	j=sizeof(tg);
	for(i=0;i<j;i+=4)
	{
		buf[i]^=auc.c[0];buf[i+1]^=auc.c[1];
		buf[i+2]^=auc.c[2];buf[i+3]^=auc.c[3];
	}
	CFile file;
	if(sfname.IsEmpty())
	{
		MessageBox("file name not exist!");
		return;
	}
	if(!file.Open(sfname,CFile::modeReadWrite|CFile::modeCreate|CFile::modeNoTruncate))
	{//T0015_WP_STANDARD
		MessageBox("open or create error!");
//		MessageBox(sfname);
		return;
	}
	file.SeekToEnd();
	file.Write(buf,sizeof(tg));
	file.Close();
	MessageBox("保存成功！");
};
afx_msg void mydlg::onload()
{
	CString str;
	CComboBox *box=(CComboBox*)GetDlgItem(IDC_COMBO1);
	int i=box->GetCurSel();
	if(ay.GetCount()<=i)
	{
		MessageBox("队列长度错误！");
		return;
	}
	memset((void*)&tg,0,sizeof(tg));
	tg=ay.GetAt(i);
	str.Format(tg.host);
	SetDlgItemText(IDC_EDIT2,str);
	str.Format(tg.user);
	SetDlgItemText(IDC_EDIT3,str);
	str.Format(tg.pwd);
	SetDlgItemText(IDC_EDIT4,str);
	str.Format(tg.tbname);
	SetDlgItemText(IDC_EDIT5,str);
};
afx_msg void mydlg::onrun()
{
	memset((void*)&tg,0,sizeof(tg));
	CString str;
	GetDlgItemText(IDC_EDIT2,str);
	memcpy((void*)&(tg.host),str.GetBuffer(0),str.GetLength());
	GetDlgItemText(IDC_EDIT3,str);
	memcpy((void*)&(tg.user),str.GetBuffer(0),str.GetLength());
	GetDlgItemText(IDC_EDIT4,str);
	memcpy((void*)&(tg.pwd),str.GetBuffer(0),str.GetLength());	//保证加载的是显示（用户可能修改的）的信息
	GetDlgItemText(IDC_EDIT5,str);
	memcpy((void*)&(tg.tbname),str.GetBuffer(0),str.GetLength());
	GetDlgItemText(IDC_EDIT1,scon);
	if(scon.IsEmpty())
	{
		MessageBox("请输入SQL字符串");
		return;
	}
	if(scon.GetLength()>1024)
	{
		MessageBox("SQL字符串太长");
		return;
	}	
	AfxBeginThread(get_data,(LPVOID)(&tg));
};