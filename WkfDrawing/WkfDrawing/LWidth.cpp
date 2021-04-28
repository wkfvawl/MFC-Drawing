// LWidth.cpp : 实现文件
//

#include "stdafx.h"
#include "WkfDrawing.h"
#include "LWidth.h"


// CLWidth 对话框

IMPLEMENT_DYNAMIC(CLWidth, CDialog)

CLWidth::CLWidth(CWnd* pParent /*=NULL*/)
	: CDialog(CLWidth::IDD, pParent)
	, width(0)
{

}

CLWidth::~CLWidth()
{
}

void CLWidth::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, ID_SLW, width);//输入画笔宽度对话框ID_SLW
}


BEGIN_MESSAGE_MAP(CLWidth, CDialog)
END_MESSAGE_MAP()


// CLWidth 消息处理程序
