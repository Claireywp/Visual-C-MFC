// Dialog2.cpp : implementation file
//

#include "stdafx.h"
#include "stu.h"
#include "Dialog2.h"
#include "Dialog1.h"
#include "Dialog3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CString strTemp;
extern CString strTemp1;
extern CString strTemp2;
extern CString strTemp3;
extern CString strTemp4;
extern CString aaaa;
extern CString strTemp5;
extern CString strTemp6;
CString bbb;

/////////////////////////////////////////////////////////////////////////////
// CDialog2 dialog


CDialog2::CDialog2(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog2)
	m_nAge = _T("");
	//}}AFX_DATA_INIT
}


void CDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog2)
	DDX_Control(pDX, IDC_XL, m_XL);
	DDX_Control(pDX, IDC_Adress, m_Ad);
	DDX_Control(pDX, IDC_Mz, m_Mz);
	DDX_Control(pDX, IDC_Ah, m_Ah);
	DDX_Control(pDX, IDC_Sex, m_Sex);
	DDX_Control(pDX, IDC_Name, m_Name);
	DDX_Control(pDX, IDC_Age, m_Age);
	DDX_Text(pDX, IDC_Age, m_nAge);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog2, CDialog)
	//{{AFX_MSG_MAP(CDialog2)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog2 message handlers

void CDialog2::OnOK() 
{
	// TODO: Add extra validation here

	m_Age.SetWindowText (strTemp) ;
	m_Sex.SetWindowText(strTemp2);
	m_Name.SetWindowText(strTemp1);
	
//	CString hoob;
	//hoob=strTemp3+"  "+strTemp4;
	m_Ah.SetWindowText(strTemp3);
//	m_Ah.SetWindowText(strTemp4);
	m_Mz.SetWindowText(aaaa);
	m_XL.SetWindowText(strTemp6);
	m_Ad.SetWindowText(strTemp5);


}

void CDialog2::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}

void CDialog2::OnButton3() 
{
	// TODO: Add your control notification handler code here
	CDialog1 dlg;
	dlg.DoModal ();


}

void CDialog2::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CDialog3 dlg;
	m_Name.GetWindowText(bbb);
	dlg.m_ndeit2=bbb;
	dlg.DoModal();
	CDialog::OnOK();
	
}
