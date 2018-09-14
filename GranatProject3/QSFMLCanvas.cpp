#include "QSFMLCanvas.h"
#include <GameDisplayEngine.h>


QSFMLCanvas::QSFMLCanvas(QWidget* Parent) :
	QWidget(Parent),
	myInitialized(false)
{
	// Setup some states to allow direct rendering into the widget
	setAttribute(Qt::WA_PaintOnScreen);
	setAttribute(Qt::WA_OpaquePaintEvent);
	setAttribute(Qt::WA_NoSystemBackground);
	setAttribute(Qt::WA_MouseTracking);

	// Set strong focus to enable keyboard events to be received
	setFocusPolicy(Qt::StrongFocus);


	WindowSize.setHeight(800);
	WindowSize.setWidth(1200);

	Camera = new sf::View;
	Camera->setCenter(0, 0);
	Camera->setSize(this->size().width(), this->size().height());

	 CellSize = QSize(512, 256);


	OffsetCamera.first = 0;
	OffsetCamera.second = 0;
}

QSFMLCanvas::~QSFMLCanvas()
{
}
void QSFMLCanvas::pushEvent(sf::Event & ev) {
	
	SfEvents.push_back(ev);
}

void QSFMLCanvas::DrawGame(GameDisplayEngine& Game)
{
	this->clear();
	Game.Map.DrawTerrain(*this);    //DRAW TERRAIN TILES, GRID, AND RED QUADERANGLE OF CURRENT CELL WHEN CURSOR IS MOVING ON HILL CLUSTER
	Game.Map.DrawCurrentCell(*this);//IF CURSOR IS MOVING ON PLAIN TERRAIN OBJECT THEN DRAWING RED RHOMBUS CELL
	Game.Units.DrawUnits(*this);

	//this->setView(*Camera);
	this->display();
}

void QSFMLCanvas::showEvent(QShowEvent*)
{
	if (!myInitialized)
	{
		// Under X11, we need to flush the commands sent to the server to ensure that
		// SFML will get an updated view of the windows
#ifdef Q_WS_X11
		XFlush(QX11Info::display());
#endif

		// Create the SFML window with the widget handle
	    sf::Window::create((sf::WindowHandle)winId());

	this->setView(*Camera);
		// Let the derived class do its specific stuff
		myInitialized = true;
	}
}



void QSFMLCanvas::paintEvent(QPaintEvent*)
{
}

//=============================================================================================
void QSFMLCanvas::mousePressEvent(QMouseEvent *e) {
	sf::Event ev;
	ev.type = sf::Event::MouseButtonPressed;

	ev.mouseButton.button = (e->buttons() == Qt::RightButton ? sf::Mouse::Right : sf::Mouse::Left);
	ev.mouseButton.x = e->localPos().x();
	ev.mouseButton.y = e->localPos().y();

	pushEvent(ev);
}
void QSFMLCanvas::mouseReleaseEvent(QMouseEvent *e) {
	sf::Event ev;
	ev.type = sf::Event::MouseButtonReleased;

	ev.mouseButton.button = (e->buttons() == Qt::RightButton ? sf::Mouse::Right : sf::Mouse::Left);
	ev.mouseButton.x = e->localPos().x();
	ev.mouseButton.y = e->localPos().y();

	pushEvent(ev);
}

void QSFMLCanvas::wheelEvent(QWheelEvent *e) {
	sf::Event ev;
	ev.type = sf::Event::MouseWheelMoved;

	ev.mouseWheel.delta = e->delta() / 8 / 15;
	ev.mouseWheel.x = sf::Mouse::getPosition(*this).x;
	ev.mouseWheel.y = sf::Mouse::getPosition(*this).y;

	pushEvent(ev);
	e->accept();
}

void QSFMLCanvas::mouseMoveEvent(QMouseEvent *e) 
{
	sf::Event ev;
	ev.type = sf::Event::MouseMoved;

	ev.mouseMove.x = e->localPos().x();
	ev.mouseMove.y = e->localPos().y();

	pushEvent(ev);
}

void QSFMLCanvas::resizeEvent(QResizeEvent* event)
{
	Camera->setSize(event->size().width(), event->size().height());
	//Camera->setCenter(0, 0);
	this->setSize(sf::Vector2u(event->size().width(), event->size().height()));

			float temp_scale = 1;

			if (Scale < 1)
				while (temp_scale != Scale)
				{
				Camera->zoom(2);
				temp_scale /= 2;
				}

			if (Scale > 1)
				while (temp_scale != Scale)
				{
				Camera->zoom(0.5);
				temp_scale *= 2;
				}

//	qDebug() << "ZOOM " << temp_scale;
//	qDebug() << "CAMERA - " << event->size().width() << event->size().height();
	this->setView(*Camera);
}

void QSFMLCanvas::keyPressEvent(QKeyEvent *event) {
	sf::Event ev;
	ev.type = sf::Event::KeyPressed;
	ev.key.code = QtKeyToSFML(event->key());

	this->KeyboardControl(ev);
	//pushEvent(ev);
	
};
void QSFMLCanvas::keyReleaseEvent(QKeyEvent *event) {
	sf::Event ev;
	ev.type = sf::Event::KeyReleased;
	ev.key.code = QtKeyToSFML(event->key());

	//pushEvent(ev);
};


bool QSFMLCanvas::pollEvent(sf::Event& event) 
{

	if (SfEvents.size() == 0)
		return false;

	event = SfEvents.back();
	SfEvents.pop_back();
//	if (event.type == sf::Event::Resized)
//	{
//		qDebug() << "                       Resized";
//	    this->setView(*Camera);
//		//sf::FloatRect rect(sf::Vector2f(0, 0), sf::Vector2f(event.size.width, event.size.height));
//		//	Camera->setSize(event.size.width, event.size.height);
//		//	Camera->setCenter(0, 0);
//		//	this->WindowSize.setWidth(event.size.width);
//		//	this->WindowSize.setHeight(event.size.height);

//		//	qDebug() << "CAMERA - " << event.size.width << event.size.height;
//		//	Window->setView(*Camera);
//		//Window->setView(sf::View(rect));
//	}
	return true;
}
//=============================================================================================


sf::Keyboard::Key QSFMLCanvas::QtKeyToSFML(int QtKey) 
{
	switch (QtKey) {
		/* NUMBERS */
	case Qt::Key_0: return sf::Keyboard::Num0;
	case Qt::Key_1: return sf::Keyboard::Num1;
	case Qt::Key_2: return sf::Keyboard::Num2;
	case Qt::Key_3: return sf::Keyboard::Num3;
	case Qt::Key_4: return sf::Keyboard::Num4;
	case Qt::Key_5: return sf::Keyboard::Num5;
	case Qt::Key_6: return sf::Keyboard::Num6;
	case Qt::Key_7: return sf::Keyboard::Num7;
	case Qt::Key_8: return sf::Keyboard::Num8;
	case Qt::Key_9: return sf::Keyboard::Num9;

		/* ALPHABET */
	case Qt::Key_A: return sf::Keyboard::A;
	case Qt::Key_B: return sf::Keyboard::B;
	case Qt::Key_C: return sf::Keyboard::C;
	case Qt::Key_D: return sf::Keyboard::D;
	case Qt::Key_E: return sf::Keyboard::E;
	case Qt::Key_F: return sf::Keyboard::F;
	case Qt::Key_G: return sf::Keyboard::G;
	case Qt::Key_H: return sf::Keyboard::H;
	case Qt::Key_I: return sf::Keyboard::I;
	case Qt::Key_J: return sf::Keyboard::J;
	case Qt::Key_K: return sf::Keyboard::K;
	case Qt::Key_L: return sf::Keyboard::L;
	case Qt::Key_M: return sf::Keyboard::M;
	case Qt::Key_N: return sf::Keyboard::N;
	case Qt::Key_O: return sf::Keyboard::O;
	case Qt::Key_P: return sf::Keyboard::P;
	case Qt::Key_Q: return sf::Keyboard::Q;
	case Qt::Key_R: return sf::Keyboard::R;
	case Qt::Key_S: return sf::Keyboard::S;
	case Qt::Key_T: return sf::Keyboard::T;
	case Qt::Key_U: return sf::Keyboard::U;
	case Qt::Key_V: return sf::Keyboard::V;
	case Qt::Key_W: return sf::Keyboard::W;
	case Qt::Key_X: return sf::Keyboard::X;
	case Qt::Key_Y: return sf::Keyboard::Y;
	case Qt::Key_Z: return sf::Keyboard::Z;

		/* F's */
	case Qt::Key_F1:    return sf::Keyboard::F1;
	case Qt::Key_F2:    return sf::Keyboard::F2;
	case Qt::Key_F3:    return sf::Keyboard::F3;
	case Qt::Key_F4:    return sf::Keyboard::F4;
	case Qt::Key_F5:    return sf::Keyboard::F5;
	case Qt::Key_F6:    return sf::Keyboard::F6;
	case Qt::Key_F7:    return sf::Keyboard::F7;
	case Qt::Key_F8:    return sf::Keyboard::F8;
	case Qt::Key_F9:    return sf::Keyboard::F9;
	case Qt::Key_F10:   return sf::Keyboard::F10;
	case Qt::Key_F11:   return sf::Keyboard::F11;
	case Qt::Key_F12:   return sf::Keyboard::F12;

		/* ARROWS */
	case Qt::Key_Up:    return sf::Keyboard::Up;
	case Qt::Key_Down:  return sf::Keyboard::Down;
	case Qt::Key_Left:  return sf::Keyboard::Left;
	case Qt::Key_Right: return sf::Keyboard::Right;

		/* MATHS */
	case Qt::Key_Plus:     return sf::Keyboard::Add;
	case Qt::Key_Minus:    return sf::Keyboard::Subtract;
	case Qt::Key_Asterisk: return sf::Keyboard::Multiply;

		/* OTHERS */
	case Qt::Key_End:          return sf::Keyboard::End;
	case Qt::Key_Tab:          return sf::Keyboard::Tab;
	case Qt::Key_Home:         return sf::Keyboard::Home;
	case Qt::Key_Alt:          return sf::Keyboard::RAlt;
	case Qt::Key_Menu:         return sf::Keyboard::Menu;
	case Qt::Key_QuoteDbl:     /*v v v v v v v v v v v v*/
	case Qt::Key_QuoteLeft:    return sf::Keyboard::Quote;
	case Qt::Key_Atilde:       /*v v v v v v v v v v v v*/
	case Qt::Key_Ntilde:       /*v v v v v v v v v v v v*/
	case Qt::Key_Otilde:       /*v v v v v v v v v v v v*/
	case Qt::Key_AsciiTilde:   return sf::Keyboard::Tilde;
	case Qt::Key_Space:        return sf::Keyboard::Space;
	case Qt::Key_Slash:        return sf::Keyboard::Slash;
	case Qt::Key_Comma:        return sf::Keyboard::Comma;
	case Qt::Key_Equal:        return sf::Keyboard::Equal;
	case Qt::Key_Pause:        return sf::Keyboard::Pause;
	case Qt::Key_Return:       return sf::Keyboard::Return;
	case Qt::Key_Escape:       return sf::Keyboard::Escape;
	case Qt::Key_Shift:        return sf::Keyboard::RShift;
	case Qt::Key_Period:       return sf::Keyboard::Period;
	case Qt::Key_PageUp:       return sf::Keyboard::PageUp;
	case Qt::Key_Insert:       return sf::Keyboard::Insert;
	case Qt::Key_Delete:       return sf::Keyboard::Delete;
	case Qt::Key_Super_L:      return sf::Keyboard::LSystem;
	case Qt::Key_Super_R:      return sf::Keyboard::RSystem;
	case Qt::Key_Control:      return sf::Keyboard::RControl;
	case Qt::Key_BracketLeft:  return sf::Keyboard::LBracket;
	case Qt::Key_BracketRight: return sf::Keyboard::RBracket;
	case Qt::Key_PageDown:     return sf::Keyboard::PageDown;
	case Qt::Key_Backslash:    return sf::Keyboard::BackSlash;
	case Qt::Key_Backspace:    return sf::Keyboard::BackSpace;
	case Qt::Key_Semicolon:    return sf::Keyboard::SemiColon;

	default:
		return sf::Keyboard::Unknown;
	}
}

void QSFMLCanvas::KeyboardControl(sf::Event Keyboard)
{
			if (Keyboard.key.code == sf::Keyboard::Left)
			{
				Camera->move(-CellSize.height(), 0);
				OffsetCamera.first += 1;
			}

			if (Keyboard.key.code == sf::Keyboard::Right)
			{
				Camera->move(CellSize.height() , 0);
				OffsetCamera.first -= 1;
			}
			if (Keyboard.key.code == sf::Keyboard::Up)
			{
				Camera->move(0, -CellSize.height());
				OffsetCamera.second += 1;
			}
			if (Keyboard.key.code == sf::Keyboard::Down)
			{
				Camera->move(0, CellSize.height());
				OffsetCamera.second -= 1;
			}

			if (Keyboard.key.code == sf::Keyboard::S)
			{
				Camera->zoom(2);
				Scale = Scale / 2;
				qDebug() << Scale;

			}
			if (Keyboard.key.code == sf::Keyboard::D)
			{
				Camera->zoom(0.5);
				Scale = Scale * 2;
				qDebug() << Scale;
			}

	    this->setView(*Camera);
}
