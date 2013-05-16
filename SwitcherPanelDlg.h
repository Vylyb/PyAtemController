/* -LICENSE-START-
** Copyright (c) 2011 Blackmagic Design
**
** Permission is hereby granted, free of charge, to any person or organization
** obtaining a copy of the software and accompanying documentation covered by
** this license (the "Software") to use, reproduce, display, distribute,
** execute, and transmit the Software, and to prepare derivative works of the
** Software, and to permit third-parties to whom the Software is furnished to
** do so, all subject to the following:
** 
** The copyright notices in the Software and this entire statement, including
** the above license grant, this restriction and the following disclaimer,
** must be included in all copies of the Software, in whole or in part, and
** all derivative works of the Software, unless such copies or derivative
** works are solely in the form of machine-executable object code generated by
** a source language processor.
** 
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
** SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
** FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
** ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
** -LICENSE-END-
*/

#pragma once

#include "BMDSwitcherAPI_h.h"
#include <list>
#include <vector>
#include "afxwin.h"
#include "afxcmn.h"

#define INPUT_Black					0
#define INPUT_C1					1
#define INPUT_C2					2
#define INPUT_C3					3
#define INPUT_C4					4
#define INPUT_C5					5
#define INPUT_C6					6
#define INPUT_Color_Bars			7
#define INPUT_Color_1				8
#define INPUT_Color_2				9
#define INPUT_Media_Player_1		10
#define INPUT_Media_Player_1_Key	11
#define INPUT_Media_Player_2		12
#define INPUT_Media_Player_2_Key	13
#define INPUT_Program				14
#define INPUT_Preview				15
#define INPUT_Clean_Feed_1			16
#define INPUT_Clean_Feed_2			17

#define AUDIO_INPUT_1	0
#define AUDIO_INPUT_2	1
#define AUDIO_INPUT_3	2
#define AUDIO_INPUT_4	3
#define AUDIO_INPUT_5	4
#define AUDIO_INPUT_6	5

class MixEffectBlockMonitor;
class SwitcherMonitor;
class InputMonitor;
class AudioMixerMonitor;
class AudioInputMonitor;

// CSwitcherPanelDlg dialog
class CSwitcherPanelDlg : public CDialog
{
	// Construction
public:
	CSwitcherPanelDlg(CWnd* pParent = NULL);	// standard constructor

	// Dialog Data
	enum { IDD = IDD_SWITCHERPANEL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Implementation
protected:
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedAuto();
	afx_msg void OnBnClickedCut();
	afx_msg void OnBnClickedFTB();
	afx_msg void OnProgramInputChanged();
	afx_msg void OnPreviewInputChanged();

private:
	void switcherConnected();
	void switcherDisconnected();
	void updateSliderPosition();
	void updateTransitionFramesText();
	void setInputGainSliderPosition(int inputID, double gain);
	void updateFTBFramesText();
	void setProgramInput(BMDSwitcherInputId id);
	void setPreviewInput(BMDSwitcherInputId id);
	LRESULT OnMixEffectBlockProgramInputChanged(WPARAM wParam, LPARAM lParam);
	LRESULT OnMixEffectBlockPreviewInputChanged(WPARAM wParam, LPARAM lParam);
	LRESULT OnMixEffectBlockInTransitionChanged(WPARAM wParam, LPARAM lParam);
	LRESULT OnMixEffectBlockTransitionPositionChanged(WPARAM wParam, LPARAM lParam);
	LRESULT OnMixEffectBlockTransitionFramesRemainingChanged(WPARAM wParam, LPARAM lParam);
	LRESULT OnMixEffectBlockFTBFramesRemainingChanged(WPARAM wParam, LPARAM lParam);
	LRESULT OnSwitcherInputLongnameChanged(WPARAM wParam, LPARAM lParam);
	LRESULT OnSwitcherDisconnected(WPARAM wParam, LPARAM lParam);
	LRESULT OnAudioMixerMasterGainChanged(WPARAM wParam, LPARAM lParam);
	LRESULT OnAudioMixerMasterBalanceChanged(WPARAM wParam, LPARAM lParam);
	LRESULT OnAudioInputGainChanged(WPARAM wParam, LPARAM lParam);
	LRESULT OnAudioInputBalanceChanged(WPARAM wParam, LPARAM lParam);
	void mixEffectBlockBoxSetEnabled(BOOL enabled);

	CEdit						mEditAddress;
	CButton						mButtonConnect;
	CEdit						mEditName;
	CSliderCtrl					mSlider;
	CButton						mButtonAuto;
	CButton						mButtonCut;
	CButton						mButtonFTB;

	// Audio
	IBMDSwitcherAudioMixer*		mAudioMixer;
	AudioMixerMonitor*			mAudioMixerMonitor;
	std::vector<AudioInputMonitor*>	mAudioInputMonitors;
	std::vector<double>			currentGainInputs;

	IBMDSwitcherDiscovery*		mSwitcherDiscovery;
	IBMDSwitcher*				mSwitcher;
	IBMDSwitcherMixEffectBlock*	mMixEffectBlock;
	MixEffectBlockMonitor*		mMixEffectBlockMonitor;
	SwitcherMonitor*			mSwitcherMonitor;
	std::list<InputMonitor*>	mInputMonitors;
	BOOL						mMoveSliderDownwards;
	BOOL						mCurrentTransitionReachedHalfway;
	double						sliderRange,minGain,maxGain;
	CFont						standardFont,enhancedFont;

public:
	afx_msg void OnBnClickedButtonProgInput9();
	afx_msg void OnBnClickedButtonProgInput1();
	afx_msg void OnBnClickedButtonProgBlack();
	afx_msg void OnBnClickedButtonProgBars();
	afx_msg void OnBnClickedButtonProgInput2();
	afx_msg void OnBnClickedButtonProgInput3();
	afx_msg void OnBnClickedButtonProgInput4();
	afx_msg void OnBnClickedButtonProgInput5();
	afx_msg void OnBnClickedButtonProgInput6();
	afx_msg void OnBnClickedButtonProgInput7();
	afx_msg void OnBnClickedButtonProgInput8();
	afx_msg void OnBnClickedButtonProgColor1();
	afx_msg void OnBnClickedButtonProgColor2();
	afx_msg void OnBnClickedButtonProgMedia1();
	afx_msg void OnBnClickedButtonProgMedia2();
	afx_msg void OnBnClickedButtonPrevInput1();
	afx_msg void OnBnClickedButtonPrevInput2();
	afx_msg void OnBnClickedButtonPrevInput3();
	afx_msg void OnBnClickedButtonPrevInput4();
	afx_msg void OnBnClickedButtonPrevInput5();
	afx_msg void OnBnClickedButtonPrevInput6();
	afx_msg void OnBnClickedButtonPrevInput7();
	afx_msg void OnBnClickedButtonPrevInput8();
	afx_msg void OnBnClickedButtonPrevColor1();
	afx_msg void OnBnClickedButtonPrevColor2();
	afx_msg void OnBnClickedButtonPrevMedia1();
	afx_msg void OnBnClickedButtonPrevMedia2();
	afx_msg void OnBnClickedButtonPrevBlack();
	afx_msg void OnBnClickedButtonPrevBars();
	CButton mButtonProgInput1;
	CButton mButtonProgInput2;
	CButton mButtonProgInput3;
	CButton mButtonProgInput4;
	CButton mButtonProgInput5;
	CButton mButtonProgInput6;
	CButton mButtonProgInputColor;
	CButton mButtonProgInputColor2;
	CButton mButtonProgMediaPlayer;
	CButton mButtonProgMediaPlayer2;
	CButton mButtonProgBlack;
	CButton mButtonProgBars;
	CButton mButtonPrevInput1;
	CButton mButtonPrevInput2;
	CButton mButtonPrevInput3;
	CButton mButtonPrevInput4;
	CButton mButtonPrevInput5;
	CButton mButtonPrevInput6;
	CButton mButtonPrevInputColor;
	CButton mButtonPrevInputColor2;
	CButton mButtonPrevMediaPlayer;
	CButton mButtonPrevMediaPlayer2;
	CButton mButtonPrevBlack;
	CButton mButtonPrevBars;
private:
	CSliderCtrl mSliderMasterVolume;
	void addOutputLine(CString str);
	void updateMasterGain();
	void updateMasterBalance();
	double currentMasterGain;
	void setInputGain(double gain, int inputID);
	void setInputBalance(double balance, int inputID);
	void muteInput(int inputID);
	void updateInputGain(int inputID);
	void updateInputBalance(int inputID);
public:
	CEdit mEditOutput;
	afx_msg void OnBnClickedButtonAudioMute();
	CEdit mEditMasterBalance;
	CSliderCtrl mSliderMasterBalance;
	CEdit mEditMasterVolume;
	CButton mButtonMasterMute;
	CProgressCtrl mAudioMasterLevelLeft;
	CProgressCtrl mAudioMasterLevelRight;
	CSliderCtrl mSliderGainInput1;
	CSliderCtrl mSliderGainInput2;
	CSliderCtrl mSliderGainInput3;
	CSliderCtrl mSliderGainInput4;
	CSliderCtrl mSliderGainInput5;
	CSliderCtrl mSliderGainInput6;
	CButton mButtonMuteInput1;
	CButton mButtonMuteInput2;
	CButton mButtonMuteInput3;
	CButton mButtonMuteInput4;
	CButton mButtonMuteInput5;
	CButton mButtonMuteInput6;
	CSliderCtrl mSliderBalanceInput1;
	CSliderCtrl mSliderBalanceInput2;
	CSliderCtrl mSliderBalanceInput3;
	CSliderCtrl mSliderBalanceInput4;
	CSliderCtrl mSliderBalanceInput5;
	CSliderCtrl mSliderBalanceInput6;
	CEdit mEditBalanceInput1;
	CEdit mEditBalanceInput2;
	CEdit mEditBalanceInput3;
	CEdit mEditBalanceInput4;
	CEdit mEditBalanceInput5;
	CEdit mEditBalanceInput6;
	CEdit mEditGainInput1;
	CEdit mEditGainInput2;
	CEdit mEditGainInput3;
	CEdit mEditGainInput4;
	CEdit mEditGainInput5;
	CEdit mEditGainInput6;
	afx_msg void OnBnClickedButtonMuteInput1();
	afx_msg void OnBnClickedButtonMuteInput2();
	afx_msg void OnBnClickedButtonMuteInput3();
	afx_msg void OnBnClickedButtonMuteInput4();
	afx_msg void OnBnClickedButtonMuteInput5();
	afx_msg void OnBnClickedButtonMuteInput6();
};
