#pragma once

#include "akahelper.h"
#include <qstring.h>
#include <QMessageBox>
#include <qtextbrowser.h>
#include <qtextedit.h>
#include <qplaintextedit.h>
#include <qlineedit.h>
#include <qpushbutton.h>

#include  <iostream>

#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <map>



using namespace std;

constexpr auto TAGS_SELECTED_MAX = 6; //you can pick less than 6 tags
int select_count = 0;   //selected button count
vector<string> tags_selected[6] = {};
string display[10][1] = {};
QString cache[50][7];

vector<string> tags_2tags_vector[20];
int tags_2_count[20][2];

/*
/	cache[i][0]save tags
/	cache[i][1]save 6star agents
/	cache[i][2]save 5star agents
/	cache[i][3]save 4star agents
/	.........
/
*/

akahelper::akahelper(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("Arknights Helper by:cat"));

}

void akahelper::button_match()
{
	QString objectNameBtn = sender()->objectName();
	QPushButton* tempButton = this->findChild<QPushButton*>(objectNameBtn);



	if (tempButton->isChecked())
	{
		select_count++;
	}
	else
	{
		select_count--;
		tags_selected[select_count].clear();
	}


	for (int i = 0; i < select_count; i++)
	{
		if (tags_selected[i].empty())
		{
			QString textd;
			textd = tempButton->text();
			string testt;
			testt = textd.toLocal8Bit();
			display[i][0] = testt;
			tags_selected[i] = button_agents_judge(objectNameBtn);
			sort(tags_selected[i].begin(), tags_selected[i].end());
		}
	}
	QString t;
	display_info(objectNameBtn);

	ui.textEdit->clear();
	for (int k = 0; k < 10; k++)
	{
		if (!cache[k][0].isEmpty())
		{
			ui.textEdit->setTextBackgroundColor("#FF00CCFF");
			ui.textEdit->setTextColor(Qt::black);
			ui.textEdit->append(cache[k][0]);

			if (!cache[k][1].isEmpty())
			{
				ui.textEdit->setTextBackgroundColor("#FF00TTFF");
				ui.textEdit->setTextColor(Qt::green);
				ui.textEdit->append(cache[k][1]);
			}

			if (!cache[k][2].isEmpty()) {
				ui.textEdit->setTextBackgroundColor("#FF00TTFF");
				ui.textEdit->setTextColor(Qt::yellow);
				ui.textEdit->append(cache[k][2]);
			}

			if (!cache[k][3].isEmpty()) {
				ui.textEdit->setTextBackgroundColor("#FF00TTFF");
				ui.textEdit->setTextColor(Qt::gray);
				ui.textEdit->append(cache[k][3]);
			}

			if (!cache[k][4].isEmpty()) {
				ui.textEdit->setTextBackgroundColor("#FF00TTFF");
				ui.textEdit->setTextColor(Qt::white);
				ui.textEdit->append(cache[k][4]);
			}

			if (!cache[k][5].isEmpty()) {
				ui.textEdit->setTextBackgroundColor("#FF00TTFF");
				ui.textEdit->setTextColor(Qt::white);
				ui.textEdit->append(cache[k][5]);
			}

			if (!cache[k][6].isEmpty()) {
				ui.textEdit->setTextBackgroundColor("#FF00TTFF");
				ui.textEdit->setTextColor(Qt::white);
				ui.textEdit->append(cache[k][6]);
			}
			ui.textEdit->append("\n");

		}
	}
}


void akahelper::select_count1(int count)
{
	QString s;
	string str;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (cache[j][0].isEmpty())
			{
				cache[j][0] = QString::fromLocal8Bit(display[i][0].data());
				max_agents_level(tags_selected[i], j);
				break;
			}
		}
		str.clear();
	}
}

void akahelper::select_count2(int count)
{
	QString s;
	string str;
	vector<string> c;
	int count_a = 0;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < i; j++)
		{
			set_intersection(tags_selected[j].begin(), tags_selected[j].end(), tags_selected[i].begin(), tags_selected[i].end(), back_inserter(c));
			if (c.empty())
			{
				continue;
			}
			else {
				tags_2tags_vector[count_a] = c;
				tags_2_count[count_a][0] = i;
				tags_2_count[count_a][1] = j;
				count_a++;
				for (int l = 0; l < 50; l++)
				{
					if (cache[l][0].isEmpty())
					{
						max_agents_level(c, l);
						str = display[i][0] + "+" + display[j][0];
						cache[l][0] = QString::fromLocal8Bit(str.data());
						break;
					}
				}
			}
		}
	}
}



void akahelper::select_count3(int count)
{
	QString s;
	string str;
	vector<string> c;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < 50,j!=tags_2_count[j][0],j!=tags_2_count[j][1]; j++)
		{
			if (!tags_2tags_vector[j].empty())
			{
				set_intersection(tags_selected[j].begin(), tags_selected[j].end(), tags_selected[i].begin(), tags_selected[i].end(), back_inserter(c));
			}

		}

	}
}








void akahelper::max_agents_level(vector<string> c, int count)
{
	string str;
	vector<string> d;


	sort(gaojizishenganyuan.begin(), gaojizishenganyuan.end());
	sort(zishenganyuan.begin(), zishenganyuan.end());
	sort(star1.begin(), star1.end());
	sort(star2.begin(), star2.end());
	sort(star3.begin(), star3.end());
	sort(star4.begin(), star4.end());


	set_intersection(c.begin(), c.end(), gaojizishenganyuan.begin(), gaojizishenganyuan.end(), back_inserter(d));
	if (!d.empty())
	{
		for (string n : d)
			str = str + n + " ";
		cache[count][1] = QString::fromLocal8Bit(str.data());
	}
	d.clear();
	str.clear();

	set_intersection(c.begin(), c.end(), zishenganyuan.begin(), zishenganyuan.end(), back_inserter(d));
	if (!d.empty())
	{
		for (string n : d)
			str = str + n + " ";
		cache[count][2] = QString::fromLocal8Bit(str.data());

	}
	d.clear();
	str.clear();

	set_intersection(c.begin(), c.end(), star4.begin(), star4.end(), back_inserter(d));
	if (!d.empty())
	{
		for (string n : d)
			str = str + n + " ";
		cache[count][3] = QString::fromLocal8Bit(str.data());
	}
	d.clear();
	str.clear();

	set_intersection(c.begin(), c.end(), star3.begin(), star3.end(), back_inserter(d));
	if (!d.empty() != false)
	{
		for (string n : d)
			str = str + n + " ";
		cache[count][4] = QString::fromLocal8Bit(str.data());
	}
	d.clear();
	str.clear();

	set_intersection(c.begin(), c.end(), star2.begin(), star2.end(), back_inserter(d));
	if (!d.empty())
	{
		for (string n : d)
			str = str + n + " ";
		cache[count][5] = QString::fromLocal8Bit(str.data());
	}
	d.clear();
	str.clear();

	set_intersection(c.begin(), c.end(), star1.begin(), star1.end(), back_inserter(d));
	if (!d.empty())
	{
		for (string n : d)
			str = str + n + " ";
		cache[count][6] = QString::fromLocal8Bit(str.data());
	}
	d.clear();
	str.clear();

}



void akahelper::display_info(QString& stri)
{

	vector<string> c, tag12, tag123;

	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 7; j++)
			cache[i][j].clear();
	if (select_count == 1)
	{
		select_count1(1);
		//ui.textEdit->clear();
	}

	if (select_count == 2)

	{
		select_count2(2);
		select_count1(2);
	}

	if (select_count == 3)
	{

	}



}


void akahelper::init()
{
	button_stylesheet_init();

	juji = { "普罗旺斯","蓝毒","守林人","陨星","白金","流星","白雪"
				,"杰西卡","克洛丝","安德切尔","巡林者" };
	shuchu = { "普罗旺斯","蓝毒","雷蛇","因陀罗","狮蝎","守林人","火神","真理","白金"
				,"崖心" ,"杜宾" ,"流星" ,"夜烟" ,"慕斯" ,"霜叶" ,"清道夫" ,"缠丸" ,"红豆"
				,"杰西卡" ,"克洛丝" ,"史都华德" ,"玫兰莎" ,"翎羽","安德切尔","夜魔" };
	xianfeng = { "德克萨斯","凛冬","清道夫","红豆","芬","香草","翎羽","夜刀" };
	jingwei = { "幽灵鲨","因陀罗", "杜宾", "艾丝黛尔", "慕斯", "霜叶", "缠丸", "玫兰莎", "Castle-3" };
	zhongzhuang = { "临光","雷蛇","火神","可颂","蛇屠箱","古米","角峰","米格鲁","黑角" };
	yiliao = { "白面鸮","赫默", "华法琳", "末药", "调香师", "芙蓉", "安赛尔", "Lancet-2" };
	fuzhu = { "初雪","真理", "梅尔", "地灵", "梓兰" };
	tezhong = { "红","狮蝎", "崖心", "食铁兽", "暗索", "砾", "阿消" };
	nan = { "角峰","史都华德", "安赛尔", "安德切尔", "巡林者", "黑角", "12F", "Castle-3" };
	nv = { "幽灵鲨","凛冬", "白面鸮","德克萨斯", "蓝毒", "普罗旺斯", "临光", "雷蛇", "红",
			"赫默", "因陀罗", "初雪", "华法琳","守林人", "狮蝎", "火神", "真理", "白金", "陨星",
			"可颂", "梅尔", "崖心", "食铁兽", "杜宾", "流星","夜烟", "白雪", "远山", "末药", "蛇屠箱",
			"艾丝黛尔", "慕斯", "暗索", "砾", "地灵", "调香师", "霜叶","清道夫", "古米", "缠丸", "阿消",
			"红豆", "杰西卡", "芬", "克洛丝", "炎熔", "米格鲁", "芙蓉","香草", "玫兰莎", "梓兰",
			"翎羽", "杜林", "Lancet-2" };
	jinzhanwei = { "幽灵鲨","凛冬", "德克萨斯", "临光", "雷蛇", "红", "因陀罗", "狮蝎", "火神", "可颂",
				"崖心", "食铁兽", "杜宾", "蛇屠箱", "艾丝黛尔", "慕斯", "暗索", "砾", "霜叶", "清道夫", "古米",
				"角峰", "缠丸", "阿消", "红豆", "芬", "米格鲁", "香草", "玫兰莎", "翎羽", "夜刀", "黑角",
				"Castle-3" };
	yuanchenwei = { "白面鸮","蓝毒", "普罗旺斯", "赫默", "初雪", "华法琳", "守林人", "真理", "白金", "陨星",
				"梅尔", "流星", "夜烟", "白雪", "远山", "末药", "地灵", "调香师", "杰西卡", "克洛丝", "炎熔",
				"芙蓉", "史都华德", "安赛尔", "梓兰", "安德切尔", "巡林者", "杜林", "12F", "Lancet-2","夜魔" };
	fanghu = { "临光","雷蛇", "火神", "可颂", "蛇屠箱", "砾", "古米", "角峰", "米格鲁" };
	shencun = { "幽灵鲨", "因陀罗", "狮蝎", "火神", "艾丝黛尔", "缠丸", "杰西卡", "玫兰莎" };
	zhiliao = { "白面鸮","临光", "赫默", "华法琳", "末药", "调香师", "古米", "芙蓉", "安赛尔", "Lancet-2","夜魔" };
	feiyonghuifu = { "凛冬","德克萨斯", "清道夫", "红豆", "芬", "香草", "翎羽" };
	qungong = { "幽灵鲨", "陨星", "白雪", "远山", "艾丝黛尔", "炎熔" };
	jiansu = { "真理","食铁兽", "白雪", "地灵", "霜叶", "梓兰" ,"夜魔" };
	zhiyuan = { "凛冬","白面鸮", "华法琳", "杜宾", "Castle-3" };
	kuaisufuhuo = { "红","砾" };
	xueruo = { "初雪","陨星", "流星", "夜烟" };
	weiyi = { "可颂","崖心", "食铁兽","暗索", "阿消" };
	zhaohuan = { "梅尔" };
	kongchang = { "德克萨斯","红", "梅尔" };
	baofa = { "守林人" };
	xinshou = { "夜刀","巡林者", "杜林", "黑角", "12F", };
	zishenganyuan = { "幽灵鲨","凛冬", "白面鸮", "德克萨斯", "蓝毒", "普罗旺斯", "临光", "雷蛇", "红", "赫默",
				"因陀罗", "初雪", "华法琳", "守林人", "狮蝎", "火神", "真理", "白金", "陨星", "可颂", "梅尔", "崖心", "食铁兽" ,"夜魔" };
	gaojizishenganyuan = { "推进之王","能天使", "星熊", "闪灵", "伊芙利特", "银灰", "塞雷娅", "夜莺","斯卡蒂" };
	star1 = { "Lancet-2","Castle-3" };
	star2 = { "夜刀","黑角","巡林者","杜林","12F" };
	star3 = { "安德切尔","芬", "翎羽", "玫兰莎", "米格鲁", "克洛斯", "炎熔", "芙蓉", "安赛尔", "史都华德", "梓兰", "空爆","月见夜" };
	star4 = { "艾斯黛尔","夜烟", "远山", "杰西卡", "流星", "白雪", "清道夫", "红豆", "杜宾", "缠丸", "霜叶", "慕斯", "砾", "暗锁",
			"末药", "调香师", "角峰", "蛇屠箱", "古米", "地灵", "阿消", "猎蜂" };
	zhiyuanjixie = { "Lancet-2","Castle-3" };
	shushi = { "夜魔","夜烟", "远山", "炎熔", "史都华德", "杜林","12F" };


	m.insert(pair<string, vector<string>>("zhiyuanjixie", zhiyuanjixie));
	m.insert(pair<string, vector<string>>("shushi", shushi));
	m.insert(pair<string, vector<string>>("juji", juji));
	m.insert(pair<string, vector<string>>("star1", star1));
	m.insert(pair<string, vector<string>>("star2", star2));
	m.insert(pair<string, vector<string>>("star3", star3));
	m.insert(pair<string, vector<string>>("star4", star4));
	m.insert(pair<string, vector<string>>("shuchu", shuchu));
	m.insert(pair<string, vector<string>>("xianfeng", xianfeng));
	m.insert(pair<string, vector<string>>("jingwei", jingwei));
	m.insert(pair<string, vector<string>>("zhongzhuang", zhongzhuang));
	m.insert(pair<string, vector<string>>("yiliao", yiliao));
	m.insert(pair<string, vector<string>>("fuzhu", fuzhu));
	m.insert(pair<string, vector<string>>("tezhong", tezhong));
	m.insert(pair<string, vector<string>>("jinzhanwei", jinzhanwei));
	m.insert(pair<string, vector<string>>("yuanchenwei", yuanchenwei));
	m.insert(pair<string, vector<string>>("fanghu", fanghu));
	m.insert(pair<string, vector<string>>("shencun", shencun));
	m.insert(pair<string, vector<string>>("zhiliao", zhiliao));
	m.insert(pair<string, vector<string>>("feiyonghuifu", feiyonghuifu));
	m.insert(pair<string, vector<string>>("qungong", qungong));
	m.insert(pair<string, vector<string>>("jiansu", jiansu));
	m.insert(pair<string, vector<string>>("zhiyuan", zhiyuan));
	m.insert(pair<string, vector<string>>("kuaisufuhuo", kuaisufuhuo));
	m.insert(pair<string, vector<string>>("xueruo", xueruo));
	m.insert(pair<string, vector<string>>("weiyi", weiyi));
	m.insert(pair<string, vector<string>>("zhaohuan", zhaohuan));
	m.insert(pair<string, vector<string>>("kongchang", kongchang));
	m.insert(pair<string, vector<string>>("baofa", baofa));
	m.insert(pair<string, vector<string>>("xinshou", xinshou));
	m.insert(pair<string, vector<string>>("zishenganyuan", zishenganyuan));
	m.insert(pair<string, vector<string>>("gaojizishenganyuan", gaojizishenganyuan));


}




vector<string> akahelper::button_agents_judge(QString& stri)
{

	vector<string> t;
	it = m.find(stri.toStdString());
	t = it->second;
	sort(t.begin(), t.end());
	return t;
}

void akahelper::on_pushButton_clicked()
{
	QMessageBox msg;
	msg.setText("Aka helper by:cat");
	msg.exec();
}

void akahelper::display_about()
{
	QMessageBox msg;
	msg.setText("Aka helper by:cat\ntwitter@bakashigure");
	msg.exec();
}

void akahelper::button_notworking()
{
	QMessageBox msg;
	msg.setText(QString::fromLocal8Bit("这个按钮暂时不起作用"));
	msg.exec();
}

void akahelper::about()
{
	display_about();
}


void akahelper::textline_empty()
{


	ui.textEdit->clear();

}
