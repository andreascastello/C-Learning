#include <SDL2/SDL.h>
#include <stdio.h>


void afficherImage ( int x ,int y ,SDL_Renderer* renderer ,char* nomFichier )
{
     SDL_Surface* surface_image = SDL_LoadBMP (nomFichier);

     if ( surface_image )
     {
         SDL_Texture* image = SDL_CreateTextureFromSurface ( renderer , surface_image );

         if ( image )
         {
             SDL_SetRenderTarget ( renderer , image );

             SDL_Rect r;
             r.x = x;
             r.y = y;

             SDL_QueryTexture ( image, NULL, NULL, &(r.w), &(r.h));

             printf ("On rend l'image dans le rectangle %d %d %d %d\n", r.x, r.y, r.w, r.h);

             SDL_RenderCopy ( renderer , image , NULL , &r);
             SDL_SetRenderTarget ( renderer , NULL );
             SDL_DestroyTexture (image);
         }
         else {
            fprintf (stderr, "Erreur de création de la texture\n");
         }

         SDL_FreeSurface (surface_image);
     }
     else {
        fprintf (stderr, "Erreur de chargement de l'image %s\n", nomFichier);
     }
}


int main(int argc, char** argv)
{

  char labyrinthe [4][8] = {    "#######" ,
                                "#J#   #" ,
                                "#   # #" ,
                                "#######" };

  int xJoueur = 1;
  int yJoueur = 1;

 SDL_Event event;

     if ( SDL_Init (SDL_INIT_VIDEO) != 0 )
     {
         fprintf (stderr, "Erreur d'initialisation du mécanisme SDL : %s\n", SDL_GetError() );
         return EXIT_FAILURE;
     }
     SDL_Window* fenetre = SDL_CreateWindow ("Exemple 5" ,SDL_WINDOWPOS_UNDEFINED ,SDL_WINDOWPOS_UNDEFINED ,1280 ,720 ,SDL_WINDOW_SHOWN);

     if ( fenetre == NULL )
     {
         fprintf (stderr, "Erreur de création de la fenêtre : %s\n",SDL_GetError());
         return EXIT_FAILURE;
     }

     SDL_RendererInfo info;

     int nbDrivers = SDL_GetNumRenderDrivers ();
     for ( int i=0; i<nbDrivers; i++)
     {
         SDL_GetRenderDriverInfo ( i, &info );

         printf ("Driver numero %d : \n", i);
         printf (" - name : %s \n", info.name);
         printf (" - flags : ");

         if ( info.flags & SDL_RENDERER_SOFTWARE ) printf ("SDL_RENDERER_SOFTWARE ");
         if ( info.flags & SDL_RENDERER_ACCELERATED ) printf ("SDL_RENDERER_ACCELERATED ");
         if ( info.flags & SDL_RENDERER_PRESENTVSYNC ) printf ("SDL_RENDERER_PRESENTVSYNC ");
         if ( info.flags & SDL_RENDERER_TARGETTEXTURE) printf ("SDL_RENDERER_TARGETTEXTURE ");
         printf ("\n");
     }

     SDL_Renderer* renderer = SDL_CreateRenderer ( fenetre, -1, SDL_RENDERER_ACCELERATED);

     SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
  int fin = 0;
do
{
     SDL_RenderClear(renderer);

    for ( int y = 0 ; y < 4; y++ )
     {
      for ( int x = 0 ; x < 8; x++ )
       {
        if ( x == xJoueur && y == yJoueur )
              {
               afficherImage ( x*100, y*100, renderer , "n.bmp");
              }
         else {
               switch (labyrinthe[y][x])
                {
                 case  '#' : afficherImage ( x*100, y*100, renderer , "mur.bmp");
                }
              }
       }
      printf ("\n");
     }
     SDL_RenderPresent(renderer);

     SDL_WaitEvent (&event);

     switch (event.type){
        case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
            case SDLK_z: if ( labyrinthe[yJoueur-1][xJoueur  ] != '#' ) yJoueur--; break;
            case SDLK_q: if ( labyrinthe[yJoueur  ][xJoueur-1] != '#' ) xJoueur--; break;
            case SDLK_d: if ( labyrinthe[yJoueur  ][xJoueur+1] != '#' ) xJoueur++; break;
            case SDLK_s: if ( labyrinthe[yJoueur+1][xJoueur  ] != '#' ) yJoueur++; break;
            case SDLK_ESCAPE: fin = 1; break;
        }
     }
}
while (fin == 0);
     SDL_DestroyRenderer (renderer);
     SDL_DestroyWindow (fenetre);
     SDL_Quit ();
 return EXIT_SUCCESS;
}
