/**
 * @file SpartyFactory.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_SPARTYFACTORY_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_SPARTYFACTORY_H
class Actor;


/**
 * Factory class that builds the Sparty character
 */
class SpartyFactory
{
private:

public:
    /**
     * creates the sparty
     * @param imagesDir
     * @return
     */
    std::shared_ptr<Actor> Create(std::wstring imagesDir);

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_SPARTYFACTORY_H
