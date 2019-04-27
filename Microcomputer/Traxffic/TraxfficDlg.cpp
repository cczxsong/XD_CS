// TraxfficDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Traxffic.h"
#include "TraxfficDlg.h"
#include "stdio.h"
#include ".\qth9054fun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define P8255A     0
#define P8255B     1
#define P8255C     2
#define P8255MODE  3


unsigned char Codedistab[16] = { 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
0x80,0x90,    0x88,0x83,0xc6,0xa1,0x86,0x8e };//共阳数码管断码表


CWinThread	*Thread_Comd;	//要创建的两个线程
HWND hWnd;
BOOL ISSTART=false;

int redgreen_time = 15;
int yellow_time = 5;

//****************************************************//
//*********************数码管*************************//
//*****************************************************//

void night(){
	unsigned int con = 0x00;
	con = IO8bRead(P8255C)&0x10;
	if(con==0x10){
		IO8bWrite(P8255B,0x00);
		while((IO8bRead(P8255C)&0x10)==0x10){
			IO8bWrite(P8255A,0xF6);
			Sleep(500);
			IO8bWrite(P8255A,0xFF);
			Sleep(500);
		}
		IO8bWrite(P8255A,0x1B);
	}
}

void manCtrl(){
	unsigned int con = 0x00;
	con = IO8bRead(P8255C)&0x20;
	if(con==0x20){
		IO8bWrite(P8255B,0x00);
		while(IO8bRead(P8255C)&0x20){
			unsigned int choose = IO8bRead(P8255C);
			switch(choose&0xC0){
				case 0x00:   //全红
					IO8bWrite(P8255A,0x1B);
					break;
				case 0x40:	//东西红南北绿
					IO8bWrite(P8255A,0x2B);
					break;
				case 0x80:  //全绿
					IO8bWrite(P8255A,0x1D);
					break;
				case 0xC0:	//全黄
					IO8bWrite(P8255A,0x36);
					break;
				default:
					break;
			}
		}
		IO8bWrite(P8255A,0x1B);
	}
}

void count12(int num){	//绿灯数码管
//	int num = GreenL;
	while(num>=0){
		int j = 20;
		while(j--){
			IO8bWrite(P8255B,Codedistab[num/10]);
			IO8bWrite(P8255C,0x01);
			Sleep(1);
			IO8bWrite(P8255B,Codedistab[num%10]);
			IO8bWrite(P8255C,0x02);
			Sleep(1);
			night();
			manCtrl();
		}
		num--;
	}
}

void count34(int num) //黄灯数码管
{
	int j = 20;
	while(j--){
		
		IO8bWrite(P8255B,Codedistab[num/10]);
		IO8bWrite(P8255C,0x04);
		Sleep(1);
		IO8bWrite(P8255B,Codedistab[num%10]);
		IO8bWrite(P8255C,0x08);
		Sleep(1);
		night();
		manCtrl();
	}
}

//*****************************************************************************
//		/*初始状态全为红灯*/
//*****************************************************************************

void st0()
{
	IO8bWrite(P8255A,0x1b);
	Sleep(10);
}
//*****************************************************************************
//		/*南北为绿灯，东西为红灯子程序*/
//*****************************************************************************
void st1()
{
	IO8bWrite(P8255A,0x2B);
	count12(redgreen_time);
	//Sleep(800);
}
//*****************************************************************************
//		/*南北黄灯闪烁，东西为红灯子程序*/
//*****************************************************************************
void st2()
{
	int i =yellow_time;
	for(i;i>0;i--)
	{
		IO8bWrite(P8255A,0x33);
	    Sleep(20);
		count34(i);
		IO8bWrite(P8255A,0x3b);
		Sleep(20);
	}
	
}
//*****************************************************************************
//		/*南北为红灯，东西为绿灯子程序*/
//*****************************************************************************
void st3()
{
	IO8bWrite(P8255A,0x1d);
	count12(redgreen_time);
	//Sleep(800);
}				
//*****************************************************************************
//		/*南北为红灯，东西黄灯闪烁子程序*/
//*****************************************************************************
void st4()
{
	int i =yellow_time;
	for(i;i>0;i--)
	{
		IO8bWrite(P8255A,0x1e);
		Sleep(20);
		count34(i);
		IO8bWrite(P8255A,0x1f);
		Sleep(20);
	}
}


UINT Comd(LPVOID pParam)
{
	IO8bWrite(P8255MODE,0x88);
	st0();
	while(ISSTART) {
		st1();	   		//南北为绿灯，东西为红灯
		st2();  	 	//南北红灯闪烁，东西为红灯
		st3(); 		 	//南北为红灯，东西为绿灯
		st4(); 			//南北为红灯，东西黄灯闪烁
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	int		m_redgreen_time;
	int		m_yellow_time;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTraxfficDlg dialog

CTraxfficDlg::CTraxfficDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTraxfficDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTraxfficDlg)
		// NOTE: the ClassWizard will add member initialization here
	m_redgreen_time = 0;
	m_yellow_time = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTraxfficDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTraxfficDlg)
	DDX_Text(pDX, IDC_EDIT4, m_redgreen_time);
	DDX_Text(pDX, IDC_EDIT5, m_yellow_time);
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTraxfficDlg, CDialog)
	//{{AFX_MSG_MAP(CTraxfficDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON, OnButton)
	ON_EN_CHANGE(IDC_EDIT4, OnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, OnChangeEdit5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTraxfficDlg message handlers

BOOL CTraxfficDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	if (!Init9054())
	{
		return 0;
	}
	Thread_Comd=AfxBeginThread(Comd,NULL,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);	//创建KEYDOWN线程
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTraxfficDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTraxfficDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTraxfficDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTraxfficDlg::OnButton() 
{
	// TODO: Add your control notification handler code here
	if(!ISSTART){
		ISSTART=true;
		Thread_Comd->ResumeThread();
	}
}

void CTraxfficDlg::OnChangeEdit4() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(TRUE);//更新 m_redgreen_time
	redgreen_time=m_redgreen_time;
	// TODO: Add your control notification handler code here
	
}

void CTraxfficDlg::OnChangeEdit5() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(TRUE);//更新 m_yellow_time
	yellow_time=m_yellow_time;
	// TODO: Add your control notification handler code here
	
}
