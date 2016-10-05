//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <cstdlib>

//Screen dimension constants
const int SCREEN_WIDTH = 768 / 3;
const int SCREEN_HEIGHT = 768;

//Game Board Size
const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 24;

//Color Consts
const 

struct inputData
{
	bool up;
	bool down;
	bool left;
	bool right;
	bool space;
};

enum pieceType
{
	LONG,
	CUBE,
	L_RIGHT,
	L_LEFT,
	NOT_A_PIECE
};

struct piece
{
	pieceType type;
	short locationOfBlocksX[4];
	short locationOfBlocksY[4];
	short width;
};

struct gameData
{
	bool dataStructureInitialized = false;
	bool gameRunning = true;
	// accessed from top left to bottom right by row
	short gameBoard[BOARD_HEIGHT * BOARD_WIDTH] = {0};

	piece playerPiece;
	piece nextPiece;

	//pieces are generated from left top to bottom right
	int score = 0;

	inputData inputs;
};

void renderSurroundings(SDL_Surface* sdl_surface, int score)
{
	SDL_Rect borderRectInner = {5, 5, SCREEN_WIDTH - 10, SCREEN_HEIGHT - 10 - 70};
	SDL_Rect borderRectOuter = {0, 0, SCREEN_WIDTH , SCREEN_HEIGHT - 70};
	
	// do score here blah blah blah

	SDL_FillRect(sdl_surface, &borderRectOuter, SDL_MapRGB(sdl_surface->format, 0xff, 0xff, 0xff));
	SDL_FillRect(sdl_surface, &borderRectInner, SDL_MapRGB(sdl_surface->format, 0x00, 0x00, 0x00));
}

pieceType generatePieceType()
{
	return (pieceType)(rand() % 4);
}


// generate Player data is 0, generate in waiting data is 1, increment position is 2
void changePieceLocation(gameData* game_data, short mode)
{
	if (mode == 0) {
		for (int i = 0; i < 4; i++)
		{
			game_data->playerPiece.locationOfBlocksX[i] = 0;
			game_data->playerPiece.locationOfBlocksY[i] = 0;
		}
		switch (game_data->playerPiece.type)
		{
		case LONG:
			for(int i = 0; i < 4; i++)
			{
				game_data->playerPiece.locationOfBlocksX[i] = i;
				game_data->playerPiece.locationOfBlocksY[i] = 0;
			}
			game_data->playerPiece.width = 4;
			break;
		case CUBE:
			game_data->playerPiece.locationOfBlocksX[0];
			game_data->playerPiece.locationOfBlocksY[0];

			game_data->playerPiece.locationOfBlocksX[1];
			game_data->playerPiece.locationOfBlocksY[0];

			game_data->playerPiece.locationOfBlocksX[0];
			game_data->playerPiece.locationOfBlocksY[1];
	
			game_data->playerPiece.locationOfBlocksX[1];
			game_data->playerPiece.locationOfBlocksY[1];

			game_data->playerPiece.width = 2;
			break;
		case L_RIGHT:
			game_data->playerPiece.locationOfBlocksX[0];
			game_data->playerPiece.locationOfBlocksY[0];

			game_data->playerPiece.locationOfBlocksX[0];
			game_data->playerPiece.locationOfBlocksY[1];

			game_data->playerPiece.locationOfBlocksX[0];
			game_data->playerPiece.locationOfBlocksY[2];
	
			game_data->playerPiece.locationOfBlocksX[1];
			game_data->playerPiece.locationOfBlocksY[2];
			
			game_data->playerPiece.width = 2;
			break;


		case L_LEFT:
			game_data->playerPiece.locationOfBlocksX[1];
			game_data->playerPiece.locationOfBlocksY[0];

			game_data->playerPiece.locationOfBlocksX[1];
			game_data->playerPiece.locationOfBlocksY[1];

			game_data->playerPiece.locationOfBlocksX[1];
			game_data->playerPiece.locationOfBlocksY[2];
	
			game_data->playerPiece.locationOfBlocksX[0];
			game_data->playerPiece.locationOfBlocksY[2];

			game_data->playerPiece.width = 2;
			break;
	
		}
		for(int i = 0; i < 4; i++)
		{
			game_data->playerPiece.locationOfBlocksX[i] += 5;
		}
	} else if (mode == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			game_data->nextPiece.locationOfBlocksX[i] = 0;
			game_data->nextPiece.locationOfBlocksY[i] = 0;
		}
		switch (game_data->playerPiece.type)
		{
		case LONG:
			for(int i = 0; i < 4; i++)
			{
				game_data->nextPiece.locationOfBlocksX[i] = i;
				game_data->nextPiece.locationOfBlocksY[i] = 0;
			}
			game_data->nextPiece.width = 4;
			break;
		case CUBE:
			game_data->nextPiece.locationOfBlocksX[0];
			game_data->nextPiece.locationOfBlocksY[0];

			game_data->nextPiece.locationOfBlocksX[1];
			game_data->nextPiece.locationOfBlocksY[0];

			game_data->nextPiece.locationOfBlocksX[0];
			game_data->nextPiece.locationOfBlocksY[1];
	
			game_data->nextPiece.locationOfBlocksX[1];
			game_data->nextPiece.locationOfBlocksY[1];

			game_data->nextPiece.width = 2;
			break;
		case L_RIGHT:
			game_data->nextPiece.locationOfBlocksX[0];
			game_data->nextPiece.locationOfBlocksY[0];

			game_data->nextPiece.locationOfBlocksX[0];
			game_data->nextPiece.locationOfBlocksY[1];

			game_data->nextPiece.locationOfBlocksX[0];
			game_data->nextPiece.locationOfBlocksY[2];
	
			game_data->nextPiece.locationOfBlocksX[1];
			game_data->nextPiece.locationOfBlocksY[2];
			
			game_data->nextPiece.width = 2;
			break;


		case L_LEFT:
			game_data->nextPiece.locationOfBlocksX[1];
			game_data->nextPiece.locationOfBlocksY[0];

			game_data->nextPiece.locationOfBlocksX[1];
			game_data->nextPiece.locationOfBlocksY[1];

			game_data->nextPiece.locationOfBlocksX[1];
			game_data->nextPiece.locationOfBlocksY[2];
	
			game_data->nextPiece.locationOfBlocksX[0];
			game_data->nextPiece.locationOfBlocksY[2];

			game_data->nextPiece.width = 2;
			break;
	
		}
	} else if (mode == 2)
	{
		for (int i = 0; i < 4; i++) {
			game_data->playerPiece.locationOfBlocksY[i]++;
		}
		
	}
}

void updateGame(gameData* game_data)
{
	short diceRoll = -1;
	if(game_data->playerPiece.type == NOT_A_PIECE)
	{
		game_data->playerPiece.type = generatePieceType();
		changePieceLocation(game_data, 0);
		game_data->nextPiece.type = generatePieceType();
		changePieceLocation(game_data, 1);
	}

	changePieceLocation(game_data, 2);

	game_data->gameBoard[BOARD_WIDTH * 5 + 3] = 3;
	game_data->gameBoard[BOARD_WIDTH * 5] = 1;
	game_data->gameBoard[BOARD_WIDTH * 5 + 9] = 4;
}

void updateAndRender(gameData* game_data, SDL_Surface* sdl_surface)
{
	updateGame(game_data);
	renderSurroundings(sdl_surface, game_data->score);

	SDL_Rect tempRectangle = { 0, 0, 0, 0 };
	for(int i = 3; i < BOARD_HEIGHT; i++)
	{
		for(int j = 0; j < BOARD_WIDTH; j++)
		{
			if(game_data->gameBoard[BOARD_WIDTH * i + j])
			{
				tempRectangle.x = 5 + j * (SCREEN_WIDTH - 10) / BOARD_WIDTH;
				tempRectangle.y = 5 + i * (SCREEN_HEIGHT / 2 - 70) / BOARD_HEIGHT;
				tempRectangle.w = (SCREEN_WIDTH - 10) / BOARD_WIDTH;
				tempRectangle.h = (SCREEN_HEIGHT / 2 - 70) / BOARD_HEIGHT;
				switch (game_data->gameBoard[BOARD_WIDTH * i + j])
				{
				case 1:
					SDL_FillRect(sdl_surface, &tempRectangle, SDL_MapRGB(sdl_surface->format, 0xff, 0xff, 0x00));
					break;
				case 2:
					SDL_FillRect(sdl_surface, &tempRectangle, SDL_MapRGB(sdl_surface->format, 0xff, 0x00, 0xff));
					break;
				case 3:
					SDL_FillRect(sdl_surface, &tempRectangle, SDL_MapRGB(sdl_surface->format, 0x00, 0xff, 0xff));
					break;
				case 4:
					SDL_FillRect(sdl_surface, &tempRectangle, SDL_MapRGB(sdl_surface->format, 0x00, 0xff, 0x00));
					break;
				default:
					break;
				}
			}
		}
	}

	for(int i = 0; i < 4; i++)
	{
		tempRectangle.x = 5 + game_data->playerPiece.locationOfBlocksX[i] * (SCREEN_WIDTH - 10) / BOARD_WIDTH;
		tempRectangle.y = 5 + game_data->playerPiece.locationOfBlocksY[i] * (SCREEN_HEIGHT / 2 - 70) / BOARD_HEIGHT;
		tempRectangle.w = (SCREEN_WIDTH - 10) / BOARD_WIDTH;
		tempRectangle.h = (SCREEN_HEIGHT / 2 - 70) / BOARD_HEIGHT;
		switch (game_data->playerPiece.type)
		{
			case CUBE:
				SDL_FillRect(sdl_surface, &tempRectangle, SDL_MapRGB(sdl_surface->format, 0xff, 0xff, 0x00));
				break;
			case LONG:
				SDL_FillRect(sdl_surface, &tempRectangle, SDL_MapRGB(sdl_surface->format, 0xff, 0x00, 0xff));
				break;
			case L_LEFT:
				SDL_FillRect(sdl_surface, &tempRectangle, SDL_MapRGB(sdl_surface->format, 0x00, 0xff, 0xff));
				break;
			case L_RIGHT:
				SDL_FillRect(sdl_surface, &tempRectangle, SDL_MapRGB(sdl_surface->format, 0x00, 0xff, 0x00));
				break;
			default:
				break;
		}
	}


}

int main( int argc, char* args[] )
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "Droppy Blocks", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );

			//Fill the surface white


			SDL_Rect testRectangle;
			testRectangle.x = SCREEN_WIDTH / 2;
			testRectangle.y = SCREEN_HEIGHT / 2;
			testRectangle.w = 32;
			testRectangle.h = 32;


			// stuff for game window and handling close 
			SDL_Event event;
			gameData currentGameData;
			currentGameData.inputs = {false, false, false, false};
			currentGameData.playerPiece.type = NOT_A_PIECE;

			// game board: int represents color
			for(int i = 0; i < 10 * 24; i++)
			{
				currentGameData.gameBoard[i] = 0;
			}

			while (currentGameData.gameRunning)
			{

				while (SDL_PollEvent(&event))
				{
					switch (event.type)
					{
					case SDL_QUIT:
						currentGameData.gameRunning = false;
						break;
					case SDL_KEYDOWN:
						switch (event.key.keysym.sym)
						{
						case SDLK_UP:
							currentGameData.inputs.up = true;
							break;
						case SDLK_DOWN:
							currentGameData.inputs.down = true;
							break;
						case SDLK_LEFT:
							currentGameData.inputs.left = true;
							break;
						case SDLK_RIGHT:
							currentGameData.inputs.right= true;
							break;
						default:
							break;
						}
						break;
					case SDL_KEYUP:
						switch (event.key.keysym.sym)
						{
						case SDLK_UP:
							currentGameData.inputs.up = false;
							break;
						case SDLK_DOWN:
							currentGameData.inputs.down = false;
							break;
						case SDLK_LEFT:
							currentGameData.inputs.left = false;
							break;
						case SDLK_RIGHT:
							currentGameData.inputs.right = false;
							break;
						default:
							break;
						}
					default:
						break;

					}
				}

				SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xff, 0x00, 0x00 ) );

				if(currentGameData.inputs.right && testRectangle.x < SCREEN_WIDTH - 32)
				{
					testRectangle.x++;
				} else if (currentGameData.inputs.left && testRectangle.x > 0){
					testRectangle.x--;
				}


				updateAndRender(&currentGameData, screenSurface);
				// test rect
				SDL_FillRect(screenSurface, &testRectangle, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));

				//Update the surface
				SDL_UpdateWindowSurface(window);

				SDL_Delay(2000);

			}
		}
	}

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}

