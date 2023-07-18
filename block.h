#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>

enum TetrominoeType{
    I,O,T,L,J,Z,S,None
};

struct Block{

    bool m_isVisible = false;
    bool m_isCurrentTetrominoe = false;

    TetrominoeType m_tetrominoType = None;

    // TODO
    // QPoint coordinates
    // bool m_exists; // instead of visible

public:
    bool getIsVisible() const;
    void setIsVisible(bool newIsVisible);

    bool isCurrentTetrominoe() const;
    void setIsCurrentTetrominoe(bool newIsCurrentTetrominoe);

    void setBlock(bool isVisible, bool isCurrentTetrominoe, TetrominoeType type);
    TetrominoeType tetrominoType() const;
    void setTetrominoType(TetrominoeType newTetrominoType);
};

#endif // BLOCK_H
