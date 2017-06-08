
//todo: fix map.length things to proper c++ syntax

/* RULES
if a wall/ramp has less than 2 similar neighbours, it dies
----to implement if having problems------
if a wall/ramp has 2 or 3 similar neighbours, it stays alive
if a wall/ramp has more than 3 similar neighbours it dies.
-----------------------------------------
if an open space or hole has 3 neighbours that are all wall or all ramp, it becomes that.


*/

#include "mainwindow.h"

public mapVector initialiseMap(mapVector map) {
	//TODO: implement chances for levels between 1 and 2
	// implement proper random syntax and seeding for c++
	double holeChance = 0.05f;
	double obstacleChance = 0.10f;
	double openspaceChance = 0.60f;
	double rampChance = 0.24f;
	double victimChance = 0.01f;

	srand(time(NULL));

	for (int x=0; x<width; x++){
		for (int y=0; y<height; y++){
			if(random() < holeChance) {
				map[x][y] =  -3;
			}
			else if (rand() < obstacleChance) {
				map[x][y] = -2;
			}
			else if (rand() < openspaceChance) {
				map[x][y] = 1;
			}
			else if (rand() < rampChance) {
				map[x][y] = 2;
			}
			else if (rand() < victimChance) {
				map[x][y] = 4;
			}
		}
	}

	return map;
}







public mapVector doSimulationStep(mapVector oldMap) {
	mapVector newMap = new mapVector[width][height];
	//loop over each row and column of the map
	for(int x=0; x < oldMap.length; x++){
		for (int y=0; y<oldMap[0].length; y++){
			int nbs = countAlikeNeighbours(oldMap, x, y);
			//the new value is based on our simulation rules
			//TODO: change death limit and birth limits for different types??
			//first, if a cell is not a open space and has too few neighbours, kill it
			//TODO: include up to 2 in the != statement?
			//TODO: only implement changing for obstacle, open space, and ramp

			if(oldMap[x][y] == -2){
				if(nbs < 2){
					newMap[x][y] = 1;
				}
				else{
					newMap[x][y] = oldMap[x][y];
				}
			} 
			else if (oldMap[x][y] != 1 && oldMap[x][y] != -2) {
				if(nbs < 3){
					newMap[x][y] = 1;
				}
				else {
					newMap[x][y] = oldMap[x][y];
				}
			}

			//otherwise, if the cell is open now, check if it has the right number of neighbours to be ramp or obstacle
			//check what it has most neighbours of first................
			else{
				if(nbs > 2){
					newMap[x][y] = ;
				}
				else{
					newMap[x][y] = oldMap[x][y];
				}
			}
		}
	}
	return newMap;
}







//for wall and ramp to see whether they live or die
public int countAlikeNeighbours(mapVector map, int x, int y) {
//implement separate part for between (1,2]
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
	return count;
}








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
	if (wallCount > rampCount) {
		if (wallCount >= 3) {
			return -2; //check syntax for this
		}
	}
	else if (rampCount > wallCount) {
		if (rampCount > 3) {
			return 2;
		}
	}
	else if (rampCount == wallCount)
}










public mapVector generateMap(){
	//create a new map
	boolean[][] cellmap = new boolean[width][height];
	//set up the map with random values
	cellmap = initialiseMap(cellmap);
	//and now run the simulation for a set number of steps
	for (int i=0; i<numberOfSteps; i++){
		cellmap = doSimulationStep(cellmap);
	}
	return 
}

