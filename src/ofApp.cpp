#include "ofApp.h"
#include <codecvt>

//--------------------------------------------------------------
void ofApp::setup(){
//	automateKR = new AutomateKR();
	wcout.imbue(locale("en_US.UTF-8"));

	// loadFont
	textFont = new ofxTrueTypeFontUC();
	textFont->loadFont("AppleSDGothicNeo-Regular.otf", 60, true, true);
	
	m_HangulKeyTable['q'] = 7;
	m_HangulKeyTable['Q'] = 8;
	m_HangulKeyTable['w'] = 12;
	m_HangulKeyTable['W'] = 13;
	m_HangulKeyTable['e'] = 3;
	m_HangulKeyTable['E'] = 4;
	m_HangulKeyTable['r'] = 0;
	m_HangulKeyTable['R'] = 1;
	m_HangulKeyTable['t'] = 9;
	m_HangulKeyTable['T'] = 10;
	m_HangulKeyTable['y'] = 31;
	m_HangulKeyTable['Y'] = 31;
	m_HangulKeyTable['u'] = 25;
	m_HangulKeyTable['U'] = 25;
	m_HangulKeyTable['i'] = 21;
	m_HangulKeyTable['I'] = 21;
	m_HangulKeyTable['o'] = 20;
	m_HangulKeyTable['O'] = 22;
	m_HangulKeyTable['p'] = 24;
	m_HangulKeyTable['P'] = 26;
	m_HangulKeyTable['a'] = 6;
	m_HangulKeyTable['A'] = 6;
	m_HangulKeyTable['s'] = 2;
	m_HangulKeyTable['S'] = 2;
	m_HangulKeyTable['d'] = 11;
	m_HangulKeyTable['D'] = 11;
	m_HangulKeyTable['f'] = 5;
	m_HangulKeyTable['F'] = 5;
	m_HangulKeyTable['g'] = 18;
	m_HangulKeyTable['G'] = 18;
	m_HangulKeyTable['h'] = 27;
	m_HangulKeyTable['H'] = 27;
	m_HangulKeyTable['j'] = 23;
	m_HangulKeyTable['J'] = 23;
	m_HangulKeyTable['k'] = 19;
	m_HangulKeyTable['K'] = 19;
	m_HangulKeyTable['l'] = 39;
	m_HangulKeyTable['L'] = 39;
	m_HangulKeyTable['z'] = 15;
	m_HangulKeyTable['Z'] = 15;
	m_HangulKeyTable['x'] = 16;
	m_HangulKeyTable['X'] = 16;
	m_HangulKeyTable['c'] = 14;
	m_HangulKeyTable['C'] = 14;
	m_HangulKeyTable['v'] = 17;
	m_HangulKeyTable['V'] = 17;
	m_HangulKeyTable['b'] = 36;
	m_HangulKeyTable['B'] = 36;
	m_HangulKeyTable['n'] = 32;
	m_HangulKeyTable['N'] = 32;
	m_HangulKeyTable['m'] = 37;
	m_HangulKeyTable['M'] = 37;
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	if(m_strText.length() > 0){
		textFont->drawStringAsShapes(m_strText, 60, ofGetHeight()/2);
	}
}

void ofApp::exit(){
	delete textFont;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//	if((key < 65  && key >32) || (key >90 && key < 127)){
//		automataKR.SetKeyCode(-4, key);
//		// 특수문자들
////		m_strText += static_cast<char>(key);
////		m_wstrText.push_back(static_cast<char>(key));
//	}
	if(key == OF_KEY_RETURN){
		automataKR.Clear();
		m_strText.clear();
	}
	if (key == ' '){
		automataKR.SetKeyCode(-1);	// KEY_CODE_SPACE
//		m_strText.append(" ");
	}
	if (key == OF_KEY_BACKSPACE){
		automataKR.SetKeyCode(-3);	// KEY_CODE_BACKSPACE
	} else {
		int code = 0;
		
		// 테이블에서 키를 찾아서 해당 코드를 리턴한다..
		auto it = m_HangulKeyTable.find(key);
		if(it != m_HangulKeyTable.end()){
			code = it->second;
			automataKR.SetKeyCode(code);
			cout << "key : " << static_cast<char>(key)  << " >> keyCode is : " << code;
			wcout << "\t::";
		}
		
		
	}
	m_wstrText = automataKR.completeText + automataKR.ingWord;
	//		cout << &m_wstrText << endl;
	//		m_strText.assign(m_wstrText.begin(), m_wstrText.end());
	
	std::wstring_convert<std::codecvt_utf8<wchar_t>,wchar_t> convert;
	m_strText.assign(convert.to_bytes(m_wstrText));

	

	
	
	
	//		m_strText.assign(str(m_wstrText));
	//		wstring2string(m_strText, m_wstrText);
	cout << m_strText << endl;
	

	// work!!!
	
//	wcout.imbue(locale("en_US.UTF-8"));
//	wcout << kr << endl;
//	m_wstrText = L'ㄱㅏ';
//	m_strText += m_strText.assign(m_strText.begin(), m_strText.end());
}


void ofApp::string2wstring(wstring &dest, const string &src){
	dest.resize(src.size());
	for(unsigned int i=0; i<src.size(); i++){
		dest[i] = static_cast<unsigned char>(src[i]);
	}
}
void ofApp::wstring2string(string &dest, const wstring &src){
	dest.resize(src.size());
	for(unsigned int i=0; i<src.size(); i++){
		dest[i] = src[i] < 256 ? src[i] : ' ';
	}
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
