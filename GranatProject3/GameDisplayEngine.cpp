#include "GameDisplayEngine.h"




GameDisplayEngine::~GameDisplayEngine()
{


}

void GameDisplayEngine::ConnectWindow(QSFMLCanvas* Interface)
{
	    Window = Interface;
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
	            //GET POSITION IN GLOBAL MAP COORD SYSTEM 
	            //THAT IS DEFINED AS OFFSET CENTER OF CAMERA ON CELLS COUNT + LENGTH FROM CENTER VIEW TO CURSOR IN CELL MEASUREMENT UNIT

				double x_pos_real;
				double y_pos_real;



		//===============================================================================================
				if (event.type == sf::Event::MouseMoved)
				{
	             x_pos_real = double(event.mouseMove.x - Window->size().width() / 2) / (Window->CellSize.height()*Window->Scale) - Window->OffsetCamera.first;
				 y_pos_real = double(event.mouseMove.y - Window->size().height() / 2) / (Window->CellSize.height()*Window->Scale) - Window->OffsetCamera.second;
				MousePosition.SetRealCoord(x_pos_real,y_pos_real);
				Map.MapCellMoved(MousePosition.IsoPos(0), MousePosition.IsoPos(1));
				Map.DefineCellMoved(MousePosition.MousePosReal(0), MousePosition.MousePosReal(1));
				}

		//===============================================================================================
			if (event.type == sf::Event::MouseButtonPressed)
			{

	             x_pos_real = double(event.mouseButton.x - Window->size().width() / 2) / (Window->CellSize.height()*Window->Scale) - Window->OffsetCamera.first;
				 y_pos_real = double(event.mouseButton.y - Window->size().height() / 2) / (Window->CellSize.height()*Window->Scale) - Window->OffsetCamera.second;

				MousePosition.SetRealCoord(x_pos_real,y_pos_real);
				Map.MapCellPressed(MousePosition.IsoPos(0), MousePosition.IsoPos(1));

					QPair<int, int> Cell = Map.GetRealCellPressed();
					Units.MapCellPressed(Cell.first,Cell.second);
			}
		//===============================================================================================


}

void GameDisplayEngine::RunGame()
{

		sf::Event event;
		while (Window->pollEvent(event))
		{
			if(event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseMoved)
			MouseControl(event);

		//	if (event.type == sf::Event::KeyPressed)
		//	KeyboardControl(event);
		}

		if (clock.getElapsedTime().asMilliseconds() >= 50)
		{
			Units.MoveUnits();
			clock.restart();
			Window->DrawGame(*this);
		}

}

