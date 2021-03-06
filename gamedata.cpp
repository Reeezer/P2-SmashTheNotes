#include "gamedata.h"

#include <QFontDatabase>

bool loadRessources(GameData *game)
{
    /* Fonts */
    QFontDatabase::addApplicationFont(":/font/foo.ttf");
    QFontDatabase::addApplicationFont(":/font/karen.otf");

    game->_fonts[FontType::NORMAL_18] = QFont("Foo", 18, QFont::Normal);
    game->_fonts[FontType::NORMAL_70] = QFont("Foo", 70, QFont::Normal);
    game->_fonts[FontType::NORMAL_40] = QFont("Foo", 40, QFont::Normal);
    game->_fonts[FontType::NORMAL_50] = QFont("Foo", 50, QFont::Normal);
    game->_fonts[FontType::ACCURACY] = QFont("karen", 22, QFont::Normal);

    return true;
}
