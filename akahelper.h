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
	void button_match();//ƥ�䰴ť
	void textline_empty();//������ֿ�
	vector<string>button_agents_judge(QString& stri);//ÿ����ť�жϸ�Ա��Ϣ
	void display_about();//����
	void button_notworking();//��ʱ�������õİ�ť
	void max_agents_level(vector<string> c,int count);
	void select_count1(int count);
	void select_count2(int count);
	void select_count3(int count);
	void about();
private:
	QAction* openAction;
	Ui::akahelperClass ui;
	
};
