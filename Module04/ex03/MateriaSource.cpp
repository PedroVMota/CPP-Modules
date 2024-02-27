#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    _materiaCount = 0;
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    *this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
    if (this != &copy)
    {
        _materiaCount = copy._materiaCount;
        for (int i = 0; i < 4; i++)
            _materia[i] = copy._materia[i];
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i])
            delete _materia[i];
    }
}

void MateriaSource::learnMateria(AMateria *materia)
{
    if(!materia)
        return;
    if (_materiaCount < 4)
    {
        _materia[_materiaCount] = materia;
        _materiaCount++;
        return;
    }
    if(_materiaCount == 4)
        std::cout << "MateriaSource is full" << std::endl;
    delete materia;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] && _materia[i]->getType() == type)
            return _materia[i]->clone();
    }
    return NULL;
}