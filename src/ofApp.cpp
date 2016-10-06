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
	
	m_HangulKeyTable['`']	=  68;	// ㅡ
	m_HangulKeyTable['1']	=  69;	// ㅡ
	m_HangulKeyTable['2']	=  70;	// ㅡ
	m_HangulKeyTable['3']	=  71;	// ㅡ
	m_HangulKeyTable['4']	=  72;	// ㅡ
	m_HangulKeyTable['5']	=  73;	// ㅡ
	m_HangulKeyTable['6']	=  74;	// ㅡ
	m_HangulKeyTable['7']	=  75;	// ㅡ
	m_HangulKeyTable['8']	=  76;	// ㅡ
	m_HangulKeyTable['9']	=  77;	// ㅡ
	m_HangulKeyTable['0']	=  78;	// ㅡ
	m_HangulKeyTable['-']	=  79;	// ㅡ
	m_HangulKeyTable['=']	=  80;	// ㅡ
	m_HangulKeyTable['[']	=  81;	// ㅡ
	m_HangulKeyTable[']']	=  82;	// ㅡ
	m_HangulKeyTable['\\']	=  83;	// ㅡ
	m_HangulKeyTable[';']	=  84;	// ㅡ
	m_HangulKeyTable['\'']	=  85;	// ㅡ
	m_HangulKeyTable[',']	=  86;	// ㅡ
	m_HangulKeyTable['.']	=  87;	// ㅡ
	m_HangulKeyTable['/']	=  88;	// ㅡ
		
	m_HangulKeyTable['~']	=  89;	// ㅡ
	m_HangulKeyTable['!']	=  90;	// ㅡ
	m_HangulKeyTable['@']	=  91;	// ㅡ
	m_HangulKeyTable['#']	=  92;	// ㅡ
	m_HangulKeyTable['$']	=  93;	// ㅡ
	m_HangulKeyTable['%']	=  94;	// ㅡ
	m_HangulKeyTable['^']	=  95;	// ㅡ
	m_HangulKeyTable['&']	=  96;	// ㅡ
	m_HangulKeyTable['*']	=  97;	// ㅡ
	m_HangulKeyTable['(']	=  98;	// ㅡ
	m_HangulKeyTable[')']	=  99;	// ㅡ
	m_HangulKeyTable['_']	= 100;	// ㅡ
	m_HangulKeyTable['+']	= 101;	// ㅡ
	m_HangulKeyTable['{']	= 102;	// ㅡ
	m_HangulKeyTable['}']	= 103;	// ㅡ
	m_HangulKeyTable['|']	= 104;	// ㅡ
	m_HangulKeyTable[':']	= 105;	// ㅡ
	m_HangulKeyTable['"']	= 106;	// ㅡ
	m_HangulKeyTable['<']	= 107;	// ㅡ
	m_HangulKeyTable['>']	= 108;	// ㅡ
	m_HangulKeyTable['?']	= 109;	// ㅡ
	
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
	
	switch(key){
		case OF_KEY_TAB:
			if(ofGetElapsedTimeMillis() - lastKeyComboCheckTimer > 50){
				toggleInputMethod();
				lastKeyComboCheckTimer = ofGetElapsedTimeMillis();
			}
			break;
	}
	
	if(getInputMethod() == 0  && key < 255 && key > 0){	// english
		automata.pushASCII(key);
	} else {
//	if((key < 65  && key >32) || (key >90 && key < 127)){
//		automata.SetKeyCode(-4, key);
//		// 특수문자들
////		m_strText += static_cast<char>(key);
////		m_wstrText.push_back(static_cast<char>(key));
//	}
	
	switch(key){
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
//	if(key == OF_KEY_RETURN){
//		automata.SetKeyCode(KEY_CODE_ENTER);
////		automata.Clear();
////		m_strText.clear();
//	}
//	if (key == ' '){
//		automata.SetKeyCode(KEY_CODE_SPACE);	// KEY_CODE_SPACE
////		m_strText.append(" ");
//	}
//	if (key == OF_KEY_BACKSPACE){
//		automata.SetKeyCode(KEY_CODE_BACKSPACE);	// KEY_CODE_BACKSPACE
//	} else {
//		
//		
//		// 테이블에서 키를 찾아서 해당 코드를 리턴한다..
//		auto it = m_HangulKeyTable.find(key);
//		if(it != m_HangulKeyTable.end()){
//			code = it->second;
//			automata.SetKeyCode(code);
//			ss = "key : " + to_string(static_cast<char>(key)) + " >> keyCode is : " + to_string(code);
//			cout << "key : " << static_cast<char>(key)  << " >> keyCode is : " << code << endl;
//			
//			cout << "complete string is : \t" << m_strText << endl;
//			cout << "automata.ingWord is : \t";
//			wcout << automata.ingWord << endl;
//			cout << "==========================================" << endl;
//			
//		}
//		
//		
//	}
	m_wstrText = automata.completeText + automata.ingWord;
	//		cout << &m_wstrText << endl;
	//		m_strText.assign(m_wstrText.begin(), m_wstrText.end());
	
	std::wstring_convert<std::codecvt_utf8<wchar_t>,wchar_t> convert;
	m_strText.assign(convert.to_bytes(m_wstrText));

	
	//		m_strText.assign(str(m_wstrText));
	//		wstring2string(m_strText, m_wstrText);
	
	// testing...
	// 완성 문장과
	// 조합전의 문자를 보여주자.
	

	

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
