//
// Created by bakashigure on 2019/10/15.
// Twitter @bakashigure
//

//#include "ArkAssistant.h"
#include <qpushbutton.h>
#include <qaction.h>

class LanguageSwitch : public QAction
{
	Q_OBJECT

public:
	LanguageSwitch(QAction* parent = Q_NULLPTR);
	void lan_zh();

public slots:
	//void lan_zh();
	void lan_init();
private:
	QAction* openAction;
	//Ui::LanguageSwitch* ui;

};
