#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct node {
	pair <int, int> own;
	pair <int, int> parent;
	int gVal;
	int hVal;

}start, current, suc1, suc2, suc3, suc4,temp, goal;



int main()
{
	// add your code here
	int rows;
	int columns;
	int sRow;
	int sCol;
	int gRow;
	int gCol;
	int obsticals;
	int newObRow;
	int newObCol;
	int x = 0;
	int stop = 0;

	vector<node> openList;
	vector<node> closedList;
	//initialize path to non zero for goal checking later


	cerr << "Number of rows and columns";
	cin >> rows;
	cin >> columns;

	cerr << "Starting postion";
	cin >> sRow;
	cin >> sCol;

	cerr << "goal location";
	cin >> gRow;
	cin >> gCol;

	cerr << "number of obsticales";
	cin >> obsticals;
	// Create Grid
	int** grid = new int*[rows];
	for (int i = 0; i < rows; i++)
		grid[i] = new int[columns];
	//Fill Grid
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			grid[i][j] = 0;
	//PLace Staring Location
	grid[sRow][sCol] = 1;
	//Places Goal
	grid[gRow][gCol] = 2;

	//Places Obsticals

	while (x < obsticals) {
		cin >> newObRow;
		cin >> newObCol;
		grid[newObRow][newObCol] = 3;
		x++;
	
	}
	
	//set initial location to start
	start.own.first = sRow ;
	start.own.second = sCol ;
	start.parent.first = sRow ;
	start.parent.second = sCol ;

	start.hVal = abs(gRow - sRow) + abs(gCol - sCol);
	
	start.gVal = 0;
	
	//set goal location 
	goal.own.first = gRow-1;
	goal.own.second = gCol-1;
	
	
	

	//bools for which succesor reached the goal 
	bool g1 = false;
	bool g2 = false;
	bool g3 = false;
	bool g4 = false;

	openList.push_back(start);
	
	bool goalT = false;
	int first = true;
	int pCounter = 0;
	//gather 4 possible successors 
	while (goalT != true ) {
		//bools to check if successors are in open or closed list
		bool s1E = false;
		bool s2E = false;
		bool s3E = false;
		bool s4E = false;
		
		


		// initialize the current node to take from succesors from by setting it equal to top of openlist
		//the top of the open list is then erased from the opelist vector and placed into the closedList 
		current = openList[0];
		closedList.push_back(openList[0]);
		openList.erase(openList.begin());
	
		//special if statements for first itearation
		if (first == true) {
			if (current.own.first > 0) {
				//first successor above current node.
			

				suc1.parent.first = current.own.first;
				suc1.parent.second = current.own.second;
				//move up a row
				suc1.own.first = current.own.first - 1; 
				suc1.own.second = current.own.second;
				suc1.gVal = current.gVal++;
				suc1.hVal = abs(gRow - suc1.own.first) + abs(gCol - suc1.own.second);
				
			
				
			//check for obsicals
				
				
				if (grid[suc1.own.first][suc1.own.second] != 3) {
					openList.push_back(suc1);
					cout << suc1.own.first << " " << suc1.own.second << endl;
				}
				
			}

			if (current.own.first < rows-1) {
				//second successor below current node
				suc2.parent.first = current.own.first;
				suc2.parent.second = current.own.second;
				//move down a row
				suc2.own.first = current.own.first + 1;
				suc2.own.second = current.own.second;

				suc2.gVal = current.gVal++;
				suc2.hVal = abs(gRow - suc2.own.first) + abs(gCol - suc2.own.second);
				
				

				
				
				
				//check for obsicals
			
				if (grid[suc2.own.first][suc2.own.second] != 3) {
					cout << suc2.own.first << " " << suc2.own.second << endl;
					openList.push_back(suc2);
				}
				
			}

			if (current.own.second > 0) {
				//third successor left current node
				
				suc3.parent.first = current.own.first;
				suc3.parent.second = current.own.second;
				//move left a column
				suc3.own.second = current.own.second - 1;
				suc3.own.first = current.own.first;

				suc3.gVal = current.gVal++;
				suc3.hVal = abs(gRow - suc3.own.first) + abs(gCol - suc3.own.second);
				

				
			
				
				//check for obsicals
				

				if (grid[suc3.own.first][suc3.own.second]!=3) {
					cout << suc3.own.first << " " << suc3.own.second << endl;
					openList.push_back(suc3);
				}
			
			}

			if (current.own.second < columns-1) {
				//third successor left current node
				
				suc4.parent.first = current.own.first;
				suc4.parent.second = current.own.second;
				//move right a column
				suc4.own.second = current.own.second + 1;
				suc4.own.first = current.own.first;
				suc4.gVal = current.gVal++;
				suc4.hVal = abs(gRow - suc4.own.first) + abs(gCol - suc4.own.second);
				
			
				

				if (grid[suc4.own.first][suc4.own.second]!=3) {
					openList.push_back(suc4);
					cout << suc4.own.first << " " << suc4.own.second << endl;
				}
				
			}
			
		}
		// after first iteration uses these if statements 
		if (first == false) {
			if (current.own.first > 0 )
			{

				//first successor above current node.
			

				suc1.parent.first = current.own.first;
				suc1.parent.second = current.own.second;
				//move up a row
				suc1.own.first = current.own.first - 1;
				suc1.own.second = current.own.second;
				suc1.gVal = current.gVal++;
				suc1.hVal = abs(gRow - suc1.own.first) + abs(gCol - suc1.own.second);
				
				
			
				
				//check if the successor already exists on the closed and open lists if it does dont add it 
				for (int i = 0; i < openList.size(); i++) {
					if (suc1.own.first == openList[i].own.first && suc1.own.second == openList[i].own.second)
						s1E = true;
				}
				for (int i = 0; i < closedList.size(); i++) {
					if (suc1.own.first == closedList[i].own.first && suc1.own.second == closedList[i].own.second)
						s1E = true;
				}
				
				if (s1E != true && grid[suc1.own.first][suc1.own.second] != 3) {
					openList.push_back(suc1);
					cout << suc1.own.first << " " << suc1.own.second << endl;
					if (suc1.own.first == gRow && suc1.own.second == gCol) {
						goalT = true;
						g1 = true;
						closedList.push_back(suc1);
						break;
					}
				}
			}

			if (current.own.first < rows-1 ) {
				//second successor below current node
				suc2.parent.first = current.own.first;
				suc2.parent.second = current.own.second;
				//move down a row
				suc2.own.first = current.own.first + 1;
				suc2.own.second = current.own.second;
				suc2.gVal = current.gVal++;
				
				suc2.hVal = abs(gRow - suc2.own.first) + abs(gCol - suc2.own.second);
				

				
				
				
				for (int i = 0; i < openList.size(); i++) {
					if (suc2.own.first == openList[i].own.first && suc2.own.second == openList[i].own.second)
						s2E = true;
				}
				for (int i = 0; i < closedList.size(); i++) {
					if (suc2.own.first == closedList[i].own.first && suc2.own.second == closedList[i].own.second)
						s2E = true;
				}
			
				if (s2E != true && grid[suc2.own.first][suc2.own.second] != 3) {
					openList.push_back(suc2);
					cout << suc2.own.first << " " << suc2.own.second << endl;
					if (suc2.own.first == gRow && suc2.own.second == gCol) {
						goalT = true;
						g2 = true;
						closedList.push_back(suc2);
						break;
					}
				}
				
			}

			if (current.own.second > 0 ) {
				//third successor left current node
			
				suc3.parent.first = current.own.first;
				suc3.parent.second = current.own.second;
				//move left a column
				suc3.own.second = current.own.second - 1;
				suc3.own.first = current.own.first;
				suc3.gVal = current.gVal++;
				suc3.hVal = abs(gRow - suc3.own.first) + abs(gCol - suc3.own.second);
				

				
				
				
				//check if the successor already exists on the closed and open lists if it does dont add it 
				for (int i = 0; i < openList.size(); i++) {
					if (suc3.own.first == openList[i].own.first && suc3.own.second == openList[i].own.second)
						s3E = true;
				}
				for (int i = 0; i < closedList.size(); i++) {
					if (suc3.own.first == closedList[i].own.first && suc3.own.second == closedList[i].own.second)
						s3E = true;
				}
				
				if (s3E != true && grid[suc3.own.first][suc3.own.second] != 3) {
					openList.push_back(suc3);
					cout << suc3.own.first << " " << suc3.own.second << endl;
					if (suc3.own.first == gRow && suc3.own.second == gCol) {
						goalT = true;
						g3 = true;
						closedList.push_back(suc3);
						break;
					}
				}
				
			}

			if (current.own.second < columns-1) {
				//third successor left current node
				
				suc4.parent.first = current.own.first;
				suc4.parent.second = current.own.second;
				//move right a column
				suc4.own.second = current.own.second + 1;
				suc4.own.first = current.own.first;
				suc4.gVal = current.gVal++;
				suc4.hVal = abs(gRow - suc4.own.first) + abs(gCol - suc4.own.second);
				
			
			
				
				//check if the successor already exists on the closed and open lists if it does not add it 
				for (int i = 0; i < openList.size(); i++) {
					if (suc4.own.first == openList[i].own.first && suc4.own.second == openList[i].own.second)
						s4E = true;
				}
				for (int i = 0; i < closedList.size(); i++) {
					if (suc4.own.first == closedList[i].own.first && suc4.own.second == closedList[i].own.second)
						s4E = true;
				}
				
				if (s4E != true && grid[suc4.own.first][suc4.own.second] != 3) {
					openList.push_back(suc4);
					cout << suc4.own.first << " " << suc4.own.second << endl;
					if (suc4.own.first == gRow && suc4.own.second == gCol) {
						goalT = true;
						g4 = true;
						closedList.push_back(suc4);
						break;
					}
				}
				
			}

		}
		first = false;
		pCounter++;
		



	
		
		//sort the open list by fvalue which is created by adding together the nodes g and h value
		sort(openList.begin(), openList.end(), [](auto const &a, auto const &b) 
		{ 
			return a.hVal+a.gVal < b.hVal+a.gVal;
		});
		


		
		
	}
	
	cout << "-1 -1" << endl;
	//outputs path from goal to start 
	bool end = false;
				//g1-4 boolean test to determine which of the previous successors found the goal 
		if (g1 == true) {
			/*
			this loop below is recreated for each of the 4 possbile succesors from previous search
			the loop continues to execute until the successor that was the initial node for the search is found
			the loop outputs a node then sets the node equal to its parent from the closed list repeating this until finished
			*/
			while (end == false) {
				temp.own.first = suc1.parent.first;
				temp.own.second = suc1.parent.second;
				
				int x = 0;
				while( x < closedList.size()) {
					if (temp.own.first == closedList[x].own.first && temp.own.second == closedList[x].own.second) {

							cout << suc1.own.first << " " << suc1.own.second << endl;
							if (suc1.own.first == sRow && suc1.own.second == sCol) {
								end = true;
								break;
							}
						suc1 = closedList[x];
						x = closedList.size();
						
					}
					x++;
				}
			}
		}
		else if (g2 == true) {
			
			while (end == false) {
				temp.own.first = suc2.parent.first;
				temp.own.second = suc2.parent.second;
				int x = 0;
				while (x < closedList.size()) {
					if (temp.own.first == closedList[x].own.first && temp.own.second == closedList[x].own.second) {
						
							cout << suc2.own.first << " " << suc2.own.second << endl;
							if (suc2.own.first == sRow && suc2.own.second == sCol) {
								end = true;
								break;
							}
						
						suc2 = closedList[x];
						x = closedList.size();
						
						
					}
					x++;
				}
			}
		}
		else if (g3 == true) {
			
			while (end == false) {
				temp.own.first = suc3.parent.first;
				temp.own.second = suc3.parent.second;
				int x = 0;
				while (x < closedList.size()) {
					if (temp.own.first == closedList[x].own.first && temp.own.second == closedList[x].own.second) {
						
							cout << suc3.own.first << " " << suc3.own.second << endl;
							if (suc3.own.first == sRow && suc3.own.second == sCol) {
								end = true;
								break;
							}
						
						suc3 = closedList[x];
						
						x = closedList.size();
					}
					x++;
				}
			}
		}
		else if (g4 == true) {
			
			while (end == false) {
				temp.own.first = suc4.parent.first;
				temp.own.second = suc4.parent.second;
				int x = 0;
				while (x < closedList.size()) {
					if (temp.own.first == closedList[x].own.first && temp.own.second == closedList[x].own.second) {
						
							cout << suc4.own.first << " " << suc4.own.second << endl;

							if (suc4.own.first == sRow && suc4.own.second == sCol) {
								end = true;
								break;
							}
					
						suc4 = closedList[x];
						x = closedList.size();
					}
					x++;
				}
			}
		}
		

	cout << "-1 -1" << endl;
	cerr << endl;
	cout.flush();
	system("pause");
	return 0;
}