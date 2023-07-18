#include "block.h"

TetrominoeType Block::tetrominoType() const
{
    return m_tetrominoType;
}

void Block::setTetrominoType(TetrominoeType newTetrominoType)
{
    m_tetrominoType = newTetrominoType;
}

bool Block::getIsVisible() const
{
    return m_isVisible;
}

void Block::setIsVisible(bool newIsVisible)
{
    m_isVisible = newIsVisible;
}

void Block::setBlock(bool isVisible, bool isCurrentTetrominoe, TetrominoeType type)
{
    m_isVisible = isVisible;
    m_isCurrentTetrominoe = isCurrentTetrominoe;
    setTetrominoType(type);
}

bool Block::isCurrentTetrominoe() const
{
    return m_isCurrentTetrominoe;
}

void Block::setIsCurrentTetrominoe(bool newIsCurrentTetrominoe)
{
    m_isCurrentTetrominoe = newIsCurrentTetrominoe;
}

