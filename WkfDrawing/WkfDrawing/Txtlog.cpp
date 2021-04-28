// Txtlog.cpp : 实现文件
//

#include "stdafx.h"
#include "WkfDrawing.h"
#include "Txtlog.h"


// CTxtlog 对话框

IMPLEMENT_DYNAMIC(CTxtlog, CDialog)

CTxtlog::CTxtlog(CWnd* pParent /*=NULL*/)
	: CDialog(CTxtlog::IDD, pParent)
	, MyX(0)
	, MyY(0)
	, MyString(_T(""))
{

}

CTxtlog::~CTxtlog()
{
}

void CTxtlog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, ID_TXTX, MyX);
	DDX_Text(pDX, ID_TXTY, MyY);
	DDX_Text(pDX, ID_TXTS, MyString);
}


BEGIN_MESSAGE_MAP(CTxtlog, CDialog)
END_MESSAGE_MAP()


// CTxtlog 消息处理程序
