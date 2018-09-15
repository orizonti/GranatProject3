#pragma once
#include <HeaderAndStructures.h>
#include <GameCoord.h>
#include <MapContainerClass.h>
#include <QSFMLCanvas.h>
#include <QTimer>
class MainWindowInterface;
class DisplayInterface;

class GameDisplayEngine : public QObject
{
	Q_OBJECT
public: 
	GameDisplayEngine();
	~GameDisplayEngine();

	void ConnectDisplayInterface(MainWindowInterface* Interface);
	 DisplayInterface* Display;



	sf::Clock clock; // 

    GameCoord MousePosition;  

	void MouseControl(sf::Event event);

	 QTimer Timer;

	 
	 MapContainerClass Map;
	 GameViewUnitContainer Units;

	 public slots:
	 void RunGame();
};

