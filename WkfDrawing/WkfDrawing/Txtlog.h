#pragma once


// CTxtlog �Ի���

class CTxtlog : public CDialog
{
	DECLARE_DYNAMIC(CTxtlog)

public:
	CTxtlog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTxtlog();

// �Ի�������
	enum { IDD = IDD_TEXT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int MyX;
public:
	int MyY;
public:
	CString MyString;
};
