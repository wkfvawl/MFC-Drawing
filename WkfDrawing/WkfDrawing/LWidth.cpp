// LWidth.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WkfDrawing.h"
#include "LWidth.h"


// CLWidth �Ի���

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
	DDX_Text(pDX, ID_SLW, width);//���뻭�ʿ�ȶԻ���ID_SLW
}


BEGIN_MESSAGE_MAP(CLWidth, CDialog)
END_MESSAGE_MAP()


// CLWidth ��Ϣ�������
