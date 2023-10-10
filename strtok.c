#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *my_z_strtok(char *text, char *delimiters)
{
    int len_tx;
    int i = 0;
    int len_tok;
    char *ptr;
    int len_tex_new = 0;
    char *tex_new;

    int c = 0, lo = 0, len_del = 0, del = 0, o = 0;

    if (text == NULL || delimiters == NULL)
    {
        return NULL;
    }

    len_tx = strlen(text);
    len_del = strlen(delimiters);

    for (i = 0; i < len_tx; i++)
    {

        for (del = 0; del < len_del;)
        {
            if (text[i] == delimiters[del])
            {
                text[i] = '\0';
                len_tok = strlen(text);
                ptr = (char *)malloc(len_tok + 1);

                if (ptr == NULL)
                {
                    return NULL;
                }

                for (o = 0; o < (len_tok + 1); o++)
                {
                    ptr[o] = text[o];
                }
                len_tex_new = (len_tx - len_tok);
                if (ptr[0] == '\0')
                {

                    tex_new = (char *)malloc(len_tex_new);

                    if (tex_new == NULL)
                    {
                        free(ptr);
                        return NULL;
                    }

                    i++;

                    for (c = 0; c < len_tex_new; c++)
                    {
                        *(tex_new + c) = text[i + c];
                    }
                    for (lo = 0; lo < len_tex_new; lo++)
                    {
                        *(text + lo) = *(tex_new + lo);
                    }
                    free(tex_new);
                    free(ptr);
                    i = 0;
                    del = 0;
                    continue;
                }

                tex_new = (char *)malloc(len_tex_new);

                if (tex_new == NULL)
                {
                    free(ptr);
                    return NULL;
                }

                i++;

                for (c = 0; c < len_tex_new; c++)
                {
                    *(tex_new + c) = text[i + c];
                }
                for (lo = 0; lo < len_tex_new; lo++)
                {
                    *(text + lo) = *(tex_new + lo);
                }
                free(tex_new);

                return (ptr);
            }
            del++;
        }
    }
    return (NULL);
}

int main()
{
    char text[] = "ls     -l         s\n";
    char delimiters[] = " \t\n";
    char *token;

    token = my_z_strtok(text, delimiters);

    while (text[0] != '\0' && token != NULL)
    {
        printf("Token: %s\n", token);

        free(token);

        token = my_z_strtok(text, delimiters);
    }
    printf("Token: %s\n", token);

    free(token);

    return 0;
}
