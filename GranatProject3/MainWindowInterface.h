#pragma once

#include <QWidget>
#include "ui_MainWindowInterface.h"
#include <QKeyEvent>
#include <qdebug.h>
#include "GameDisplayEngine.h"
#include "QSFMLCanvas.h"

class MainWindowInterface : public QWidget
{
	Q_OBJECT

public:
	MainWindowInterface(QWidget *parent = Q_NULLPTR);
	~MainWindowInterface();

	void LinkGameObject(GameDisplayEngine* Game);

	void keyPressEvent(QKeyEvent *event);
	QSFMLCanvas* Canvas;

	public slots:
	void ShowNormalSlot();

private:
	Ui::MainWindowInterface ui;
};
