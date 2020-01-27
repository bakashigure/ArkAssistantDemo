#pragma once

#include "akahelper.h"
#include <QGraphicsOpacityEffect>


void akahelper::button_stylesheet_init()
{
	QWidget* ddd = this->findChild<QWidget*>("backgroundifrit");
	QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect;
	ddd->setGraphicsEffect(opacityEffect);
	opacityEffect->setOpacity(0.3);


	QWidget* dddd = this->findChild<QWidget*>("list_stars_2");
		dddd->setStyleSheet(
		"QPushButton{"
		"background-color:rgb(100,100,100,1);"//����ɫ��Ҳ��������ͼƬ��
		"border-style:solid;"                  //�߿���ʽ��inset/outset��
		"border-width:2.1px;"                     //�߿�������
		"border-radius:4px;"                   //�߿�Բ�ǰ뾶����
		"border-color:rgba(140, 140, 140,1);" //�߿���ɫ);
		"font:Microsoft YaHei;"
		"font:DemiBold,12px;"                       //���壬�����С
		"color:rgba(255,255,255,1);"                //������ɫ
		"padding:6px;"




		"}"
			"QPushButton:checked{"
			"background-color:rgba(255,255,255,1);"
			"border-color:rgba(255,255,255,0);"
			"font:blod,12px;"                       //���壬�����С
			"color:rgba(100,100,100,1);"
			"}"


		);

		setStyleSheet(
			//����״̬��ʽ
			"QPushButton{"
			"background-color:rgb(255,255,255,1);"//����ɫ��Ҳ��������ͼƬ��
			"border-style:solid;"                  //�߿���ʽ��inset/outset��
			"border-width:2.1px;"                     //�߿�������
			"border-radius:4px;"                   //�߿�Բ�ǰ뾶����
			"border-color:rgba(140, 140, 140,1);"    //�߿���ɫ
			//"border-top-color:rgb(85, 0, 255);"
			//"border-left-color:rgb(85, 0, 255);"
			"font:Microsoft YaHei;"
			"font:DemiBold,12px;"                       //���壬�����С
			"color:rgba(0,0,0,1);"                //������ɫ
			"padding:6px;"                          //���
			"}"

			//��갴����ʽ
			"QPushButton:checked{"
			"background-color:rgba(100,100,100,1);"
			"border-color:rgba(255,255,255,0);"
			"font:blod,12px;"                       //���壬�����С
			"color:rgba(255,255,255,1);"
			"}"

			//�����ͣ��ʽ
			//"QPushButton:hover{"
			//"background-color:rgba(100,255,100,100);"
			//"border-color:rgba(255,255,255,200);"
			//"color:rgba(0,0,0,200);"
			//"}
		);


	ui.ALL->setStyleSheet(
		"QPushButton{"
		"background-color:rgb(255,255,255,1);"//����ɫ��Ҳ��������ͼƬ��
		"border-style:solid;"                  //�߿���ʽ��inset/outset��
		"border-width:2.1px;"                     //�߿�������
		"border-radius:4px;"                   //�߿�Բ�ǰ뾶����
		"border-color:rgba(140, 140, 140,1);"    //�߿���ɫ
		//"border-top-color:rgb(85, 0, 255);"
		//"border-left-color:rgb(85, 0, 255);"
		"font:Microsoft YaHei;"
		"font:DemiBold,12px;"                       //���壬�����С
		"color:rgba(0,0,0,1);"                //������ɫ
		"padding:6px;"                          //���
		"}"

		//��갴����ʽ
		"QPushButton:checked{"
		"background-color:rgba(100,100,100,1);"
		"border-color:rgba(255,255,255,0);"
		"font:blod,12px;"                       //���壬�����С
		"color:rgba(255,255,255,1);"
		"}"
	);
	
}