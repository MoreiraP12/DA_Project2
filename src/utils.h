#include <iostream>
#include <string>
#include <cmath>

#ifndef DA_FIRST_PROJECT_UTILS_H
#define DA_FIRST_PROJECT_UTILS_H
/**
 * clear the screen
 */
void clearScreen();

template <typename T>
/**
 * sorting mechanism used in scenario 1
 * Bi-dimensional sort where
 * @tparam T class
 * @param item1 item1
 * @param item2 item2
 * @return bool
 */
bool sortScenario1(T item1,T item2){
    if(item1.getWeight() == item2.getWeight())
        return item1.getVol() > item2.getVol();
    if(item1.getVol() == item2.getVol())
        return item1.getWeight() > item2.getWeight();
    return (item1.getWeight() + item1.getVol()) > (item2.getWeight() + item2.getVol());
}

/**
 * sorting mechanism used in scenario 2 for packages
 * @tparam T class
 * @param item1 package1
 * @param item2 package2
 * @return bool
 */

template<typename T>
bool sortScenario2Package(T item1,T item2){
    return pow(item1.getReward(),3) / sqrt(pow(item1.getWeight(),2) + pow(item1.getVol(),2)) >  pow(item2.getReward(),3) / sqrt(pow(item2.getWeight(),2) + pow(item2.getVol(),2));
}

/**
 * sorting mechanism used in scenario 2 for couriers
 * @tparam T class
 * @param item1 courier1
 * @param item2 courier2
 * @return bool
 */

template<typename T>
bool sortScenario2Courier(T item1,T item2){
    return pow(item1.getCost(),2) / (item1.getWeight() * item1.getVol()) <  pow(item2.getCost(),2) / (item2.getWeight() * item2.getVol());
}

/**
 * sorting mechanism used in scenario 3
 * @tparam T class
 * @param item1 item1
 * @param item2 item2
 * @return bool
 */

template <typename T>
bool sortScenario3(T item1, T item2){
    return item1.getTimeToDeliver() < item2.getTimeToDeliver();
}

/**
 * sort vans by plate
 * @tparam T class
 * @param item1 van1
 * @param item2 van2
 * @return bool
 */
template <typename T>
bool sortPlate(T item1, T item2){
    return item1.getVan().getPlate() < item2.getVan().getPlate();
}

/**
 * sort packages by id
 * @tparam T class
 * @param item1 package1
 * @param item2 package2
 * @return bool
 */
template <typename T>
bool sortId(T item1, T item2){
    return item1.getId() < item2.getId();
}



#endif
