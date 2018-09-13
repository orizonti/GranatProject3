#pragma once
#include <HeaderAndStructures.h>
#include <GameCoord.h>
#include <MapContainerClass.h>
#include <QSFMLCanvas.h>
#include <QTimer>
#include <MainWindowInterface.h>

class GameDisplayEngine : public QObject
{
	Q_OBJECT
public: 
	GameDisplayEngine();
	~GameDisplayEngine();

	void ConnectWindow(QSFMLCanvas* Interface);
	 QSFMLCanvas* Window;



	sf::Clock clock; // 

    GameCoord MousePosition;  

	void MouseControl(sf::Event event);

	 QTimer Timer;

	 void DrawALL();
	 
	 MapContainerClass Map;
	 GameViewUnitContainer Units;

	 public slots:
	 void RunGame();
};

