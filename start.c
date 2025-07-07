#include <stdio.h> // comando clear i exit no hacen su funcion
#include <string.h>
#include <stdlib.h>

int main() {
    printf("Welcome to Ferrer Os (beta)\n");

    float version = 0.1;
    char username[50];
    char command[100];

    printf("Version: %.1f\n", version);
    printf("This is a simple beta version of Ferrer Os.\n");

    if (version < 1.0) {
        printf("This is a beta version, so it contains bugs and errors.\n");
    }

    // Pedir nombre de usuario
    printf("Please enter your username: ");
    scanf("%s", username);
    getchar(); // consumir salto de línea

    printf("Hello %s, welcome to Ferrer Os.\n", username);

    // Bucle de comandos
    while (1) {
        printf("\033[38;2;50;205;50m@%s~$ \033[38;2;0;102;255m:\033[0m ", username);
        if (fgets(command, sizeof(command), stdin) == NULL) break;

        // Eliminar el salto de línea final si existe
        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        if (strcmp(command, "clear") == 0) {
            printf("\033[H\033[J");  // Limpiar pantalla
        } else if (strcmp(command, "command") == 0) {
            printf("This is the first command created in Ferrer Os (beta): %s\n", command);
        } else if (strcmp(command, "exit") == 0) {// no cierra el programa
            exit(0);
             break;
        } else if (strcmp( command, "date") == 0){
            system("date");
        } else if (strcmp(command,"help") == 0) {        // comando help
            printf ( "Available commands \n");
            printf ("clear - Clear the screen \n");
            printf ("command - Show a message about the first command\n");
            printf ("exit - Close the Ferrer OS (beta)\n");
            printf ("help - Show every availble commands\n");
            printf ("date - Show the current date and time\n");
            printf ("ls - List files in the current directory\n");
            printf ("pwd - Show the current working directory\n");
            printf ("whoami - Show your username\n");
            printf ("version - Show the version of Ferrer Os\n");

        } else if (strcmp(command,"ls") == 0) {
            system("ls");            /* code */
        }else if (strcmp(command,"pwd") == 0) {
            system("pwd");
        }else if (strcmp(command,"whoami") == 0) {
            printf("Your username is: %s\n", username);
        }else if (strcmp(command, "version") == 0) {
            printf ("The actually Ferrer Os version is %.1f\n", version);
        } else {
            printf("Command not recognized. Please try again\n");
        }
    }

    return 0;
}
