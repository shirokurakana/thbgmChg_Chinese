﻿// thbgmChg2.cpp : アプリケーションのクラス動作を定義します。
//

#include "stdafx.h"
#include "thbgmChg2.h"
#include "thbgmChg2Dlg.h"
#include "IniDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CthbgmChg2App

BEGIN_MESSAGE_MAP(CthbgmChg2App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CthbgmChg2App コンストラクション

CthbgmChg2App::CthbgmChg2App()
{
	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}


// 唯一の CthbgmChg2App オブジェクトです。

CthbgmChg2App theApp;


// CthbgmChg2App 初期化

BOOL CthbgmChg2App::InitInstance()
{
	// アプリケーション マニフェストが visual スタイルを有効にするために、
	// ComCtl32.dll Version 6 以降の使用を指定する場合は、
	// Windows XP に InitCommonControlsEx() が必要です。さもなければ、ウィンドウ作成はすべて失敗します。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// アプリケーションで使用するすべてのコモン コントロール クラスを含めるには、
	// これを設定します。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// 標準初期化
	// これらの機能を使わずに最終的な実行可能ファイルの
	// サイズを縮小したい場合は、以下から不要な初期化
	// ルーチンを削除してください。
	// 設定が格納されているレジストリ キーを変更します。
	// TODO: 会社名または組織名などの適切な文字列に
	// この文字列を変更してください。
	SetRegistryKey(_T("アプリケーション ウィザードで生成されたローカル アプリケーション"));

	SetThreadLocale(MAKELCID(MAKELANGID(LANG_JAPANESE, SUBLANG_JAPANESE_JAPAN), SORT_JAPANESE_XJIS));

	CIniDlg IniDlg;
	if( IniDlg.DoModal() == IDOK ){
		CthbgmChg2Dlg dlg;
		m_pMainWnd = &dlg;
		INT_PTR nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: ダイアログが <OK> で消された時のコードを
			//  記述してください。
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: ダイアログが <キャンセル> で消された時のコードを
			//  記述してください。
		}
	}

	// ダイアログは閉じられました。アプリケーションのメッセージ ポンプを開始しないで
	//  アプリケーションを終了するために FALSE を返してください。
	return FALSE;
}
