#pragma once

#include "ofMain.h"
#include "HangulAutomata.h"
#include "ofxTrueTypeFontUC.h"

#define KB_ENGLISH	0
#define KB_HANGUL	1

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	void exit();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	bool keyIsDown[255];
	
	ofxTrueTypeFontUC *textFont;
	ofxTrueTypeFontUC *consoleFont;
	
	HangulAutomata automata;
	wstring m_wstrText = L"";
	string m_strText = "";
	string stringBuffer = "";
	
	map<char, int> m_HangulKeyTable;
	string ss;
	
	
	// input lang status
	int keyboardLanguage;
	int lastKeyComboCheckTimer;
	void toggleInputMethod();
	int getInputMethod();
	
};
