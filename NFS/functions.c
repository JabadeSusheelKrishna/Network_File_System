# include "headers.h"

void print_s(char* Message, int status_code)
{
    if(status_code == Success){
        printf(GRN "[+]  %s ---\n" WHT, Message);
    }
    else if(status_code == Failure){
        printf(RED "[-]  %s ***\n" WHT, Message);
    }
    else if(status_code == Other_y){
        printf(YEL "%s\n\n" WHT, Message);
    }
}