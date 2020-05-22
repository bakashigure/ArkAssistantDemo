//
// Created by bakashigure on 2020/2/8.
// Twitter @bakashigure
//



#include "LanguageSwitch.h"
#include <qmessagebox.h>
#include "ui_ArkAssistant.h"

using namespace std;

void LanguageSwitch::lan_init()
{
	
	//connect(btn_lan_cn(),SIGNAL(triggered()),this,lan)
}


void LanguageSwitch::lan_zh()
{
	QMessageBox msg;
	msg.setText("success");
	msg.exec();

}




