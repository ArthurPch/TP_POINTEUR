#include <stdio.h>

typedef struct Menu {
    const char *option;
} Menu;

typedef struct Application {
    const char *nom;
    Menu *menus;
    int nb_menus;
} Application;

Menu photoMenus[] = {
    {"Regarder une photo"},
    {"Prendre une photo"}
};

Application photoApp = {
    .nom = "Photos",
    .menus = photoMenus,
    .nb_menus = 2
};

void displayMenu(const Application* app) {
    printf("--- %s ---\n", app->nom); 
    for (int i = 0; i < app->nb_menus; i++) {
        printf("%d. %s\n", i + 1, app->menus[i].option); 
    }
    printf("Choisissez une option (0 pour quitter) :\n"); 
}

int main() {
    
    displayMenu(&photoApp);

    return 0;
}


    // gcc "./*.c" -o main.exe
    //.\main.exe