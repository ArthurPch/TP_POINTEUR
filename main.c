#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    printf("Choisissez une option (0 pour quitter)\n");
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

void updateMenu(Application* app, int menuIndex, const char* newOption) {
    if (menuIndex < 0 || menuIndex >= app->nb_menus) {
        printf("Index de menu invalide.\n");
        return;
    }
    app->menus[menuIndex].option = newOption;
    printf("Option %d du menu de '%s' mise a jour avec succes.\n", menuIndex + 1, app->nom);
}

void updateApplication(Application* app, const char* newName, Menu* newMenus, int newMenuCount) {
    app->nom = newName;
    app->menus = newMenus;
    app->nb_menus = newMenuCount;
    printf("L'application '%s' a ete mise à jour avec succes.\n", newName);
}

void runPhone(Application *app1, Application *app2) {
    int choix;

    while (1) {
        printf("--- Applications ---\n");
        printf("1. %s\n", app1->nom);
        printf("2. %s\n", app2->nom);
        printf("3. Modifier le menu de '%s'\n", app1->nom);
        printf("4. Modifier l'application '%s'\n", app2->nom);
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
            case 3: {
                int menuIndex;
                char newOption[100];
                printf("Entrez l'index de l'option à modifier (1 a %d) : ", app1->nb_menus);
                scanf("%d", &menuIndex);
                getchar(); 
                printf("Entrez le nouvel intitule : ");
                fgets(newOption, sizeof(newOption), stdin);
                newOption[strcspn(newOption, "\n")] = '\0'; 
                updateMenu(app1, menuIndex - 1, newOption);
                break;
            }
            case 4: {
                char newName[100];
                int newMenuCount;
                printf("Entrez le nouveau nom de l'application : ");
                getchar();
                fgets(newName, sizeof(newName), stdin);
                newName[strcspn(newName, "\n")] = '\0'; 

                printf("Entrez le nombre de nouvelles options : ");
                scanf("%d", &newMenuCount);

                Menu *newMenus = malloc(newMenuCount * sizeof(Menu));
                for (int i = 0; i < newMenuCount; i++) {
                    char option[100];
                    printf("Entrez l'intitule de l'option %d : ", i + 1);
                    getchar(); 
                    fgets(option, sizeof(option), stdin);
                    option[strcspn(option, "\n")] = '\0'; 
                    newMenus[i].option = strdup(option);
                }

                updateApplication(app2, newName, newMenus, newMenuCount);
                break;
            }
            default:
                printf("Option invalide.\n");
        }
    }
}

int main() {
    runPhone(&photoApp, &messageApp);
    return 0;
}

