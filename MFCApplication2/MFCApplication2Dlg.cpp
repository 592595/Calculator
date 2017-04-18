
// MFCApplication2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include<stack>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string a = "";

//判断大小的函数
int change(char a)
{
	if (a == '(')
		return 1;
	else if (a == '+')
		return 2;
	else if (a == '-')
		return 2;
	else if (a == '*')
		return 3;
	else if (a == '/')
		return 3;
}
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 对话框



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication2Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication2Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication2Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication2Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication2Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication2Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication2Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication2Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication2Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCApplication2Dlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFCApplication2Dlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication2Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON19, &CMFCApplication2Dlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication2Dlg::OnBnClickedButton16)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 消息处理程序

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnBnClickedButton13()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + "+";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton14()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + "*";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton10()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + "0";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton11()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a.substr(0, a.length() - 1);
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton12()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + ".";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton7()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + "1";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton8()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + "2";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton9()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + "3";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + "4";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + "5";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + "6";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + "7";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + "8";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + "9";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton17()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + "-";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton18()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + "/";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton15()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + "(";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton19()
{
	// TODO:  在此添加控件通知处理程序代码
	a = a + ")";
	CString b;
	b = a.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(b);
}


void CMFCApplication2Dlg::OnBnClickedButton16()//等于号
{
	// TODO:  在此添加控件通知处理程序代码
	stack<double> nu;
	stack<char> ch;
	int t = 0;
	int r = 0;
	if (a[0] == '-')
	{
		t = 1;
		r = 1;
	}
	int n;
	n = a.size();
	int i;
	for (i = r; i < n; i++)
	{
		if ('0' <= a[i] && a[i] <= '9')
		{
			int j = 0;
			char b[20] = { '0' };
			while (1)
			{
				if ('0' > a[i] && a[i] != '.' || a[i] > '9' && a[i] != '.')
				{
					i--;
					double q;
					q = atof(b);
					nu.push(q);
					break;
				}
				if (t == 1)
				{
					b[j] = '-';
					j++;
					t = 0;
				}
				b[j] = a[i];
				j++;
				i++;
			}
		}
		/////////////////////////////////////////////
		else if (a[i] == '+')
		{
			if (ch.empty() || change(ch.top()) < 2)
			{
				ch.push('+');
			}
			else
			{
				if (ch.top() == '*')
				{
					double x;
					double y;
					x = nu.top();
					nu.pop();
					y = nu.top();
					nu.top() = y*x;
					ch.pop();
				}
				else if (ch.top() == '/')
				{
					double x;
					double y;
					x = nu.top();
					nu.pop();
					y = nu.top();
					nu.top() = y/x;
					ch.pop();
				}
				else if (ch.top() == '-')
				{
					double x;
					double y;
					x = nu.top();
					nu.pop();
					y = nu.top();
					nu.top() = y-x;
					ch.pop();
				}
				else if (ch.top() == '+')
				{
					double x;
					double y;
					x = nu.top();
					nu.pop();
					y = nu.top();
					nu.top() = y+x;
					ch.pop();
				}
				ch.push('+');
			}
		}
		////////////////////////////////////////////////////////////
		else if (a[i] == '-')
		{
			if (ch.empty() || change(ch.top()) < 2)
			{
				ch.push('-');
			}
			else
			{
				if (ch.top() == '*')
				{
					double x;
					double y;
					x = nu.top();
					nu.pop();
					y = nu.top();
					nu.top() = y*x;
					ch.pop();
				}
				else if (ch.top() == '/')
				{
					double x;
					double y;
					x = nu.top();
					nu.pop();
					y = nu.top();
					nu.top() = y / x;
					ch.pop();
				}
				else if (ch.top() == '-')
				{
					double x;
					double y;
					x = nu.top();
					nu.pop();
					y = nu.top();
					nu.top() = y - x;
					ch.pop();
				}
				else if (ch.top() == '+')
				{
					double x;
					double y;
					x = nu.top();
					nu.pop();
					y = nu.top();
					nu.top() = y + x;
					ch.pop();
				}
				ch.push('-');
			}
		}
		///////////////////////////////////////////////////
		else if (a[i] == '*')
		{
			ch.push('*');
		}
		/////////////////////////////////
		else if (a[i] == '/')
		{
			ch.push('/');
		}
		///////////////////////////////
		else if (a[i] == '(')
		{
			ch.push('(');
		}
		//////////////////////////////
		else if (a[i] == ')')
		{
			while (ch.top() != '(')
			{
				if (ch.top() == '+')
				{
					double x;
					double y;
					x = nu.top();
					nu.pop();
					y = nu.top();
					nu.top() = y + x;
					ch.pop();
				}
				else if (ch.top() == '-')
				{
					double x;
					double y;
					x = nu.top();
					nu.pop();
					y = nu.top();
					nu.top() = y - x;
					ch.pop();
				}
				else if (ch.top() == '*')
				{
					double x;
					double y;
					x = nu.top();
					nu.pop();
					y = nu.top();
					nu.top() = y * x;
					ch.pop();
				}
				else if (ch.top() == '/')
				{
					double x;
					double y;
					x = nu.top();
					nu.pop();
					y = nu.top();
					nu.top() = y / x;
					ch.pop();
				}
			}
			ch.pop();
		}

	/////////////////////////////////////////////////////////////////////
	}
	while (ch.size()!=0)
	{
		if (ch.top() == '+')
		{
			double x;
			double y;
			x = nu.top();
			nu.pop();
			y = nu.top();
			nu.top() = y + x;
			ch.pop();
		}
		else if (ch.top() == '-')
		{
			double x;
			double y;
			x = nu.top();
			nu.pop();
			y = nu.top();
			nu.top() = y - x;
			ch.pop();
		}
		else if (ch.top() == '*')
		{
			double x;
			double y;
			x = nu.top();
			nu.pop();
			y = nu.top();
			nu.top() = y * x;
			ch.pop();
		}
		else if (ch.top() == '/')
		{
			double x;
			double y;
			x = nu.top();
			nu.pop();
			y = nu.top();
			nu.top() = y / x;
			ch.pop();
		}
	}
	string s;
	stringstream ss;
	ss << nu.top();
	ss >> s;
	a = s;
	CString c;
	c = s.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowText(c);

}
