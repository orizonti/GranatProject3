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

void MainWindowInterface::operator<<(std::shared_ptr<sf::Drawable> DrawObject)
{
		Canvas->draw(*DrawObject);
}

void MainWindowInterface::operator<<( QVector<std::shared_ptr<sf::Drawable>>& DrawObjects)
{
	for (auto Obj : DrawObjects)
		Canvas->draw(*Obj);

}

void MainWindowInterface::operator<<(MapObject& DrawObject)
{
		Canvas->draw(DrawObject);
}
void MainWindowInterface::operator<<(TerrainObjectClass* DrawObject)
{

		Canvas->draw(*DrawObject);
}

void MainWindowInterface::operator<<(QList<std::shared_ptr<MapUnitObject>>& DrawObjects)
{
	for (auto Obj : DrawObjects)
	{
		Canvas->draw(*Obj);
		DisplayMapObjectData(*Obj);
	}

}
void MainWindowInterface::operator<<(QVector<TerrainObjectClass*>& DrawObjects)
{
	for (TerrainObjectClass* Obj : DrawObjects)
	{
		Canvas->draw(*Obj);
		DisplayTerrainData(Obj);
	}
}

void MainWindowInterface::ClearDisplay()
{
	Canvas->clear();
}

void MainWindowInterface::Draw()
{
	Canvas->display();
}

void MainWindowInterface::DrawObject(std::shared_ptr<sf::Drawable> DrawObject)
{
		Canvas->draw(*DrawObject);
}
void MainWindowInterface::DrawGroupObject(QVector<std::shared_ptr<sf::Drawable>>& DrawObjects)
{
	for (auto Obj : DrawObjects)
		Canvas->draw(*Obj);
}

void MainWindowInterface::DisplayMapObjectData(MapObject& DrawObject)
{
}
void MainWindowInterface::DisplayTerrainData(TerrainObjectClass* DrawObjects)
{

}


