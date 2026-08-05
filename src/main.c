#include "lvgl/lvgl.h"
#include "ui.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
    // 1. Initialisation de LVGL
    lv_init();

    // 2. Création forcée de la fenêtre de simulation (Résolution à adapter si besoin)
    lv_display_t * disp = lv_sdl_window_create(800, 480);
    if(disp == NULL) {
        return -1;
    }

    // Initialisation des périphériques de saisie (souris/clavier)
    lv_sdl_mouse_create();
    lv_sdl_keyboard_create();

    // 3. Lancement automatique de votre interface graphique SquareLine
    ui_init();

    // 4. Boucle infinie pour faire vivre l'écran
    while (1) {
        lv_timer_handler();
        usleep(5000); // Petite pause de 5ms pour le processeur
    }
    return 0;
}
