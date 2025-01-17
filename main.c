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

Menu messageMenus[] = {
    {"Lire un message"},
    {"Envoyer un message"}
};

Application photoApp = {
    .nom = "Photos",
    .menus = photoMenus,
    .nb_menus = 2
};

Application messageApp = {
    .nom = "Messages",
    .menus = messageMenus,
    .nb_menus = 2
};

void displayMenu(const Application *app) {
    printf("--- %s ---\n", app->nom);
    for (int i = 0; i < app->nb_menus; i++) {
        printf("%d. %s\n", i + 1, app->menus[i].option);
    }
    printf("Choisissez une option (0 pour quitter) \n");
}

void runApplication(const Application *app) {
    int choix;

    while (1) {
        displayMenu(app);

        printf("Choix : ");
        scanf("%d", &choix);

        if (choix == 0) {
            printf("Quitter l'application.\n");
            break;
        }

        if (choix > 0 && choix <= app->nb_menus) {
            printf("Vous avez selectionne : %s\n", app->menus[choix - 1].option);
        } else {
            printf("Option invalide.\n");
        }
    }
}

void runPhone(Application *app1, Application *app2) {
    int choix;

    while (1) {
        printf("--- Applications ---\n");
        printf("1. %s\n", app1->nom);
        printf("2. %s\n", app2->nom);
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        if (choix == 0) {
            printf("Au revoir !\n");
            break;
        }

        switch (choix) {
            case 1:
                runApplication(app1);
                break;
            case 2:
                runApplication(app2);
                break;
            default:
                printf("Option invalide.\n");
        }
    }
}

int main() {
    runPhone(&photoApp, &messageApp);
    return 0;
}
