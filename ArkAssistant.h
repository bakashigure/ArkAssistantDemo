//
// Created by bakashigure on 2019/10/15.
// Twitter @bakashigure
//

#ifndef ARKASSISTANT_H
#define ARKASSISTANT_H

#include "ui_ArkAssistant.h"
#include "AboutWindow.h"


#include <iostream>

#include <set>
#include <vector>
#include <map>


using namespace std;

class ArkAssistant : public QMainWindow
{
	Q_OBJECT

public:
	ArkAssistant(QWidget* parent = Q_NULLPTR);
	vector<string> juji, shushi, xianfeng, jingwei, zhongzhuang, yiliao, fuzhu,
		tezhong, nan, nv, jinzhanwei, yuanchenwei, shuchu, fanghu, shencun, zhiliao,
		feiyonghuifu, qungong, jiansu, zhiyuan, kuaisufuhuo, xueruo, weiyi, zhaohuan,
		kongchang, baofa, xinshou, zishenganyuan, gaojizishenganyuan, star3, star4, star2,
		star1, zhiyuanjixie;

	map<string, vector<string>> operatorMap; // ��Ÿ�Աstring��vector
	map<string, vector<string>>::iterator operatorMapIter;
	map<string, int> tagMap; //��Ÿ�Աstring�����
	map<string, int>::iterator outputDataIter;

	vector<string> tagSelected[6]; //���ѡ�и�Ա��vector
	vector<string> tags2In1Vector[40]; //���������Ա��׺�ĺϳ�vector�������κϳ�ʹ��

	int tagSelected_MAX = 6; //you can pick less than 6 tags �����ֻ��ѡ����tag
	int selectCounter = 0;   //ѡ���˼�����Ա

	// vector<string> tagSelected[6] = {}; //���ѡ�и�Ա��vector


	string operatorName[100][2]; //0���ѡ�и�Ա�ı����������ƣ�1��Ű�ťojbectname;
	QString cache[200][7]; //���������
	int count_a = 0; //��ɶ���ţ����ˣ�������
	int tags2In1Counter[60][3] = {}; //һ�����صļ�����

	void stylesheetInit(); //��ť��ʽ���ʼ��

	template <class T>
	class Node
	{
	public:
		Node<T>* next;
		Node<T>* prev;
		T data;
	};

	template <class T>
	class linkList
	{
	public:
		linkList();
		~linkList();
		void add(T e);
		void remove(T index);
		bool isEmpty();
		void removeAll();
		void show();
		Node<T>* head;
		Node<T>* tail;
		int length;
	};

	linkList<vector<string>> tagg;
public slots:
	void init(); //��ʼ��
	void selectCounterSwitch(QString& stri); //ѡ���˼���tag
	vector<string>operatorJudge(QString& stri);//���ȡ�ø�Աvector
	void operatorClassify(vector<string> c, int count); //��Ա���Ǽ�����
	void selectCount1(int count); //ÿһ����Ա�Ĵ�׺�ϳɽ��
	void selectCount2(int count); //ÿ������Ա�Ĵ�׺�ϳɽ��
	void selectCount3(int count); //ÿ������Ա�Ĵ�׺�ϳɽ��
	void about(); //����
	void btnOperatorMatch();//��׺��ťƥ��
	void btnClassify(); //��ѡָ���Ǽ��ĸ�Ա
	void btnUnfinished();//��ʱ�������õİ�ť
	void outputData(); //���
	void starBtnAllChecked(); //�Ǽ�ȫѡ�İ�ť��
	void btnUncheckedAll();
private:
	QAction* openAction;
	Ui::ArkAssistantClass ui;
	AboutWindow* cw;

};


#endif //ARKASSISTANT_H