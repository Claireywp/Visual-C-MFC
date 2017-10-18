#if !defined(AFX_DIALOG3_H__E14F749B_EF0A_4A4C_8291_89793F60E61D__INCLUDED_)
#define AFX_DIALOG3_H__E14F749B_EF0A_4A4C_8291_89793F60E61D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog3 dialog

class CDialog3 : public CDialog
{
	enum { nMin = 0 };
	enum { nMax = 100 };
// Construction
public:
	CDialog3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog3)
	enum { IDD = IDD_DIALOG3 };
	CListBox	m_cb;
	CEdit	m_edit4;
	CListBox	m_cc;
	CComboBox	m_com1;
	CEdit	m_edit3;
	CEdit	m_edit2;
	CString	m_strDept;
	int		m_nLoyal;
	CString	m_ndeit2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog3)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnButton1();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSelchangeDept();
	afx_msg void OnSelchangeList1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG3_H__E14F749B_EF0A_4A4C_8291_89793F60E61D__INCLUDED_)
