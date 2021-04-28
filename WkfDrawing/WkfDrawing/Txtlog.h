#pragma once


// CTxtlog 对话框

class CTxtlog : public CDialog
{
	DECLARE_DYNAMIC(CTxtlog)

public:
	CTxtlog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTxtlog();

// 对话框数据
	enum { IDD = IDD_TEXT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int MyX;
public:
	int MyY;
public:
	CString MyString;
};
