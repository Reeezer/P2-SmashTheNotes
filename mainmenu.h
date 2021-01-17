#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QMediaPlayer>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "gameview.h"
#include "song.h"
#include "game.h"

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    MainMenu(Game *game, QWidget *parent = nullptr);

public slots:
    void playSelectedSong();
    void openSelectedSongDetails();
    void openSettingsMenu();
    void adaptToSelectedSong();
    void adaptToPreselection();

private:
    Game *game;

    QLabel *songnameLabel;
    QLabel *difficultyLabel;
    QLabel *highscoreLabel;

    QPushButton *startButton;
    QPushButton *detailsButton;
    QPushButton *settingsButton;

    QListWidget *songsList;
    QMediaPlayer *musicPreview;

    static void initializeSongList(QListWidget*);

signals:
    void songDetailsCall();
    void mainSettingsCall();
    void gameViewCall();
};

