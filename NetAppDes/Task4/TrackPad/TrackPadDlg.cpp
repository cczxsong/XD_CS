// TrackPadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TrackPad.h"
#include "TrackPadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTrackPadDlg dialog




CTrackPadDlg::CTrackPadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTrackPadDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrackPadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_STATUS, mInfoLabel);
	DDX_Control(pDX, IDC_BUTTON_STARTSERVER, mBtnStartServer);
	DDX_Control(pDX, IDC_BUTTON_STOP_SERVER, mBtnStopServer);
}

BEGIN_MESSAGE_MAP(CTrackPadDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_STARTSERVER, &CTrackPadDlg::OnBnClickedButtonStartserver)
	ON_BN_CLICKED(IDC_BUTTON_STOP_SERVER, &CTrackPadDlg::OnBnClickedButtonStopServer)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_STN_CLICKED(IDC_STATIC_STATUS, &CTrackPadDlg::OnStnClickedStaticStatus)
END_MESSAGE_MAP()


// CTrackPadDlg message handlers

BOOL CTrackPadDlg::OnInitDialog()
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
	//���嶼����TrackpadDlg.h���涨��

	m_sListener.SetParentDlg(this); 
	m_sConnected.SetParentDlg(this);
	m_port = 20000;
	m_broadcastPort = m_port +1;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTrackPadDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTrackPadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTrackPadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//����socket����
void CTrackPadDlg::OnSocketAccept(void)
{
	//ip��ַ
	CString strIP;
	//�˿ں�
	UINT port;
	if(m_sListener.Accept(m_sConnected)){
		// stop broadcasting
		KillTimer(1);
		m_broadcaster.Close();
		//mfc�Ľ���socket����
		m_sConnected.GetSockName(strIP,port);
		mInfoLabel.SetWindowTextW(_T("Client Connected,IP :")+ strIP);
		UpdateData(FALSE);
	}else{
		AfxMessageBox(_T("Cannoot Accept Connection"));
	}
}

void CTrackPadDlg::OnSocketConnect(void)
{
	//mfc�����ı���
	mInfoLabel.SetWindowTextW(_T("Socket connected."));
}

void CTrackPadDlg::OnSocketReceive(void)
{
	//
	char *pBuf =new char [1025];
	CString strData;
	int iLen;
	iLen=m_sConnected.Receive(pBuf,1024);
	if(iLen==SOCKET_ERROR)	{
		AfxMessageBox(_T("Could not Recieve"));
	}else{
		 pBuf[iLen]=NULL;
		 strData=pBuf;
		 mInfoLabel.SetWindowTextW(strData);   //display in server
		 Tranlator(strData);
		 UpdateData(FALSE);
		 m_sConnected.Send(pBuf,iLen);
		 //m_sConnected.ShutDown(0);  
		 delete pBuf;
	}
}

//�Ͽ�socket����
void CTrackPadDlg::OnSocketClose(void)
{
	m_sConnected.Close(); 
	m_sListener.Close(); 
}


void CTrackPadDlg::OnBnClickedButtonStartserver()
{
	UpdateData(TRUE);
	// broadcast
	if(m_broadcaster.Create(m_broadcastPort,FD_WRITE,SOCK_DGRAM) == FALSE){
		CString message;
		message.Format(_T("Unable to create broadcast socket,Error code : %d"),GetLastError());
		AfxMessageBox(message);
		return;	
	}
	BOOL bOptVal = true;
	if(m_broadcaster.SetSockOpt(SO_BROADCAST,(void*)&bOptVal,sizeof(BOOL)) == SOCKET_ERROR) {
		CString message;
		message.Format(_T("Unable to setsockopt,Error code : %d"),GetLastError());
		AfxMessageBox(message);
		return;	
	}
	SetTimer(1, 200, 0);

	m_sListener.Create(m_port); 
	if(m_sListener.Listen()==FALSE)
	{
		CString message;
		message.Format(_T("Unable to m_sListener.Listen,Error code : %d"),GetLastError());
		AfxMessageBox(message);
		m_sListener.Close(); 
		return;
	}

	sockaddr SockAddr;
    int SockAddrLen;
	CString sLIP;
	//SockAddr.sockaddr_in.m_sListener.GetSockAddr(&SockAddr,&SockAddrLen);
	//sLIP=inet_ntoa(SockAddr.sa_data);

	mInfoLabel.SetWindowTextW(_T("Listening For Connections!!!"));
	UpdateData(FALSE);
	mBtnStartServer.EnableWindow(FALSE);
	mBtnStopServer.EnableWindow(TRUE); 
}

void CTrackPadDlg::OnBnClickedButtonStopServer()
{
	KillTimer(1);
	m_broadcaster.Close();
	m_sConnected.Close(); 
	m_sListener.Close(); 
	mInfoLabel.SetWindowTextW(_T("Oops stopped!!"));	
	UpdateData(FALSE);
	mBtnStartServer.EnableWindow(TRUE);
	mBtnStopServer.EnableWindow(FALSE); 
}

/*
Command :
MOUSEEVENTF_MOVE x y
MOUSEEVENTF_LEFTDOWN
MOUSEEVENTF_LEFTUP
MOUSEEVENTF_RIGHTDOWN
MOUSEEVENTF_RIGHTUP
MOUSEEVENTF_MIDDLEDOWN
MOUSEEVENTF_MIDDLEUP
MOUSEEVENTF_WHEEL WHEEL_DELTA

reference :
http://msdn.microsoft.com/en-us/library/windows/desktop/ms646273(v=vs.85).aspx
*/

//ת������,���ӿͻ��˷������ַ��������һ����ʽ����
void CTrackPadDlg::Tranlator(CString commandString)
{
	// get data first, command and data
	//���ַ����Կո�Ϊ�ָ����ֳ������ַ��������� command[3]��
	int nTokenPos = 0;
	CString strToken = commandString.Tokenize(_T(" "), nTokenPos);
	CString command[3];
	int i =0;
	while(!strToken.IsEmpty() && i < 3){
		command[i++] = strToken;
		strToken = commandString.Tokenize(_T(" "), nTokenPos);
	}
	//MFC���������Ϳ���
	
	INPUT in;
	//�������Ͷ���Ϊ���
	in.type = INPUT_MOUSE;
	//�����Ķ���
	in.mi.dx = 0;
	in.mi.dy = 0;
	in.mi.time = 0;
	in.mi.dwExtraInfo = 0;
	in.mi.mouseData = 0;
	//�ַ����ĳ��ȣ�Ϊ�˽������ַ���ת�����ַ����ʹ�õ�
	int l = command[0].GetLength();
	CString test = _T("MOUSEEVENTF_LEFTDOWN");

	int ll = test.GetLength();
	//����ƶ�
	//command[0]����궯�����ͣ��жϺ�ִ����Ӧ�Ķ���
	if(command[0].Find(_T("MOUSEEVENTF_MOVE")) == 0){
		in.mi.dwFlags = MOUSEEVENTF_MOVE;

		//_tstof�ǰ��ַ���ת����float���͵ĺ����������ŵĲ�����������˼�ǣ�
		//��conmmand��1���ַ�ת����ָ��command[1]���ַ�ָ�롣
		in.mi.dx = _tstof(command[1].GetBuffer(command[1].GetLength()));//command1��x����
		in.mi.dy = _tstof(command[2].GetBuffer(command[2].GetLength()));//command2��y����

		mouse_event(MOUSEEVENTF_MOVE,in.mi.dx,in.mi.dy,0,0);
	}
	else if(command[0].Find(_T("MOUSEEVENTF_LEFTDOWN")) == 0){
		in.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	}else if(command[0].Find(_T("MOUSEEVENTF_LEFTUP")) == 0){
		in.mi.dwFlags = MOUSEEVENTF_LEFTUP;

		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	}else if(command[0].Find(_T("MOUSEEVENTF_RIGHTDOWN")) == 0){
		in.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;

		mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	}else if(command[0].Find(_T("MOUSEEVENTF_RIGHTUP")) == 0){
		in.mi.dwFlags = MOUSEEVENTF_RIGHTUP;

		mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	}else if(command[0].Find(_T("MOUSEEVENTF_MIDDLEDOWN")) == 0){
		in.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;

		mouse_event(MOUSEEVENTF_MIDDLEDOWN,0,0,0,0);
	}else if(command[0].Find(_T("MOUSEEVENTF_MIDDLEUP")) == 0){
		in.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;

		mouse_event(MOUSEEVENTF_MIDDLEUP,0,0,0,0);
	}else if(command[0].Find(_T("MOUSEEVENTF_WHEEL")) == 0){
		in.mi.dwFlags = MOUSEEVENTF_WHEEL;
		in.mi.mouseData = WHEEL_DELTA * _tstof(command[1].GetBuffer(command[1].GetLength()));

		mouse_event(MOUSEEVENTF_MIDDLEDOWN,0,0,in.mi.mouseData,0);
	}else {
		return;
	}

	//SendInput(1,&in,sizeof(in));
}

void CTrackPadDlg::OnTimer(UINT_PTR nIDEvent)
{
	CString test = _T("broadcasting...");
	mInfoLabel.SetWindowTextW(test);	
	// broadcast
	IN_ADDR addr;
	addr.S_un.S_addr = INADDR_BROADCAST;
	CString ipaddr = CString(inet_ntoa(addr));
	int ret = m_broadcaster.SendTo(test.GetBuffer(test.GetLength()),test.GetLength()+1,m_broadcastPort);
	if(ret == SOCKET_ERROR){
	
		KillTimer(1);

		CString message;
		message.Format(_T("Unable to send broadcast message,Error code : %d"),GetLastError());
		AfxMessageBox(message);
		return;	
	}
	CDialog::OnTimer(nIDEvent);
}

void CTrackPadDlg::OnClose()
{
	KillTimer(1);
	m_broadcaster.Close();
	m_sConnected.Close(); 
	m_sListener.Close(); 

	CDialog::OnClose();
}


void CTrackPadDlg::OnStnClickedStaticStatus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
}
