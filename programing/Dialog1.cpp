// Dialog1.cpp : implementation file
//

#include "stdafx.h"
#include "stu.h"
#include "Dialog1.h"
#include "Dialog2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString strTemp;
CString strTemp1;
CString strTemp2;
CString strTemp3;
CString strTemp4;
CString aaaa;
CString strTemp5;
CString strTemp6;
/////////////////////////////////////////////////////////////////////////////
// CDialog1 dialog


CDialog1::CDialog1(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog1)
	m_strAge = _T("");
	m_strHome = _T("");
	m_nMz = _T("");
	m_strName = _T("");
	m_nSex = -1;
	m_nXl = -1;
	m_aihao1 = FALSE;
	m_aihao2 = FALSE;
	//}}AFX_DATA_INIT
}


void CDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog1)
	DDX_Control(pDX, IDC_Hoo2, m_Hoo2);
	DDX_Control(pDX, IDC_Hoo1, m_Hoo1);
	DDX_Control(pDX, IDC_Xl3, m_Xl);
	DDX_Control(pDX, IDC_Sex1, m_Sex);
	DDX_Control(pDX, IDC_Name, m_Name);
	DDX_Control(pDX, IDC_Mz, m_Mz);
	DDX_Control(pDX, IDC_Home, m_Home);
	DDX_Control(pDX, IDC_Age, m_Age);
	DDX_Text(pDX, IDC_Age, m_strAge);
	DDX_Text(pDX, IDC_Home, m_strHome);
	DDX_CBString(pDX, IDC_Mz, m_nMz);
	DDX_Text(pDX, IDC_Name, m_strName);
	DDX_Radio(pDX, IDC_Sex1, m_nSex);
	DDX_Radio(pDX, IDC_Xl3, m_nXl);
	DDX_Check(pDX, IDC_Hoo1, m_aihao1);
	DDX_Check(pDX, IDC_Hoo2, m_aihao2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog1, CDialog)
	//{{AFX_MSG_MAP(CDialog1)
	ON_BN_CLICKED(IDC_Sex2, OnSex2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_Xl4, OnXl4)
	ON_BN_CLICKED(IDC_Hoo1, OnHoo1)
	ON_BN_CLICKED(IDC_Hoo2, OnHoo2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog1 message handlers

void CDialog1::OnOK() 
{
	// TODO: Add extra validation here

	CDialog2 dlg;

	CString tempRadio;
	CString tempRadio1;

	char buffer[10];

	UpdateData(TRUE);                       // 使得改变实时被捕捉

	tempRadio=itoa(m_nSex,buffer,10);//函数：char *itoa(int value, char *string, int radix);
	                               //int value 被转换的整数，char *string 转换后储存的字符数组，int radix 转换进制数，如2,8,10,16 进制等
	if (tempRadio=="0")
		strTemp2="男";
	if(tempRadio=="1")
		strTemp2="女";

//	m_Sex.GetWindowText(strTemp2);


	tempRadio1=itoa(m_nXl,buffer,10);

	if(tempRadio1=="0")
		strTemp6="本科";
	if(tempRadio1=="1")
		strTemp6="专科";

//	m_Xl.GetWindowText(strTemp6);

		
	m_Age.GetWindowText (strTemp);
	//dlg.m_nAge=strTemp;
	m_Name.GetWindowText(strTemp1);


	CString aihao1,aihao2;
	if ( BST_CHECKED == IsDlgButtonChecked( IDC_Hoo1 )) 
		m_Hoo1.GetWindowText(aihao1);
	if( BST_CHECKED == IsDlgButtonChecked( IDC_Hoo2 ) )
		m_Hoo2.GetWindowText(aihao2);
	strTemp3=aihao1+" "+aihao2;

/*	CString tempCheck="";
	//strTemp4="";
	if(m_aihao1==true)
	{
		strTemp4=tempCheck+"music";
		m_Hoo1.GetWindowText(strTemp4);
	}
	if(m_aihao2==true)
	{
		strTemp4=strTemp4+"movie";
		m_Hoo2.GetWindowText(strTemp4);
	}*/
	m_Mz.GetWindowText(aaaa);

	m_Home.GetWindowText(strTemp5);

	


//	CDialog2 dlg;
	dlg.DoModal ();
	CDialog::OnOK();
	
	
}

void CDialog1::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	//CDialog::OnCancel();
	m_Age.SetWindowText("");
	m_Home.SetWindowText("");
	m_Mz.SetWindowText("");
	m_Name.SetWindowText("");
	m_aihao1=false;
	m_aihao2=false;
	m_nSex=-1;


	
}

void CDialog1::OnSex2() 
{
	// TODO: Add your control notification handler code here
	//((CButton *)GetDlgItem(IDC_Sex2))->SetCheck(TRUE);//选上
	m_nSex=1;
  
	
}

BOOL CDialog1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_nSex=0;
	m_nXl=0;
	m_aihao1=false;
	m_aihao2=false;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CDialog1::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();

}

void CDialog1::OnXl4() 
{
	// TODO: Add your control notification handler code here
	m_nXl=1;
}

void CDialog1::OnHoo1() 
{
	// TODO: Add your control notification handler code here
	//m_aihao1=true;
}

void CDialog1::OnHoo2() 
{
	// TODO: Add your control notification handler code here
	//m_aihao2=true;
}
