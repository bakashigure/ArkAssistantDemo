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

	juji = { "������˹","����","������","����","�׽�","����","��ѩ"
				,"������","����˿","�����ж�","Ѳ����" };
	shuchu = { "������˹","����","����","������","ʨЫ","������","����","����","�׽�"
				,"����" ,"�ű�" ,"����" ,"ҹ��" ,"Ľ˹" ,"˪Ҷ" ,"�����" ,"����" ,"�춹"
				,"������" ,"����˿" ,"ʷ������" ,"õ��ɯ" ,"����","�����ж�","ҹħ" };
	xianfeng = { "�¿���˹","�ݶ�","�����","�춹","��","���","����","ҹ��" };
	jingwei = { "������","������", "�ű�", "��˿���", "Ľ˹", "˪Ҷ", "����", "õ��ɯ", "Castle-3" };
	zhongzhuang = { "�ٹ�","����","����","����","������","����","�Ƿ�","�׸�³","�ڽ�" };
	yiliao = { "�����^","��Ĭ", "������", "ĩҩ", "����ʦ", "ܽ��", "������", "Lancet-2" };
	fuzhu = { "��ѩ","����", "÷��", "����", "����" };
	tezhong = { "��","ʨЫ", "����", "ʳ����", "����", "��", "����" };
	nan = { "�Ƿ�","ʷ������", "������", "�����ж�", "Ѳ����", "�ڽ�", "12F", "Castle-3" };
	nv = { "������","�ݶ�", "�����^","�¿���˹", "����", "������˹", "�ٹ�", "����", "��",
			"��Ĭ", "������", "��ѩ", "������","������", "ʨЫ", "����", "����", "�׽�", "����",
			"����", "÷��", "����", "ʳ����", "�ű�", "����","ҹ��", "��ѩ", "Զɽ", "ĩҩ", "������",
			"��˿���", "Ľ˹", "����", "��", "����", "����ʦ", "˪Ҷ","�����", "����", "����", "����",
			"�춹", "������", "��", "����˿", "����", "�׸�³", "ܽ��","���", "õ��ɯ", "����",
			"����", "����", "Lancet-2" };
	jinzhanwei = { "������","�ݶ�", "�¿���˹", "�ٹ�", "����", "��", "������", "ʨЫ", "����", "����",
				"����", "ʳ����", "�ű�", "������", "��˿���", "Ľ˹", "����", "��", "˪Ҷ", "�����", "����",
				"�Ƿ�", "����", "����", "�춹", "��", "�׸�³", "���", "õ��ɯ", "����", "ҹ��", "�ڽ�",
				"Castle-3" };
	yuanchenwei = { "�����^","����", "������˹", "��Ĭ", "��ѩ", "������", "������", "����", "�׽�", "����",
				"÷��", "����", "ҹ��", "��ѩ", "Զɽ", "ĩҩ", "����", "����ʦ", "������", "����˿", "����",
				"ܽ��", "ʷ������", "������", "����", "�����ж�", "Ѳ����", "����", "12F", "Lancet-2","ҹħ" };
	fanghu = { "�ٹ�","����", "����", "����", "������", "��", "����", "�Ƿ�", "�׸�³" };
	shencun = { "������", "������", "ʨЫ", "����", "��˿���", "����", "������", "õ��ɯ" };
	zhiliao = { "�����^","�ٹ�", "��Ĭ", "������", "ĩҩ", "����ʦ", "����", "ܽ��", "������", "Lancet-2","ҹħ" };
	feiyonghuifu = { "�ݶ�","�¿���˹", "�����", "�춹", "��", "���", "����" };
	qungong = { "������", "����", "��ѩ", "Զɽ", "��˿���", "����" };
	jiansu = { "����","ʳ����", "��ѩ", "����", "˪Ҷ", "����" ,"ҹħ" };
	zhiyuan = { "�ݶ�","�����^", "������", "�ű�", "Castle-3" };
	kuaisufuhuo = { "��","��" };
	xueruo = { "��ѩ","����", "����", "ҹ��" };
	weiyi = { "����","����", "ʳ����","����", "����" };
	zhaohuan = { "÷��" };
	kongchang = { "�¿���˹","��", "÷��" };
	baofa = { "������" };
	xinshou = { "ҹ��","Ѳ����", "����", "�ڽ�", "12F", };
	zishenganyuan = { "������","�ݶ�", "�����^", "�¿���˹", "����", "������˹", "�ٹ�", "����", "��", "��Ĭ",
				"������", "��ѩ", "������", "������", "ʨЫ", "����", "����", "�׽�", "����", "����", "÷��", "����", "ʳ����" ,"ҹħ" };
	gaojizishenganyuan = { "�ƽ�֮��","����ʹ", "����", "����", "��ܽ����", "����", "�����", "ҹݺ","˹����" };
	star1 = { "Lancet-2","Castle-3" };
	star2 = { "ҹ��","�ڽ�","Ѳ����","����","12F" };
	star3 = { "�����ж�","��", "����", "õ��ɯ", "�׸�³", "����˹", "����", "ܽ��", "������", "ʷ������", "����", "�ձ�","�¼�ҹ" };
	star4 = { "��˹���","ҹ��", "Զɽ", "������", "����", "��ѩ", "�����", "�춹", "�ű�", "����", "˪Ҷ", "Ľ˹", "��", "����",
			"ĩҩ", "����ʦ", "�Ƿ�", "������", "����", "����", "����", "�Է�" };
	zhiyuanjixie = { "Lancet-2","Castle-3" };
	shushi = { "ҹħ","ҹ��", "Զɽ", "����", "ʷ������", "����","12F" };


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
	msg.setText(QString::fromLocal8Bit("�����ť��ʱ��������"));
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
