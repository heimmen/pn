/**
 * @file projpropsview.h
 * @brief Project Properties
 * @author Simon Steele
 * @note Copyright (c) 2004 Simon Steele <s.steele@pnotepad.org>
 *
 * Programmers Notepad 2 : The license file (license.[txt|html]) describes 
 * the conditions under which this source may be modified / distributed.
 */

#ifndef projpropsview_h__included
#define projpropsview_h__included

#include "include/proplist/propertylist.h"

class CProjPropsView : public CDialogImpl<CProjPropsView>
{
public:
	enum { IDD = IDD_PROJPROPS };

	BEGIN_MSG_MAP(CProjPropsView)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(IDOK, OnOK)
		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
		//NOTIFY_HANDLER(IDC_LIST1, PIN_BROWSE, OnBrowse)
		REFLECT_NOTIFICATIONS()
	END_MSG_MAP()

	void DisplayFor(Projects::ProjectType* pItem, Projects::ProjectTemplate* pTemplate);

protected:
	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	void displayGroups(Projects::PropGroupList& groups, HTREEITEM hParent = NULL);
	void displayCategories(Projects::PropCatList& categories);
	void displayProperties(Projects::PropList& properties);

protected:
	CPropertyListCtrl	m_props;
	Projects::PropSet*	m_pPropSet;
};

#endif // #ifndef projpropsview_h__included