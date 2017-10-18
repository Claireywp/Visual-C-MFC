// Dialog4.cpp : implementation file
//

#include "stdafx.h"
#include "stu.h"
#include "Dialog4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog4 dialog


CDialog4::CDialog4(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog4::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog4)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialog4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog4)
	DDX_Control(pDX, IDC_STATIC_LIST, m_edit_list);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog4, CDialog)
	//{{AFX_MSG_MAP(CDialog4)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_NOTIFY(LVN_ENDLABELEDIT, IDC_LIST1, OnEndlabeleditList1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, OnSelchangedTree1)
	ON_NOTIFY(TVN_ENDLABELEDIT, IDC_TREE1, OnEndlabeleditTree1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog4 message handlers

BOOL CDialog4::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	

	HICON hIcon[8];
	int n;
	m_imageList.Create(16, 16, 0, 8, 8); // 32, 32 for large icons
	hIcon[0] = AfxGetApp()->LoadIcon(IDI_WHITE);
	hIcon[1] = AfxGetApp()->LoadIcon(IDI_BLACK);
	hIcon[2] = AfxGetApp()->LoadIcon(IDI_RED);
	hIcon[3] = AfxGetApp()->LoadIcon(IDI_BLUE);
	hIcon[4] = AfxGetApp()->LoadIcon(IDI_YELLOW);
	hIcon[5] = AfxGetApp()->LoadIcon(IDI_CYAN);
	hIcon[6] = AfxGetApp()->LoadIcon(IDI_PURPLE);
	hIcon[7] = AfxGetApp()->LoadIcon(IDI_GREEN);
	for (n = 0; n < 8; n++) {
		m_imageList.Add(hIcon[n]);
	}

	static char* color[] = {"高数", "C语言", "线性代数",
	                        "JAVA语言", "概率统计", "管理学基础",
	                        "英语", "行政"};
	CListCtrl* pList =
		(CListCtrl*) GetDlgItem(IDC_LIST1);
	pList->SetImageList(&m_imageList, LVSIL_SMALL);
	for (n = 0; n < 8; n++) {
		pList->InsertItem(n, color[n], n);
	}
	pList->SetBkColor(RGB(0, 255, 255)); // UGLY!
	pList->SetTextBkColor(RGB(0, 255, 255));



	CTreeCtrl* pTree = (CTreeCtrl*) GetDlgItem(IDC_TREE1); 	
	pTree->SetImageList(&m_imageList, TVSIL_NORMAL); 
	TV_INSERTSTRUCT tvinsert;	 
	tvinsert.hParent = NULL;	
	tvinsert.hInsertAfter = TVI_LAST;
	tvinsert.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE| TVIF_TEXT; 
  					
	tvinsert.item.hItem = NULL;	
	tvinsert.item.state = 0;			
	tvinsert.item.stateMask = 0;	
	tvinsert.item.cchTextMax = 6;		
	tvinsert.item.iSelectedImage = 1;
	tvinsert.item.cChildren = 0;		
	tvinsert.item.lParam = 0;	
	// 创建第一层
	tvinsert.item.iImage = 2;	
	tvinsert.item.pszText = "计算机教研室";	
	HTREEITEM hDad = pTree ->InsertItem(&tvinsert);
	tvinsert.item.pszText = "数学教研室";
	HTREEITEM hMom = pTree->InsertItem(&tvinsert);
	// 创建第二层
	tvinsert.hParent = hDad;		
	tvinsert.item.iImage = 3;		
	tvinsert.item.pszText = "翁老师";
	HTREEITEM hOther = pTree->InsertItem(&tvinsert);
	tvinsert.item.pszText = "李老师";	
	pTree->InsertItem(&tvinsert);
	// 创建第三层
	tvinsert.hParent = hOther;		
	tvinsert.item.iImage = 7;
	tvinsert.item.pszText = "教授";	    
	pTree->InsertItem(&tvinsert);
	tvinsert.item.pszText = "教研室主任";    
	pTree->InsertItem(&tvinsert);

	tvinsert.hParent = hMom;	
	tvinsert.item.iImage = 4;
	tvinsert.item.pszText = "牛老师";		
	pTree->InsertItem(&tvinsert);
	tvinsert.item.pszText = "马老师";	
	pTree->InsertItem(&tvinsert);
	tvinsert.item.pszText = "邰老师";
	pTree->InsertItem(&tvinsert);
	





	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDialog4::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	CListCtrl* pList = (CListCtrl*) GetDlgItem(IDC_LIST1);
	int nSelected = pNMListView->iItem;
	if (nSelected >= 0) 
	{	CString strItem = pList->GetItemText(nSelected, 0);
		SetDlgItemText(IDC_STATIC_LIST, strItem);
	}
	*pResult = 0;

	CString ppp;
	m_edit_list.GetWindowText(ppp);
	m_edit1.SetWindowText(ppp);
}

void CDialog4::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	CListCtrl* pList = (CListCtrl*) GetDlgItem(IDC_LIST1);
	int nSelected = pNMListView->iItem;
	if (nSelected >= 0) 
		pList->EditLabel(nSelected);

	*pResult = 0;
}

void CDialog4::OnEndlabeleditList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	LVITEMA item = pDispInfo->item;
	CString str =item.pszText;	str.TrimLeft();
	str.TrimRight();
	if(str.GetLength() > 0)
	{  CListCtrl* pList = (CListCtrl*) GetDlgItem(IDC_LIST1);
	    pList->SetItemText(item.iItem, item.iSubItem, item.pszText);
	}

	*pResult = 0;
}

void CDialog4::OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	CTreeCtrl* pTree =(CTreeCtrl*) GetDlgItem(IDC_TREE1);
	HTREEITEM hSelected = pNMTreeView->itemNew.hItem;
	if (hSelected != NULL)
	 {	char text[31];		TV_ITEM item;
		item.mask = TVIF_HANDLE | TVIF_TEXT;
		item.hItem = hSelected;
		item.pszText = text;	item.cchTextMax = 30;
		VERIFY(pTree->GetItem(&item));
		SetDlgItemText(IDC_STATIC_TREE, text);
	}

	*pResult = 0;
}

void CDialog4::OnEndlabeleditTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	TVITEMA item = pTVDispInfo->item;
	CString str =item.pszText;
	str.TrimLeft();
	str.TrimRight();
	if(str.GetLength() > 0)
	{ CTreeCtrl* pTree =(CTreeCtrl*) GetDlgItem(IDC_TREE1);
	  pTree->SetItemText(item.hItem,item.pszText);	
	 }

	*pResult = 0;
}

void CDialog4::OnOK() 
{
	// TODO: Add extra validation here
	
	AfxMessageBox("注册完成！");
}

void CDialog4::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
