

#include "input.h"


void getInput(void)
{
	SDL_Event event;

	/* Keymapping : g�re les appuis sur les touches et les enregistre
	dans la structure input */

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{

			case SDL_QUIT:
				exit(0);
			break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						exit(0);
					break;

					case SDLK_DELETE:
						input.erase = 1;
					break;

					case SDLK_SPACE:
						input.jump = 1;
                    break;

                  	case SDLK_q:
						input.attack = 1;
                    break;

					case SDLK_a:
						input.left = 1;
					break;

					case SDLK_d:
						input.right = 1;
					break;

					case SDLK_s:
						input.down = 1;
					break;

					case SDLK_z:
						input.up = 1;
					break;


					case SDLK_RETURN:
						input.enter = 1;
					break;


					default:
					break;
				}
			break;

			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
					case SDLK_DELETE:
						input.erase = 0;
					break;

                    case SDLK_SPACE:
						input.jump = 0;
                    break;

					case SDLK_a:
						input.left = 0;
					break;

					case SDLK_d:
						input.right = 0;
					break;

					case SDLK_s:
						input.down = 0;
					break;

					case SDLK_z:
						input.up = 0;
					break;

					case SDLK_RETURN:
						input.enter = 0;
					break;

					default:
					break;
				}
			break;

		}

	}
}




