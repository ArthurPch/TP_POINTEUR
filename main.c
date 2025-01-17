    #include <stdio.h>

    int main(){

        typedef struct Menu
        {
            const char *option;
        }Menu;

        typedef struct Application
        {
            const char *nom;
            Menu *menus;
            int nb_menus;

        }Application;



        Menu menu1 = {"Option 1"};
        printf("Menu: %s\n", menu1.option);
        



        
        return 0;
    }

    // gcc "./*.c" -o main.exe
    //.\main.exe