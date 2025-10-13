#include "get_next_line.h"

static char *extract_line(char **sbuffer)
{
    char *newline_position;
    size_t line_len;
    char *line;
    char *temp;
    size_t  rest_len;

    if (!*sbuffer || !**sbuffer)
        return (NULL);
    newline_position = ft_strchr(*sbuffer, '\n');
    if (newline_position)
    {
        line_len = newline_position - *sbuffer + 1;  // the +1 for including the new line
        line = ft_calloc(line_len + 1, sizeof(char));
        if (!line)
            return (NULL);
        ft_memcpy(line, *sbuffer, line_len);
        line[line_len] = '\0';

        rest_len = ft_strlen(newline_position + 1);
        if (rest_len > 0)
        {
            temp = ft_calloc(rest_len, sizeof(char));
            if (!temp)
            {
                free(line);
                return (NULL);
            }
            ft_memcpy(temp, newline_position + 1, rest_len);
            temp[rest_len] = '\0';
            *sbuffer = temp;
        }
        else
        {
            free(*sbuffer);
            *sbuffer = NULL;
        }
        return (line);
    }
    line = *sbuffer;
    *sbuffer = NULL;
    return (line);
}
static char *read_file(int fd, char *sbuffer)
{
    int byte_read;
    char *buffer;
    char *temp;

    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
        return (NULL);

    byte_read = 1;
    while (byte_read >= 0)
    {
        byte_read = read(fd, buffer, BUFFER_SIZE);

        if (byte_read == 0)
            break;

        if (!sbuffer)   // so we don't have ft_strjion(NULL, buffer);
            sbuffer = ft_calloc(1, 1);

        buffer[byte_read] = '\0';
        temp = ft_strjoin(sbuffer, buffer);
        free(sbuffer);
        sbuffer = temp; // prevent memory leaks because dtrjoin allocate memory

        if (!sbuffer)
        {
            free(buffer);
            return (NULL);
        }
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return (sbuffer);
}

char *get_next_line(int fd)
{
    static char    *sbuffer;
    char        *line;

    // error handling 
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    sbuffer = read_file(fd, sbuffer);
    if (!sbuffer)
        return (NULL);
    line = extract_line(&sbuffer);
    return (line);
}