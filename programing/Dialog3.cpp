// Dialog3.cpp : implementation file
//

#include "stdafx.h"
#include "stu.h"
#include "Dialog3.h"
#include "Dialog2.h"
#include "Dialog4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CString bbb;
/////////////////////////////////////////////////////////////////////////////
// CDialog3 dialog


CDialog3::CDialog3(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog3)
	m_strDept = _T("");
	m_nLoyal = 0;
	m_ndeit2 = _T("");
	//}}AFX_DATA_INIT
}


void CDialog3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog3)
	DDX_Control(pDX, IDC_LIST1, m_cb);
	DDX_Control(pDX, IDC_EDIT4, m_edit4);
	DDX_Control(pDX, IDC_DEPT, m_cc);
	DDX_Control(pDX, IDC_COMBO1, m_com1);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_LBString(pDX, IDC_DEPT, m_strDept);
	DDX_Slider(pDX, IDC_LOYAL, m_nLoyal);
	DDX_Text(pDX, IDC_EDIT2, m_ndeit2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog3, CDialog)
	//{{AFX_MSG_MAP(CDialog3)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_LBUTTONDOWN()
	ON_LBN_SELCHANGE(IDC_DEPT, OnSelchangeDept)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog3 message handlers

void CDialog3::OnOK() 
{
	// TODO: Add extra validation here
	AfxMessageBox("������ɣ�");

	//CDialog::OnOK();
}

BOOL CDialog3::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	CListBox* pLB = (CListBox*) GetDlgItem(IDC_DEPT);
	pLB->InsertString(-1, "��������ѧԺ");
	pLB->InsertString(-1, "����ҽѧԺ");
	pLB->InsertString(-1, "ҩѧԺ");
	pLB->InsertString(-1, "��ǻӰ��ϵ");
	pLB->InsertString(-1, "����ѧԺ");
	pLB->InsertString(-1, "����ѧԺ");
	pLB->InsertString(-1, "����ѧԺ");



/*	m_cb.AddString("�Ź�");
	m_cb.AddString("����");
	m_cb.AddString("����");
	m_cb.AddString("Ԥ��");
	m_cb.AddString("ʳƷ");
	m_cb.AddString("Ӫ��");*/


	CScrollBar* pSB = (CScrollBar*) GetDlgItem(IDC_LOYAL);
	pSB->SetScrollRange(nMin, nMax);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDialog3::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	int nTemp1, nTemp2;

	nTemp1 = pScrollBar->GetScrollPos();
	switch(nSBCode) {
	case SB_THUMBPOSITION:
		pScrollBar->SetScrollPos(nPos);
		break;
	case SB_LINELEFT: // left arrow button
		nTemp2 = (nMax - nMin) / 10;
		if ((nTemp1 - nTemp2) > nMin) {
			nTemp1 -= nTemp2;
		}
		else {
			nTemp1 = nMin;
		}
		pScrollBar->SetScrollPos(nTemp1);
		break;
	case SB_LINERIGHT: // right arrow button
		nTemp2 = (nMax - nMin) / 10;
		if ((nTemp1 + nTemp2) < nMax) {
			nTemp1 += nTemp2;
		}
		else {
			nTemp1 = nMax;
		}
		pScrollBar->SetScrollPos(nTemp1);
		break;
	}
}

void CDialog3::OnButton1() 
{
	// TODO: Add your control notification handler code here
	
	CDialog4 dlg;
	dlg.DoModal();
	CDialog::OnOK();
	
}

void CDialog3::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	//CDialog::OnLButtonDown(nFlags, point);
		
}

void CDialog3::OnSelchangeDept() 
{
	// TODO: Add your control notification handler code here
		CString ms;
	//m_cc.GetLBText(m_cc.GetCurSel(), ms);
	//AfxMessageBox(msg);
	

	m_cc.GetText(m_cc.GetCurSel(),ms);
	m_edit4.SetWindowText(ms);

	//CString tempRadio;
	
//	char buffer[10];

	//UpdateData(TRUE);                       // ʹ�øı�ʵʱ����׽

	//tempRadio=itoa(m_strDept,buffer,10);//������char *itoa(int value, char *string, int radix);
	                               //int value ��ת����������char *string ת���󴢴���ַ����飬int radix ת������������2,8,10,16 ���Ƶ�
	if (ms=="��������ѧԺ")
	{
		m_cb.ResetContent();
		m_cb.AddString("�Ź�");
		m_cb.AddString("����");
		m_cb.AddString("����");
		m_cb.AddString("Ԥ��");
		m_cb.AddString("ʳƷ");
		m_cb.AddString("Ӫ��");
	}
	if (ms=="����ҽѧԺ")
	{
		m_cb.ResetContent();
		m_cb.AddString("�ٴ�");
		m_cb.AddString("�ٴ���Ѫ");
		m_cb.AddString("�ٴ�ҩѧ");
	}
	if (ms=="����ѧԺ")
	{
		m_cb.ResetContent();
		m_cb.AddString("ҩ������");
		m_cb.AddString("��ר");
		m_cb.AddString("�챾");
	}
	if (ms=="����ѧԺ")
	{
		m_cb.ResetContent();
		m_cb.AddString("Ӧ������");
	}
	if (ms=="����ѧԺ")
	{
		m_cb.ResetContent();
		m_cb.AddString("Ӣ��");
		m_cb.AddString("����");
	}
	if (ms=="ҩѧԺ")
	{
		m_cb.ResetContent();
		m_cb.AddString("ҩ��");
		m_cb.AddString("�ٴ�ҩѧ");
	}
	if (ms=="��ǻӰ��ϵ")
	{
		m_cb.ResetContent();
		m_cb.AddString("��ǻ");
		m_cb.AddString("Ӱ��");
	}


}

void CDialog3::OnSelchangeList1() 
{
	// TODO: Add your control notification handler code here
	CString msg;
	
	m_cb.GetText(m_cb.GetCurSel(),msg);
	m_edit3.SetWindowText(msg);

}
