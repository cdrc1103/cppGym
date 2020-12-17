#include <iostream>

using namespace std;

enum material{wall, space, player};

struct field{
    int x,y;
    material type;
    bool isWall;
    bool isPlayer;
};

#define n 16
#define m 12

char character(material mat){
	// Switching is a sort of if_then_else
	// Useful when there many cases.
	//Remember to always break each branch!
	switch(mat)
    {
	case wall:
		return '*';
	case space:
		return ' ';
    case player:
        return 'O';
	default:
		return '?';
	}
}

int main()
{
    int x_pos = 5;
    int y_pos = 5;

    // Define the dimensions of the field
    field **playground = new field *[n];
    for (int i=0; i<n; i++){
        playground[i] = new field[m];
    }

    // Build the field
    // Loop over n columns
    for (int i=0; i<n; i++){
        // Loop over m rows
        for (int j=0; j<m; j++){
            // Save index numbers.
            playground[i][j].x=i;
            playground[i][j].y=j;

            // Define restrictions for being a wall material
            playground[i][j].isWall=(i==0||j==0||i==(n-1)||j==(m-1));

            // Connect material to respective character
            if (playground[i][j].isWall){
                playground [i][j].type=wall;
            }
            else{
                playground [i][j].type=space;
            }
        }
    }
    playground[3][0].isWall = false;
    playground[3][0].type = space;

    // Every game iteration
    while(true)
    {
        playground[x_pos][y_pos].type=player;
        
        // print the playground
        for (int j=0; j<m; j++){
            for (int i=0; i<n; i++){
                cout << character(playground[i][j].type);
            }
            cout << endl;
        }

        // take direction input for next round
        char dir;
        // cout << "Go right (r), Go left (l), Go up (u), Go down (d) or quit (q):\n";
        cin >> dir;

        if (dir=='r' && playground[x_pos + 1][y_pos].isWall == false){
            playground[x_pos][y_pos].type = space;
            x_pos++;
        }
        else if(dir=='l' && playground[x_pos - 1][y_pos].isWall == false){
            playground[x_pos][y_pos].type = space;
            x_pos--;
        }
        else if(dir=='u' && playground[x_pos][y_pos - 1].isWall == false){
            playground[x_pos][y_pos].type = space;
            y_pos--;
        }
        else if(dir=='d' && playground[x_pos][y_pos + 1].isWall == false){
            playground[x_pos][y_pos].type = space;
            y_pos++;
        }
        else if(dir=='q'){
            break;
        }
    }

    // when memory is dynamically allocated, you have to deallocate it explicitly!
    for (int i=0; i<n; i++){
        delete[] playground[i];
    }
    delete[] playground;

	return 0;
}