
//todo: fix map.length things to proper c++ syntax
//todo: fix array notation to vector notation: i.e. push_back etc. .length etc.
//possibly todo: implement that when cell dies, there's a certain chance it becomes a hole instead of open space
//todo: change from array to vector the WHOLE WAY THROUGH UNLESS GIVEN WIDTH AND LENGTH AT START
/* RULES
if a wall/ramp has less than 2 similar neighbours, it dies
----to implement if having problems------
if a wall/ramp has 2 or 3 similar neighbours, it stays alive
if a wall/ramp has more than 3 similar neighbours it dies.
-----------------------------------------
if an open space or hole has 3 neighbours that are all wall or all ramp, it becomes that.


*/

#include "mainwindow.h"
#include <cstdlib>
#include <ctime>

public mapVector initialiseMap(mapVector map) {
	//TODO: implement chances for levels between 1 and 2
	// float victimChance = 0.01f;
	// float holeChance = 0.05f;
	// float obstacleChance = 0.10f;
	// float rampChance = 0.24f;
	// float openspaceChance = 0.60f;
	
	

	srand(time(0));

	for (int x=0; x < 20; x++){
		for (int y=0; y < 20; y++){
			//fix random number so its not in every if statement, and so it's a 2 place FLOAT
			double num = (rand() % 100) / 100 ;
			
			
			if (num <= 0.01f) {
				map[x][y] = 4;
			}
			else if(num <= 0.06f) {
				map[x][y] =  -3;
			}
			else if (num <= 0.16f) {
				map[x][y] = -2;
			}
			else if (num <= 0.40f) {
				map[x][y] = 2;
			}
			else if (num <= 1.00f) {
				map[x][y] = 1;
			}	
		}
	}

	return map;
}







public mapVector doSimulationStep(mapVector oldMap) {
	mapVector newMap;
	
	//loop over each row and column of the map
	for(int x=0; x < oldMap.length; x++){
		for (int y=0; y<oldMap[0].length; y++){
			//check what type it is to determine course of action
			if (oldMap[x][y] == 4) {
				//if victim, do nothing
			}
			else if (oldMap[x][y] == -2 || (oldMap[x][y] > 1 && oldMap[x][y] <= 2)) {
				// if an obstacle or a ramp
				int similarNeighbours = countAlikeNeighbours(oldMap, x, y);
				if (similarNeighbours < 2) {
					newMap[x][y] = 1;
				}
				else {
					newMap[x][y] = oldMap[x][y];
				}
			}

			else if (oldMap[x][y] == -3 || oldMap[x][y] == 1) {
				// if a hole or open space
				int highestNeighbour = countHighestNeighbour(oldMap, x, y);
				if (highestNeighbour == -2) {
					newMap[x][y] = -2;
				}
				else if (highestNeighbour == 2) {
					newMap[x][y] = 2;
				}
				else if (highestNeighbour == 0) {
					newMap[x][y] = oldMap[x][y];
				}
			}
		}
	}
	return newMap;
}






//returns number of alike neighbours
//for wall and ramp to see whether they live or die
public int countAlikeNeighbours(mapVector map, int x, int y) {
	int alikeCount = 0;

	for (int i =-1; i<2; i++) {
		for (int j = -1; j<2; j++) {
			int neighbour_x = x+i;
			int neighbour_y = y+j;
			//if we're looking at the middle point
			if(i== 0 && j == 0) {
				//do nothing
			}
			//in case index is off map (can be removed to see different effect)
			else if(neighbour_x < 0 || neighbour_y < 0 || neighbour_x >= map.length || neighbour_y >= map[0].length){
				//count = count + 1;
			}
			//otherwise, a normal check of the neighbour to see if alike
			else if (map[neighbour_x][neighbour_y] == map[x][y]) {
				alikeCount++;
			}
		}
	}
	return alikeCount;
}







//returns the number which it should transform to, 0 if stay the same
//count amount of walls and ramps
//compare which neighbour is highest. then, if over a threshold, return the type. in the receiver, if return is the type, change it to that. else, keep it the same
public int countHighestNeighbour(mapVector map, int x, int y) {
	
	int wallCount = 0;
	int rampCount = 0;

	for (int i =-1; i<2; i++) {
		
		for (int j = -1; j<2; j++) {
			int neighbour_x = x+i;
			int neighbour_y = y+j;
			
			//if we're looking at the middle point
			if(i==0 && j == 0) {
				//do nothing
			}
			
			else if (neighbour_x < 0 || neighbour_y < 0 || neighbour_x >= map.length || neighbour_y >= map[0].length) {
				//off the edge of the map, do nothing
			}
			
			else {
				// if a wall, add to wall count. if a ramp, add to ramp count. we don't care about other types
				if (map[neighbour_x][neighbour_y] == -2) {
					wallCount++; //check if this is proper syntax
				}
				else if (map[neighbour_x][neighbour_y] <= 2 && map[neighbour_x][neighbour_y] > 1) {
					rampCount++;
				}
			}
		}
	}
	// TODO : combine if statements
	if (wallCount > rampCount && wallCount >= 3) {
		return -2; //check syntax for this
	}
	else if (rampCount > wallCount && rampCount > 3) {
		return 2;
	}
	else if (rampCount == wallCount && rampCount > 3) {
		return 2;
	}
	else {
		return 0;
	}
}










public mapVector generateMap(){
	//create a new map
	mapVector cellmap;
	//set up the map with random values
	cellmap = initialiseMap(cellmap);
	//and now run the simulation for a set number of steps
	for (int i=0; i < 3; i++){
		cellmap = doSimulationStep(cellmap);
	}
	//convert to mapVector, leave as array throughout process
	return cellmap;
}

