#include "GameDisplayEngine.h"

#include <MainWindowInterface.h>



GameDisplayEngine::~GameDisplayEngine()
{


}

void GameDisplayEngine::ConnectDisplayInterface(MainWindowInterface* Interface)
{
	    Display = Interface;
		Timer.start(1);
		connect(&Timer, SIGNAL(timeout()), this, SLOT(RunGame()));
}

GameDisplayEngine::GameDisplayEngine()
{
	QString GameDir = qgetenv("GAME_WORK_DIR");
	Font.loadFromFile(GameDir.toStdString() + "/Gc05002t.ttf");
}


void GameDisplayEngine::MouseControl(sf::Event event)
{
	//            //GET POSITION IN GLOBAL MAP COORD SYSTEM 
	//            //THAT IS DEFINED AS OFFSET CENTER OF CAMERA ON CELLS COUNT + LENGTH FROM CENTER VIEW TO CURSOR IN CELL MEASUREMENT UNIT

		//===============================================================================================
				if (event.type == sf::Event::MouseMoved)
				{
		          qDebug() << "MOUSE POS  - " << event.mouseMove.x << event.mouseMove.y;
				MousePosition.SetRealCoord(event.mouseMove.x,event.mouseMove.y);
				Map.MapCellMoved(MousePosition.IsoPos(0), MousePosition.IsoPos(1));
				Map.DefineCellMoved(MousePosition.MousePosReal(0), MousePosition.MousePosReal(1));
				}

		//===============================================================================================
			if (event.type == sf::Event::MouseButtonPressed)
			{
		          qDebug() << "MOUSE POS PRESSED  - " << event.mouseMove.x << event.mouseMove.y;
				MousePosition.SetRealCoord(event.mouseButton.x,event.mouseButton.y);
				Map.MapCellPressed(MousePosition.IsoPos(0), MousePosition.IsoPos(1));

					QPair<int, int> Cell = Map.GetRealCellPressed();
					Units.MapCellPressed(Cell.first,Cell.second);
			}
		//===============================================================================================


}

void GameDisplayEngine::RunGame()
{

		sf::Event event;
		while (Display->pollEvent(event))
		{
			if(event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseMoved)
			MouseControl(event);
		}

		if (clock.getElapsedTime().asMilliseconds() >= 50)
		{
			Units.MoveUnits();
			clock.restart();

			 Display->ClearDisplay();
			*Display << Map;//DRAW TERRAIN TILES, GRID, AND RED QUADERANGLE OF CURRENT CELL WHEN CURSOR IS MOVING ON HILL CLUSTER
			*Display << Units;
			 Display->Draw();
		}

}

