/**
 * @file HaroldFactory.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HAROLDFACTORY_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HAROLDFACTORY_H
class Actor;

/**
 * Factory class that builds the Harold character
 */
class HaroldFactory
{
private:

public:
    std::shared_ptr<Actor> Create(std::wstring imagesDir);


};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HAROLDFACTORY_H
