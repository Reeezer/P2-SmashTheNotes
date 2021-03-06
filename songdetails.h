#ifndef SONGDETAILS_H
#define SONGDETAILS_H

#include <QWidget>

class QLabel;
class QPushButton;
class QListWidget;

#include "song.h"

class SongDetails : public QWidget
{
    Q_OBJECT

public:
    SongDetails(QWidget *parent = nullptr);

public slots:
    void setSongDetails(Song *);

signals:
    void displayMainMenu();

private:
    QLabel *_titleLabel;
    QLabel *_highscoreLabel;
    QLabel *_rankLabel;
    QPushButton *_returnButton;

    QListWidget *_highscoreList;
};

#endif // SONGDETAILS_H
