#include "MainWindowInterface.h"

MainWindowInterface::MainWindowInterface(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.ButShowNormal, SIGNAL(clicked()), this, SLOT(ShowNormalSlot()));

	Canvas = new QSFMLCanvas(this);
	QHBoxLayout* Lay = new QHBoxLayout;
	Lay->addWidget(Canvas);
	ui.groupBox->setLayout(Lay);

	
}

MainWindowInterface::~MainWindowInterface()
{
}

void MainWindowInterface::LinkGameObject(GameDisplayEngine* Game)
{
	Game->ConnectWindow(Canvas);
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
