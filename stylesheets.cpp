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
		"background-color:rgb(100,100,100,1);"//背景色（也可以设置图片）
		"border-style:solid;"                  //边框样式（inset/outset）
		"border-width:2.1px;"                     //边框宽度像素
		"border-radius:4px;"                   //边框圆角半径像素
		"border-color:rgba(140, 140, 140,1);" //边框颜色);
		"font:Microsoft YaHei;"
		"font:DemiBold,12px;"                       //字体，字体大小
		"color:rgba(255,255,255,1);"                //字体颜色
		"padding:6px;"




		"}"
			"QPushButton:checked{"
			"background-color:rgba(255,255,255,1);"
			"border-color:rgba(255,255,255,0);"
			"font:blod,12px;"                       //字体，字体大小
			"color:rgba(100,100,100,1);"
			"}"


		);

		setStyleSheet(
			//正常状态样式
			"QPushButton{"
			"background-color:rgb(255,255,255,1);"//背景色（也可以设置图片）
			"border-style:solid;"                  //边框样式（inset/outset）
			"border-width:2.1px;"                     //边框宽度像素
			"border-radius:4px;"                   //边框圆角半径像素
			"border-color:rgba(140, 140, 140,1);"    //边框颜色
			//"border-top-color:rgb(85, 0, 255);"
			//"border-left-color:rgb(85, 0, 255);"
			"font:Microsoft YaHei;"
			"font:DemiBold,12px;"                       //字体，字体大小
			"color:rgba(0,0,0,1);"                //字体颜色
			"padding:6px;"                          //填衬
			"}"

			//鼠标按下样式
			"QPushButton:checked{"
			"background-color:rgba(100,100,100,1);"
			"border-color:rgba(255,255,255,0);"
			"font:blod,12px;"                       //字体，字体大小
			"color:rgba(255,255,255,1);"
			"}"

			//鼠标悬停样式
			//"QPushButton:hover{"
			//"background-color:rgba(100,255,100,100);"
			//"border-color:rgba(255,255,255,200);"
			//"color:rgba(0,0,0,200);"
			//"}
		);


	ui.ALL->setStyleSheet(
		"QPushButton{"
		"background-color:rgb(255,255,255,1);"//背景色（也可以设置图片）
		"border-style:solid;"                  //边框样式（inset/outset）
		"border-width:2.1px;"                     //边框宽度像素
		"border-radius:4px;"                   //边框圆角半径像素
		"border-color:rgba(140, 140, 140,1);"    //边框颜色
		//"border-top-color:rgb(85, 0, 255);"
		//"border-left-color:rgb(85, 0, 255);"
		"font:Microsoft YaHei;"
		"font:DemiBold,12px;"                       //字体，字体大小
		"color:rgba(0,0,0,1);"                //字体颜色
		"padding:6px;"                          //填衬
		"}"

		//鼠标按下样式
		"QPushButton:checked{"
		"background-color:rgba(100,100,100,1);"
		"border-color:rgba(255,255,255,0);"
		"font:blod,12px;"                       //字体，字体大小
		"color:rgba(255,255,255,1);"
		"}"
	);
	
}