#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *get_string(char *str);


int main(void)
{

    char *text = get_string("Text: ");
    if (text == NULL)
    {
        printf("Seg fault!\n");
        return 1;
    }
  
    free(text);

}

char *get_string(char *str)
{
    printf("%s", str);
    int n = sizeof(char) * 1000;
    char *text = malloc(n);
    fgets(text, n, stdin);

    return text;
}
