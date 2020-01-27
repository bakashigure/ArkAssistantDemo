#pragma once
#include <QtWidgets/QMainWindow>

#include "ui_akahelper.h"

#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

class akahelper : public QMainWindow
{
	Q_OBJECT

public:
	akahelper(QWidget *parent = Q_NULLPTR);
	map<string, vector<string>> m;
	map<string, vector<string>>::iterator it;
	vector<string> juji, shushi, xianfeng, jingwei, zhongzhuang, yiliao, fuzhu,
		tezhong, nan, nv, jinzhanwei, yuanchenwei, shuchu, fanghu, shencun, zhiliao,
		feiyonghuifu, qungong, jiansu, zhiyuan, kuaisufuhuo, xueruo, weiyi, zhaohuan,
		kongchang, baofa, xinshou, zishenganyuan, gaojizishenganyuan, star3, star4, star2,
		star1, zhiyuanjixie;
	void button_stylesheet_init();
public slots:
	void init();
	void on_pushButton_clicked();
	void display_info(QString &stri);
	void button_match();//匹配按钮
	void textline_empty();//清空文字框
	vector<string>button_agents_judge(QString& stri);//每个按钮判断干员信息
	void display_about();//关于
	void button_notworking();//暂时不起作用的按钮
	void max_agents_level(vector<string> c,int count);
	void select_count1(int count);
	void select_count2(int count);
	void select_count3(int count);
	void about();
private:
	QAction* openAction;
	Ui::akahelperClass ui;
	
};
