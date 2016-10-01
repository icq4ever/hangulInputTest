#pragma once

#include "ofMain.h"
#include "AutomataKR.h"
#include "ofxTrueTypeFontUC.h"

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
	
	void string2wstring(wstring &dest, const string &src);
	void wstring2string(string &dest, const wstring &src);

	ofxTrueTypeFontUC *textFont;
	
	CAutomataKR automataKR;
	wstring m_wstrText = L"";
	string m_strText = "";
	
	string message = "안녕하세용";
	
	wchar_t kr = L'가';

	map<char, int> m_HangulKeyTable;
};
