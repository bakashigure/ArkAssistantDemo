#pragma once

#include "akahelper.h"

using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	akahelper w;
	w.init();
	w.show();
	return a.exec();
}
