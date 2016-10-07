#include "ofApp.h"
#include <codecvt>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetLogLevel(OF_LOG_SILENT);
	ofSetFrameRate(60);
	//	automateKR = new AutomateKR();
	wcout.imbue(locale("en_US.UTF-8"));
	
	// loadFont
	textFont = new ofxTrueTypeFontUC();
	consoleFont = new ofxTrueTypeFontUC();
	textFont->loadFont("AppleSDGothicNeo-Regular.otf", 30, true, true);
	consoleFont->loadFont("Andale Mono.ttf", 16, true, true);
	
	
	m_HangulKeyTable['q']	=   7;	// ㅂ
	m_HangulKeyTable['Q']	=   8;	// ㅃ
	m_HangulKeyTable['w']	=  12;	// ㅈ
	m_HangulKeyTable['W']	=  13;	// ㅉ
	m_HangulKeyTable['e']	=   3;	// ㄷ
	m_HangulKeyTable['E']	=   4;	// ㄸ
	m_HangulKeyTable['r']	=   0;	// ㄱ
	m_HangulKeyTable['R']	=   1;	// ㄲ
	m_HangulKeyTable['t']	=   9;	// ㅅ
	m_HangulKeyTable['T']	=  10;	// ㅆ
	m_HangulKeyTable['y']	=  31;	// ㅛ
	m_HangulKeyTable['Y']	=  31;	// ㅛ
	m_HangulKeyTable['u']	=  25;	// ㅕ
	m_HangulKeyTable['U']	=  25;	// ㅕ
	m_HangulKeyTable['i']	=  21;	// ㅑ
	m_HangulKeyTable['I']	=  21;	// ㅑ
	m_HangulKeyTable['o']	=  20;	// ㅐ
	m_HangulKeyTable['O']	=  22;	// ㅒ
	m_HangulKeyTable['p']	=  24;	// ㅔ
	m_HangulKeyTable['P']	=  26;	// ㅖ
	m_HangulKeyTable['a']	=   6;	// ㅁ
	m_HangulKeyTable['A']	=   6;	// ㅁ
	m_HangulKeyTable['s']	=   2;	// ㄴ
	m_HangulKeyTable['S']	=   2;	// ㄴ
	m_HangulKeyTable['d']	=  11;	// ㅇ
	m_HangulKeyTable['D']	=  11;	// ㅇ
	m_HangulKeyTable['f']	=   5;	// ㄹ
	m_HangulKeyTable['F']	=   5;	// ㄹ
	m_HangulKeyTable['g']	=  18;	// ㅎ
	m_HangulKeyTable['G']	=  18;	// ㅎ
	m_HangulKeyTable['h']	=  27;	// ㅗ
	m_HangulKeyTable['H']	=  27;	// ㅗ
	m_HangulKeyTable['j']	=  23;	// ㅓ
	m_HangulKeyTable['J']	=  23;	// ㅓ
	m_HangulKeyTable['k']	=  19;	// ㅏ
	m_HangulKeyTable['K']	=  19;	// ㅏ
	m_HangulKeyTable['l']	=  39;	// ㅣ
	m_HangulKeyTable['L']	=  39;	// ㅣ
	m_HangulKeyTable['z']	=  15;	// ㅋ
	m_HangulKeyTable['Z']	=  15;	// ㅋ
	m_HangulKeyTable['x']	=  16;	// ㅌ
	m_HangulKeyTable['X']	=  16;	// ㅌ
	m_HangulKeyTable['c']	=  14;	// ㅊ
	m_HangulKeyTable['C']	=  14;	// ㅊ
	m_HangulKeyTable['v']	=  17;	// ㅍ
	m_HangulKeyTable['V']	=  17;	// ㅍ
	m_HangulKeyTable['b']	=  36;	// ㅠ
	m_HangulKeyTable['B']	=  36;	// ㅠ
	m_HangulKeyTable['n']	=  32;	// ㅜ
	m_HangulKeyTable['N']	=  32;	// ㅜ
	m_HangulKeyTable['m']	=  37;	// ㅡ
	m_HangulKeyTable['M']	=  37;	// ㅡ
	
	m_HangulKeyTable['`']	=  68;	// `
	m_HangulKeyTable['1']	=  69;	// 1
	m_HangulKeyTable['2']	=  70;	// 2
	m_HangulKeyTable['3']	=  71;	// 3
	m_HangulKeyTable['4']	=  72;	// 4
	m_HangulKeyTable['5']	=  73;	// 5
	m_HangulKeyTable['6']	=  74;	// 6
	m_HangulKeyTable['7']	=  75;	// 7
	m_HangulKeyTable['8']	=  76;	// 8
	m_HangulKeyTable['9']	=  77;	// 9
	m_HangulKeyTable['0']	=  78;	// 0
	m_HangulKeyTable['-']	=  79;	// -
	m_HangulKeyTable['=']	=  80;	// =
	m_HangulKeyTable['[']	=  81;	// [
	m_HangulKeyTable[']']	=  82;	// ]
	m_HangulKeyTable['\\']	=  83;	// \
	m_HangulKeyTable[';']	=  84;	// ;
	m_HangulKeyTable['\'']	=  85;	// '
	m_HangulKeyTable[',']	=  86;	// ,
	m_HangulKeyTable['.']	=  87;	// .
	m_HangulKeyTable['/']	=  88;	// /
	
	m_HangulKeyTable['~']	=  89;	// ~
	m_HangulKeyTable['!']	=  90;	// !
	m_HangulKeyTable['@']	=  91;	// @
	m_HangulKeyTable['#']	=  92;	// #
	m_HangulKeyTable['$']	=  93;	// $
	m_HangulKeyTable['%']	=  94;	// %
	m_HangulKeyTable['^']	=  95;	// ^
	m_HangulKeyTable['&']	=  96;	// &
	m_HangulKeyTable['*']	=  97;	// *
	m_HangulKeyTable['(']	=  98;	// (
	m_HangulKeyTable[')']	=  99;	// )
	m_HangulKeyTable['_']	= 100;	// _
	m_HangulKeyTable['+']	= 101;	// +
	m_HangulKeyTable['{']	= 102;	// {
	m_HangulKeyTable['}']	= 103;	// }
	m_HangulKeyTable['|']	= 104;	// |
	m_HangulKeyTable[':']	= 105;	// :
	m_HangulKeyTable['"']	= 106;	// "
	m_HangulKeyTable['<']	= 107;	// <
	m_HangulKeyTable['>']	= 108;	// >
	m_HangulKeyTable['?']	= 109;	// ?
	
	keyboardLanguage = KB_ENGLISH;
	
	lastKeyComboCheckTimer = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	if(m_strText.length() != 0){
		ofSetHexColor(0xFFFFFF);
		textFont->drawStringAsShapes(m_strText, 50, 120);
	}
	
	ofSetHexColor(0xFFFF00);
	ofDrawBitmapStringHighlight(ss, 50, 50, ofColor(ofColor::yellow), ofColor(ofColor::black));
	//	consoleFont->drawStringAsShapes(ss, 50, 50);
}

void ofApp::exit(){
	delete textFont;
	delete consoleFont;
}

void ofApp::toggleInputMethod(){
	keyboardLanguage = (keyboardLanguage+1) %2 ;
	cout << "KEYBOARD INPUT MODE : " ;
	if(keyboardLanguage == 0)	cout << "ENGLISH"	<< endl;
	else						cout << "HANGUL"	<< endl;
}

int ofApp::getInputMethod(){
	return keyboardLanguage;
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	int code = 0;
	
	if(getInputMethod() == 0 ){	// english
		switch(key){
			case OF_KEY_LEFT_SHIFT:
			case OF_KEY_RIGHT_SHIFT:
			case OF_KEY_SHIFT:
			case OF_KEY_ALT:
			case OF_KEY_LEFT_ALT:
			case OF_KEY_RIGHT_ALT:
			case OF_KEY_COMMAND:
			case OF_KEY_LEFT_COMMAND:
			case OF_KEY_RIGHT_COMMAND:
			case OF_KEY_CONTROL:
			case OF_KEY_LEFT_CONTROL:
			case OF_KEY_RIGHT_CONTROL:
				break;
			case OF_KEY_RETURN:
				automata.SetKeyCode(KEY_CODE_ENTER);
				break;
			case ' ':
				automata.SetKeyCode(KEY_CODE_SPACE);
				break;
			case OF_KEY_BACKSPACE:
				automata.SetKeyCode(KEY_CODE_BACKSPACE);	// KEY_CODE_BACKSPACE
				break;
				
				// disable arrow keys
			case OF_KEY_LEFT:
			case OF_KEY_RIGHT:
			case OF_KEY_UP:
			case OF_KEY_DOWN:
				break;
			case OF_KEY_TAB:
				if(ofGetElapsedTimeMillis() - lastKeyComboCheckTimer > 50){
					toggleInputMethod();
					lastKeyComboCheckTimer = ofGetElapsedTimeMillis();
				}
				break;
			default:
				automata.pushASCII(key);
				break;
		}
		
	} else {
		
		switch(key){
			case OF_KEY_LEFT_SHIFT:
			case OF_KEY_RIGHT_SHIFT:
			case OF_KEY_SHIFT:
			case OF_KEY_ALT:
			case OF_KEY_LEFT_ALT:
			case OF_KEY_RIGHT_ALT:
			case OF_KEY_COMMAND:
			case OF_KEY_LEFT_COMMAND:
			case OF_KEY_RIGHT_COMMAND:
			case OF_KEY_CONTROL:
			case OF_KEY_LEFT_CONTROL:
			case OF_KEY_RIGHT_CONTROL:
				break;
			case OF_KEY_RETURN:
				automata.SetKeyCode(KEY_CODE_ENTER);
				break;
			case ' ':
				automata.SetKeyCode(KEY_CODE_SPACE);
				break;
			case OF_KEY_BACKSPACE:
				automata.SetKeyCode(KEY_CODE_BACKSPACE);	// KEY_CODE_BACKSPACE
				break;
				
				// disable arrow keys
			case OF_KEY_LEFT:
			case OF_KEY_RIGHT:
			case OF_KEY_UP:
			case OF_KEY_DOWN:
				break;
			case OF_KEY_TAB:
				if(ofGetElapsedTimeMillis() - lastKeyComboCheckTimer > 50){
					toggleInputMethod();
					lastKeyComboCheckTimer = ofGetElapsedTimeMillis();
				}
				break;
			default:
				// 테이블에서 키를 찾아서 해당 코드를 리턴한다..
				auto it = m_HangulKeyTable.find(key);
				if(it != m_HangulKeyTable.end()){
					code = it->second;
					automata.SetKeyCode(code);
					ss = "key : " + to_string(static_cast<char>(key)) + " >> keyCode is : " + to_string(code);
					cout << "key : " << static_cast<char>(key)  << " >> keyCode is : " << code << endl;
					
					cout << "complete string is : \t" << m_strText << endl;
					cout << "automata.ingWord is : \t";
					wcout << automata.ingWord << endl;
					cout << "==========================================" << endl;
					
				}
				break;
		}
	}
	m_wstrText = automata.completeText + automata.ingWord;
	
	std::wstring_convert<std::codecvt_utf8<wchar_t>,wchar_t> convert;
	m_strText.assign(convert.to_bytes(m_wstrText));
	
	
	
	// work!!!
	
	//	wcout.imbue(locale("en_US.UTF-8"));
	//	wcout << kr << endl;
	//	m_wstrText = L'ㄱㅏ';
	//	m_strText += m_strText.assign(m_strText.begin(), m_strText.end());
}



//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	
}
