// CustomSocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TrackPad.h"
#include "TrackPadDlg.h"
#include "CustomSocket.h"


// CCustomSocket

CCustomSocket::CCustomSocket()
{
}

CCustomSocket::~CCustomSocket()
{
}


// CCustomSocket ��Ա����
void CCustomSocket::SetParentDlg(CDialog *pDlg)
{
m_pDlg=pDlg;
}


void CCustomSocket::OnAccept(int nErrorCode) 
{ 
	if(nErrorCode==0) 
	{ 
	((CTrackPadDlg*)m_pDlg)->OnSocketAccept(); 
	}
	CAsyncSocket::OnAccept(nErrorCode); 
} 

void CCustomSocket::OnConnect(int nErrorCode) 
{ 
	if(nErrorCode==0) 
	{ 
	((CTrackPadDlg*)m_pDlg)->OnSocketConnect(); 
	}
	CAsyncSocket::OnAccept(nErrorCode); 
} 

void CCustomSocket::OnReceive(int nErrorCode) 
{ 
	if(nErrorCode==0) 
	{ 
	((CTrackPadDlg*)m_pDlg)->OnSocketReceive(); 
	}
	CAsyncSocket::OnAccept(nErrorCode); 
} 

void CCustomSocket::OnClose(int nErrorCode)
{

	if(nErrorCode==0) 
	{ 
	((CTrackPadDlg*)m_pDlg)->OnSocketClose(); 
	}
	CAsyncSocket::OnClose(nErrorCode);
}

void CCustomSocket::OnOutOfBandData(int nErrorCode)
{
	CAsyncSocket::OnOutOfBandData(nErrorCode);
}

void CCustomSocket::OnSend(int nErrorCode)
{
	CAsyncSocket::OnSend(nErrorCode);
}
