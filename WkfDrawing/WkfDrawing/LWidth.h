#pragma once


// CLWidth �Ի���

class CLWidth : public CDialog
{
	DECLARE_DYNAMIC(CLWidth)

public:
	CLWidth(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLWidth();

// �Ի�������
	enum { IDD = IDD_Width };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int width;//���ʿ��
};
