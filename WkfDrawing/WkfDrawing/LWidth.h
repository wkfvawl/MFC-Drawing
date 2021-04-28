#pragma once


// CLWidth 对话框

class CLWidth : public CDialog
{
	DECLARE_DYNAMIC(CLWidth)

public:
	CLWidth(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLWidth();

// 对话框数据
	enum { IDD = IDD_Width };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int width;//画笔宽度
};
