#include "globalv.h"

//Converts the rate and board deminsons to useable data to determin the number of items to randomly spawn
int organismsCalculator(int rate, int length, int width) {
    return (.01*rate)*(length*width);
}