#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
int main (int argc, char** argv)
{
 int largeurDeLaFenetre = 800;
 int hauteurDeLaFenetre = 600;
 SDL_Init (SDL_INIT_VIDEO);
 SDL_Window* displayWindow;
 SDL_RendererInfo displayRendererInfo;
 SDL_Renderer* displayRenderer;
 SDL_CreateWindowAndRenderer ( largeurDeLaFenetre ,
 hauteurDeLaFenetre ,
SDL_WINDOW_OPENGL ,
&displayWindow ,
&displayRenderer );

SDL_GetRendererInfo ( displayRenderer ,
 &displayRendererInfo );
 int quitter = 0;
 SDL_Event ev;
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f (1,1,0);
 glBegin(GL_TRIANGLES);
 glVertex2f(-1,0);
 glVertex2f(1,1);
 glVertex2f(1,-1);
 glEnd();
 glFlush();
 SDL_RenderPresent (displayRenderer);
 do
 {
 if (SDL_WaitEvent (&ev) == 1)
 quitter = (ev.type == SDL_KEYDOWN);
 }
 while (!quitter);
 SDL_Quit();
 return 0;
}
