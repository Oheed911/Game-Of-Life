/* Name           :        Oheed Imran
   Project        :         PF
   Roll Number     :         19I-0525
*/
//code starts from here

//librarires
#include <iostream>
#include <fstream>//fstreamf or the file writing and reading
using namespace std;

//variables
char name[20];//to store the anme iof the user 
int no_of_generations = 0; //to count total number of generations
int no_of_cells = 0;//to count how many cells are there
const int X_axis = 20;// size of the secandory array
const int Y_axis = 20;// y axis of the secondary array
int G_X = 0, G_Y = 0; //variables to take input from the user of the x and y axis for secandor/ grid array
int Grid_array[X_axis][Y_axis];//grid array
int Secandory_array[X_axis][Y_axis];//array to check wchich neighbour is alive or dead
int Living_dead_cells[X_axis][Y_axis];//array to store the value which cell be alive in next generation

//functions defination
void Menu();//this function will display menu to the user
void User_information();//this function will take the inpur users name that will be displayed on terminal with every generation... 
void File_reading();//this function reads data from the file
void Initializing_arrays();//this function will inititalize arrays
void Finding_neighbours();//this function will add the values of alive cells to secandory array
void Display_output();//this function will print the output on the console
void Total_no_of_times_display();//this funtion will dispaly the output no_of_genreaions time
void Finding_death_live_cells();//this function will find the death and live cells from secandory array according to rules of game of life
void Grid_upgrade();//this function will upgrade the grid
void File_writing();//writing the output in the file named as output file
void other_functions(); //this function contains the necesaary functions needed to run the game and this function is called inthe menu function
void Start();//this funciton is only in main., all other functions are linked to this funciton

//main of the program
int main()
{
	Start();
	return 0;

}
//end of the main and start of the functions 

												
												/* FRom here are the Functions*/
												
												
//this funciton will ask the user for the information here which is nanme and it will be prompted on the console with every generation
void User_information()
{
	cout << "ENTER YOUR NAME: ";
	cin.getline(name,20);
}
//this function is only in the start of the program and contains every other funciton
void Start()
{
	User_information();//this will take the user name.
	Menu();//this function conatains the menu and other fucntions needed to run the whiole game.
}
//this funciton is needed to contain other function as it is called in menu funciton and the code will become celes
void other_functions()
{
	Initializing_arrays();//initalizing arrays
	File_reading();   //reading data from the file
	Total_no_of_times_display();//Total_no_of_times_display();//displaying the output no_of_generations_time
}
//menu of the game
void Menu()
{
	int input;
	cout << "WELCOME TO GAME-OF-LIFE:  "<<name<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"Please Make sure you have input.txt file"<<endl;
	cout << "1. PLAY GAME. "<<endl;
	cout << "2. End  GAME. "<<endl;
	cout<<"Choose From the above: ";
	cin>>input;
	cout<<endl;
	//check for input validation
	while (input!=1 && input!=2)
	{
		cout<<"Wrong Input:"<<endl;
		cout<< "Choose Again: ";
		cin>>input;//again inputing from the user
		cout<<endl;
	}
	//if teh user presses 1 the code will run and other funciton is callsed which means those funcitons will starts to execute
	if (input ==1)
	{
		other_functions();//game will start to run.
	}
	//gaem will end if user press 2
	else if (input ==2)
	{
		cout<<"Game Ended Successfully."<<endl; //game will end.
	}
}
//function to read data from the file
void File_reading()
{
	fstream myfile;//making an object of the fstreat
	myfile.open("input.txt", ios::in);//opening the file for input
	if (myfile.is_open())//if the file is open
	{
		myfile >> no_of_generations;//onputing the numebr of the generatiosn
		myfile >> no_of_cells;//inputing the no of the cells
		//this for loop will enter the live cells into the  grid array late from grid array into the secandory array
		for (int i = 0; i < no_of_cells; i++)
		{
			myfile >> G_X;//inptuing the x-axis of teh alive cellls
			myfile >> G_Y;//inputing the y axis of the alive cells
			//status being true as these are live cells
			Grid_array[G_X][G_Y] = 1;//making that cells alive by assigning 1
		}
	}
	//if the file is not found
	else
	{
		//prompting the error message 
		cout<<"Unable to open File: "<<endl;
		cout<<"Therefore, 20x20 grid has only zeros, nothing to read from file."<<endl;
	}
	//closing the file
	myfile.close();
}
//this function will intialize the arrays
void Initializing_arrays()
{
		for (int i = 0; i < X_axis; i++)
		{
			for (int j = 0; j < Y_axis; j++)
			{
				Grid_array[i][j] = 0;//grid array to be initalized with zero
				Secandory_array[i][j] = 0;//secandory array to eb intialized with zero
				Living_dead_cells[i][j]=0;//living dead cells to be intialize with zero
			}
		}
}
//Adding live cells from grid array to secandory array, AS ASKED
void Finding_neighbours()
{
	for (int i = 0; i < X_axis; i++)
	{
		for (int j = 0; j < Y_axis; j++)
		{
			Secandory_array[i][j] = Grid_array[i][j];//2d array is used to strore the values of live cells
		}
	}
}
//this function is to display the fgrid array on the console
void  Display_output()
{
         
	for (int i = 0; i < X_axis; i++)
	{
		for (int j = 0; j < Y_axis; j++)
		{
			cout << Grid_array[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	cout << endl;
}
//this function will display the output on the grid number of generation times
void Total_no_of_times_display()
{
	for (int i = 0; i <= no_of_generations; i++)
	{
	    //this will display the generation number
	    cout<<"Generation Number: "<<i;
	    //this will diaplay the user anem with every generation
	    cout<<". \t\tUSER NAME: "<<name<<endl<<endl;
	    //this funciton will display the grid array on teh console
		Display_output();
		//this is used to store the alive cells in the secandory array
		Finding_neighbours();
		//this function will search for live or dead neighbours and then decide their future
		Finding_death_live_cells();
		//this function will upgrade the grid
		Grid_upgrade();
		//this function will write the output in the output.txt file
		File_writing();
	}

}
//this function will search for the neighbours of only alive cells and decides wether the cell will remain alive or not
void Finding_death_live_cells()
{
	//first two for loops are tof ind the alive cell in secandory array as i am using 2d array here
	for (int c=0;c<X_axis;c++)
	{
		for (int d=0;d<Y_axis;d++)
		{
			if (Secandory_array[c][d]==1)//if the cell is alive then searching in its neighbour cells
			{
				for (int i = 0; i < X_axis; i++)//for loop for the x-axis of the secandory array
				{
					for (int j = 0; j < Y_axis; j++)//for loop for the y-axis of the secandory array
					{
						int count_neigh_live_cells = 0;//this variable will count how many neighbour cells are alive
						//these two for loops will search around the evteries of secandory array to find wether therea re any 
						//alive neighbours or not and it will increment the variable if found any 
						for (int k = -1; k < 2; k++)
						{
							for (int a = -1; a < 2; a++)
							{
								if (!(k == 0 && a == 0))//as(x,y) will be the cell itself so excluding this...
								{
									if (Secandory_array[i + k][j + a])//if neighbour cell is alive then incrementing teh counter
									{
										count_neigh_live_cells++;//count for the calculating number of neighbours alive
									}
								}
							}
						}
						//now calcultating the values of living and death cells
						//if cell is alive and alive neighbours cells are less than 2 cell dies
						if (Secandory_array[i][j] == 1 && count_neigh_live_cells < 2)
						{
							Living_dead_cells[i][j] = 0;//updating value here so that it can upgrade the grid
						}
						//if cell is alive and alive neighbour cells are more than 3 cell dies 
						if (Secandory_array[i][j] == 1 && count_neigh_live_cells > 3)
						{
							Living_dead_cells[i][j] = 0;//updating here so that it can updat ethe grid
						}
						//if cell is alive and alive neighbour cell are 2 or 3 then cell will remain alive
						if (Secandory_array[i][j] == 1 && (count_neigh_live_cells == 2 || count_neigh_live_cells == 3))
						{
							Living_dead_cells[i][j] = 1;//updating so that it can upgrade in the upgrade array
						}
						//if the cell is dead and alive neighbour cells are three then cell remain alive 
						if (Secandory_array[i][j] == 0 && count_neigh_live_cells == 3)
						{
							Living_dead_cells[i][j] = 1;//updating here so that it can upgrade in the grid array
						}
						//for next calculation counter must be set to zero
						count_neigh_live_cells = 0;
					}
				}
			}
		}
	}
}
//this function will upgrade the grade
void Grid_upgrade()
{
	for (int i = 0; i < X_axis; i++)
	{
		for (int j = 0; j < Y_axis; j++)
		{
			Grid_array[i][j] = Living_dead_cells[i][j];
		}
	}
}
//this funciton will write the output in the output file
void File_writing()
{
	int count=0;//count number of cells alive in last in secandory array
	ofstream myfile2;//for file writing making an object myfile2
	myfile2.open("output.txt",ios::out);//opening the file for the output
	//these for loops to find how many alive cells are there in the secandory array
	for (int i=0;i<X_axis;i++)
	{
		for (int j=0;j<Y_axis;j++)
		{
			if (Secandory_array[i][j]==1)
					count++;
		}
	}
	//now writeing the output in file
	myfile2<<no_of_generations<<endl;
	//writing how many live cells are there in secandory array
	myfile2<<count<<endl;
	//this will write the x and y axis of the alive cells into the output file
	for (int i=0;i<X_axis;i++)
	{
		for (int j=0;j<Y_axis;j++)
		{
			if (Secandory_array[i][j]==1)
			{
				myfile2<<i<<" "<<j<<endl;
			}
		}
	}
	//closing the file after writing.
	myfile2.close();
}
