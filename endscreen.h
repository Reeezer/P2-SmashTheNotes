#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QWidget>

#include "gamedata.h"
#include "gameitems/character.h"
#include "song.h"

class QLabel;
class QPushButton;

class EndScreen : public QWidget
{
    Q_OBJECT

public:
    EndScreen(GameData *game, Character *player, QWidget *parent = nullptr);
    ~EndScreen();

    void initialize();
    void setSong(Song *);

protected:
    void keyPressEvent(QKeyEvent *);

signals:
    void restartGame();
    void displayMainMenu();

private:
    GameData *_game;
    Character *_player;

    QLabel *_scoreLabel;
    QLabel *_highScoreLabel;
    QLabel *_perfectLabel;
    QLabel *_greatLabel;
    QLabel *_missLabel;
    QLabel *_passLabel;
    QLabel *_accuracyLabel;
    QLabel *_noteLabel;

    QPushButton *_restartButton;

    Song *_currentSong;
};

#endif // ENDSCREEN_H
