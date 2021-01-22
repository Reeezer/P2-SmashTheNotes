#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <QFont>

class QPixmap;
class QString;
class QSoundEffect;

enum FontType {
    NORMAL_18,
    NORMAL_70,
    NORMAL_40,
    NORMAL_50,
    ACCURACY,
    FONT_ESIZE
};

/* structure contenant les données communes à plusieurs parties du jeu comme les paramètres ou certaines ressources */
struct GameData
{
    QFont _fonts[FONT_ESIZE];

    int _delay = 0;
    int _volume = 100;

    int _topNote1Key = Qt::Key_F;
    int _topNote2Key = Qt::Key_D;
    int _bottomNote1Key = Qt::Key_J;
    int _bottomNote2Key = Qt::Key_K;
    int _pauseButtonKey = Qt::Key_Escape;
    int _resetButtonKey = Qt::Key_R;

    int _validateKey = Qt::Key_Return;
};

bool loadRessources(GameData *);

#endif // GAMEDATA_H