#ifndef STATUS_ITEMS_H
#define STATUS_ITEMS_H


#include "StatusView.h"
#include "Tooltip.h"
#include "EventInfoPopup.h"


enum {
	STATUS_ITEM_CHANNEL,
	STATUS_ITEM_VIDEOSIZE,
	STATUS_ITEM_VOLUME,
	STATUS_ITEM_AUDIOCHANNEL,
	STATUS_ITEM_RECORD,
	STATUS_ITEM_CAPTURE,
	STATUS_ITEM_ERROR,
	STATUS_ITEM_SIGNALLEVEL,
	STATUS_ITEM_CLOCK,
	STATUS_ITEM_PROGRAMINFO,
	STATUS_ITEM_BUFFERING,
	STATUS_ITEM_TUNER,
	STATUS_ITEM_MEDIABITRATE,
	STATUS_ITEM_FAVORITES
};
#define STATUS_ITEM_FIRST	STATUS_ITEM_CHANNEL
#define STATUS_ITEM_LAST	STATUS_ITEM_FAVORITES


class CChannelStatusItem : public CStatusItem
{
public:
	CChannelStatusItem();
// CStatusItem
	LPCTSTR GetName() const override { return TEXT("チャンネル"); }
	void Draw(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void DrawPreview(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void OnLButtonDown(int x,int y) override;
	void OnRButtonDown(int x,int y) override;
};

class CVideoSizeStatusItem : public CStatusItem
{
public:
	CVideoSizeStatusItem();
// CStatusItem
	LPCTSTR GetName() const override { return TEXT("映像サイズ"); }
	void Draw(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void DrawPreview(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void OnLButtonDown(int x,int y) override;
	void OnRButtonDown(int x,int y) override;
};

class CVolumeStatusItem : public CStatusItem
{
public:
	CVolumeStatusItem();
// CStatusItem
	LPCTSTR GetName() const override { return TEXT("音量"); }
	void Draw(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void OnLButtonDown(int x,int y) override;
	void OnRButtonDown(int x,int y) override;
	void OnMouseMove(int x,int y) override;
	void SetStyle(const TVTest::Style::CStyleManager *pStyleManager) override;
	void NormalizeStyle(const TVTest::Style::CStyleManager *pStyleManager) override;

private:
	TVTest::Style::IntValue m_BarHeight;
	TVTest::Style::Margins m_BarPadding;
	TVTest::Style::IntValue m_BarBorderWidth;
};

class CAudioChannelStatusItem : public CStatusItem
{
public:
	CAudioChannelStatusItem();
// CStatusItem
	LPCTSTR GetName() const override { return TEXT("音声"); }
	void Draw(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void DrawPreview(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void OnLButtonDown(int x,int y) override;
	void OnRButtonDown(int x,int y) override;

private:
	DrawUtil::CMonoColorIconList m_Icons;
};

class CRecordStatusItem : public CStatusItem
{
	COLORREF m_CircleColor;
	bool m_fRemain;
	CTooltip m_Tooltip;

	int GetTipText(LPTSTR pszText,int MaxLength);

public:
	CRecordStatusItem();
// CStatusItem
	LPCTSTR GetName() const override { return TEXT("録画"); }
	void Draw(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void DrawPreview(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void OnLButtonDown(int x,int y) override;
	void OnRButtonDown(int x,int y) override;
	bool OnMouseHover(int x,int y) override;
	void OnFocus(bool fFocus) override;
	LRESULT OnNotifyMessage(LPNMHDR pnmh) override;
// CUIBase
	void SetTheme(const TVTest::Theme::CThemeManager *pThemeManager) override;
// CRecordStatusItem
	void ShowRemainTime(bool fRemain);
	void SetCircleColor(COLORREF Color);
};

class CCaptureStatusItem : public CIconStatusItem
{
public:
	CCaptureStatusItem();
// CStatusItem
	LPCTSTR GetName() const override { return TEXT("キャプチャ"); }
	void Draw(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void OnLButtonDown(int x,int y) override;
	void OnRButtonDown(int x,int y) override;

private:
	DrawUtil::CMonoColorIconList m_Icons;
};

class CErrorStatusItem : public CStatusItem
{
public:
	CErrorStatusItem();
// CStatusItem
	LPCTSTR GetName() const override { return TEXT("エラー"); }
	void Draw(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void DrawPreview(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void OnLButtonDown(int x,int y) override;
	void OnRButtonDown(int x,int y) override;
};

class CSignalLevelStatusItem : public CStatusItem
{
	bool m_fShowSignalLevel;

public:
	CSignalLevelStatusItem();
// CStatusItem
	LPCTSTR GetName() const override { return TEXT("信号レベル"); }
	void Draw(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void DrawPreview(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
// CSignalLevelStatusItem
	void ShowSignalLevel(bool fShow);
};

class CClockStatusItem : public CStatusItem
{
	bool m_fTOT;

public:
	CClockStatusItem();
// CStatusItem
	LPCTSTR GetName() const override { return TEXT("時計"); }
	void Draw(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void DrawPreview(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void OnLButtonDown(int x,int y) override;
	void OnRButtonDown(int x,int y) override;
// CClockStatusItem
	void SetTOT(bool fTOT);
	bool IsTOT() const { return m_fTOT; }
};

class CProgramInfoStatusItem : public CStatusItem
{
	bool m_fNext;
	bool m_fEnablePopupInfo;
	CEventInfoPopup m_EventInfoPopup;
	CDynamicString m_Text;

	void ShowPopupInfo();

public:
	CProgramInfoStatusItem();
// CStatusItem
	LPCTSTR GetName() const override { return TEXT("番組情報"); }
	void Draw(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void DrawPreview(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void OnLButtonDown(int x,int y) override;
	void OnRButtonDown(int x,int y) override;
	void OnLButtonDoubleClick(int x,int y) override;
	void OnFocus(bool fFocus) override;
	bool OnMouseHover(int x,int y) override;
// CProgramInfoStatusItem
	void EnablePopupInfo(bool fEnable);
	bool UpdateContent();
	bool SetEventInfoFont(const LOGFONT *pFont) {
		return m_EventInfoPopup.SetFont(pFont);
	}
};

class CBufferingStatusItem : public CStatusItem
{
public:
	CBufferingStatusItem();
// CStatusItem
	LPCTSTR GetName() const override { return TEXT("バッファリング"); }
	void Draw(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void DrawPreview(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void OnLButtonDown(int x,int y) override;
};

class CTunerStatusItem : public CStatusItem
{
public:
	CTunerStatusItem();
// CStatusItem
	LPCTSTR GetName() const override { return TEXT("チューナー"); }
	void Draw(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void DrawPreview(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void OnLButtonDown(int x,int y) override;
	void OnRButtonDown(int x,int y) override;
};

class CMediaBitRateStatusItem : public CStatusItem
{
public:
	CMediaBitRateStatusItem();
// CStatusItem
	LPCTSTR GetName() const override { return TEXT("ビットレート"); }
	void Draw(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void DrawPreview(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
};

class CFavoritesStatusItem : public CIconStatusItem
{
public:
	CFavoritesStatusItem();
// CStatusItem
	LPCTSTR GetName() const override { return TEXT("お気に入り"); }
	void Draw(HDC hdc,const RECT &ItemRect,const RECT &DrawRect) override;
	void OnLButtonDown(int x,int y) override;
	void OnRButtonDown(int x,int y) override;

private:
	DrawUtil::CMonoColorIconList m_Icons;
};


#endif
