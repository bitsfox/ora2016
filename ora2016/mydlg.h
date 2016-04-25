#ifndef IDD_DIALOG1
#include"resource.h"
#endif

class mydlg:public CDialog
{
public:
	mydlg(CWnd *pwnd=NULL):CDialog(IDD_DIALOG1,pwnd)
	{}
	BOOL OnInitDialog();
	afx_msg void OnOK();
	afx_msg void OnCancel();
	BOOL analysis_db();
	afx_msg void onsave();
	afx_msg void onload();
	afx_msg void onrun();
DECLARE_MESSAGE_MAP()
};