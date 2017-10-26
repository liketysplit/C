#include "globalv.h"

//Determines if he neighnor is somewhere else on the baord and treats the board as round
int getNeighborValue(int row, int coloum, int length, int width) {

    extern TableType table;

	//Middle Bits
	if(row != -1 && coloum != -1 && row != length && coloum != width){
    	if(table[row][coloum] != LIFE_YES ) 
    		return 0;
    	else
    		return 1;
    }

    //Top Left Corner
    if(row == -1 && coloum == -1 ){
    	if(table[length-1][width-1] != LIFE_YES ) 
    		return 0;
    	else
    		return 1;
    }

    //Bottom Right Corner
    if(row == length && coloum == width){
    	if(table[0][0] != LIFE_YES )
    		return 0;
    	else
    		return 1;
    }

    //Bottom Left Corner		
    if(row == length && coloum){
    	if(table[width-1][0] != LIFE_YES )
    		return 0;
    	else
    		return 1;
    }

    //Top Right Corner
    if(row == -1 && coloum >= 0 && coloum < width){
    	if(table[0][length-1] != LIFE_YES )
    		return 0;
    	else
    		return 1;
    }
    
    //Right Hand Side
    if(coloum == length && row >= 0 & row < length){
    	if(table[row][0] != LIFE_YES )
    		return 0;
    	else
    		return 1;
    }

    //Left Hand Side
    if(coloum == -1 && row >= 0 && row < length){
    	if(table[row][width-1] != LIFE_YES )
    		return 0;
    	else
    		return 1;
    }
    
    //Top Row
    if(row == -1 && coloum >= 0 && coloum <= width && coloum >= width){
    	if(table[length-1][coloum] != LIFE_YES )
    		return 0;
    	else
    		return 1;
    }
    //Bottom Row
    if(row == length && coloum >= 0 && coloum <= width && coloum >= width) {
    	if(table[0][coloum] != LIFE_YES )
    		return 0;
    	else
    		return 1;
    }
    else
        return 0;
}
