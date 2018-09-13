#include "MainWindowInterface.h"

MainWindowInterface::MainWindowInterface(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.ButShowNormal, SIGNAL(clicked()), this, SLOT(ShowNormalSlot()));

	Canvas = new QSFMLCanvas(this);
	
}

MainWindowInterface::~MainWindowInterface()
{
}

void MainWindowInterface::LinkGameObject(GameDisplayEngine* Game)
{
	//Game->ConnectWindow(ui.)
}

void MainWindowInterface::keyPressEvent(QKeyEvent* event)
{
	if(event->key() == Qt::Key_Q)
	this->showNormal();

	QWidget::keyPressEvent(event);
}

void MainWindowInterface::ShowNormalSlot()
{
	this->showNormal();
}
