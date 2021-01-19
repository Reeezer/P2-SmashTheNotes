#include "gamewindow.h"
#include <QDebug>
#include <QFontDatabase>

GameWindow::GameWindow(QWidget *parent)
    : QStackedWidget(parent)
{
    setFixedSize(1000,600);
    setWindowTitle("Smash The Notes");

    _game = new Game();
    _player = new Character();

    if (!loadRessources(_game))
        qDebug() << "Failed to load ressources";

    _gameView = new GameView(_game, _player, this);
    addWidget(_gameView);
    _gameView->resize(this->width(), this->height());

    _mainMenu = new MainMenu(_game, this);
    addWidget(_mainMenu);
    _mainMenu->resize(this->width(), this->height());

    _mainSettings = new MainSettings(_game, this);
    addWidget(_mainSettings);
    _mainSettings->resize(this->width(), this->height());

    _controlSettings = new ControlSettings(_game, this);
    addWidget(_controlSettings);
    _controlSettings->resize(this->width(), this->height());

    _splashScreen = new SplashScreen(this);
    addWidget(_splashScreen);
    _splashScreen->resize(this->width(), this->height());

    _endScreen = new EndScreen(_game, _player, this);
    addWidget(_endScreen);
    _endScreen->resize(this->width(), this->height());

    _songDetails = new SongDetails(_game, this);
    addWidget(_songDetails);
    _songDetails->resize(this->width(), this->height());

    //Connect
    QObject::connect(_gameView, &GameView::gameFinished, this, &GameWindow::displayEndScreen);
    QObject::connect(_endScreen, &EndScreen::restartGame, this, &GameWindow::restartGame);
    QObject::connect(_mainSettings, &MainSettings::mainMenuCall, this, &GameWindow::displayMainMenu);
    QObject::connect(_mainSettings, &MainSettings::controlSettingsCall, this, &GameWindow::displayControlSettings);
    QObject::connect(_mainMenu, &MainMenu::gameViewCall, this, &GameWindow::displayGame);
    QObject::connect(_mainMenu, &MainMenu::songDetailsCall, this, &GameWindow::displaySongDetails);
    QObject::connect(_mainMenu, &MainMenu::mainSettingsCall, this, &GameWindow::displaySettings);
    QObject::connect(_splashScreen, &SplashScreen::mainMenuCall, this, &GameWindow::displayMainMenu);
    QObject::connect(_controlSettings, &ControlSettings::mainSettingsCall, this, &GameWindow::displaySettings);
    
    setCurrentWidget(_splashScreen);

}

GameWindow::~GameWindow()
{
    delete _game;
    delete _player;
}

void GameWindow::restartGame()
{
    _gameView->initialize();
    setCurrentWidget(_gameView);
}

void GameWindow::displayGame()
{
    Song *song = _mainMenu->getSelectedSong();

    if (song) {
        _gameView->newGame(song);
        setCurrentWidget(_gameView);
    } else {
        qDebug() << "uh oh, somehow displayGame() got called in '" __FILE__ "' without any song selected in the main menu, that shouldn't happen, not starting the game";
    }
}

void GameWindow::displayEndScreen()
{
    _endScreen->initialize();
    setCurrentWidget(_endScreen);
}

void GameWindow::displayMainMenu()
{
    setCurrentWidget(_mainMenu);
}

void GameWindow::displayControlSettings()
{
    setCurrentWidget(_controlSettings);
}

void GameWindow::displaySettings()
{
    setCurrentWidget(_mainSettings);
}

void GameWindow::displaySongDetails()
{
    setCurrentWidget(_songDetails);
}
