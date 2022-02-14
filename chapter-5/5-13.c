// tail
// Fixed dropped characters (note: whitespace formatting may be mangled slightly)
// open specified FILE (if non-existent, then STDIN)
// create a fixed-sized temporary buffer to store the results from read
// have an array of the N most recently seen lines (dynamically allocated based on the size of N)
// read from the buffer into arr[i], overwriting (and freeing) older lines

#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>

struct lineStatus {
    char * line;
    bool isComplete;
    int len;
};

typedef struct lineStatus lineStatus;

struct circular {
    char ** linebuf;
    int insert;
    int remove;
    int length;
    int maxlen;
};

typedef struct circular circular;

int getline(char * buffer, size_t buflen, lineStatus* ls) {
    // if ls->line is NULL, start reading a new line
    int c, currentSize = 1, len = 0, oldLen = 0;
    if (ls->line == NULL) {
        ls->line = malloc(currentSize * sizeof(char));
    }
    // otherwise, start reading more characters from position len 
    else {
        currentSize = ls->len;
        len = ls->len;
        oldLen = ls->len;
    }
    
    for (int i = 0; i < buflen && buffer[buflen]; i++) {
        //allocate more space if needed
        if (oldLen + i - 2 > currentSize) {
            currentSize *= 2;
            ls->line = realloc(ls->line, currentSize * sizeof(char));
        }
        ls->line[i+oldLen] = buffer[i];
        len++;
        if (buffer[i] == '\n') {
            ls->isComplete = true;
            break;
            // newlines are captured
        }
    }
    ls->line = realloc(ls->line, (len+1)*sizeof(char));
    (ls->line)[len] = '\0';
    
    // if a newline is encountered, set isComplete to true, len to line length

    // otherwise, keep isComplete false and set len to length of contents seen so far
    ls->len = oldLen + len;
    return len;
}

int main(int argc, char** argv) {
    int lines = 10;
    int usedlines = 0;

    int opt;
    while ((opt = getopt(argc, argv, "n:")) != -1) {
        switch(opt) {
            case 'n':
                lines = atoi(optarg);
                if (lines < 0) {
                    fprintf(stderr, "Cannot output a negative number of lines.\n");
                    exit(EXIT_FAILURE);
                }
                break;
        }
    }
    //printf("%d %d\n", lines, optind);
    int fd = STDIN_FILENO;
    if (optind < argc) {
        fd = open(argv[optind], O_RDONLY);
    }
    circular c;
    c.insert = 0;
    c.remove = 0;
    c.length = 0;
    c.maxlen = lines;
    c.linebuf = (char**)malloc(sizeof(char*) * c.maxlen);
    for (int i = 0; i < c.maxlen; i++) {
        c.linebuf[i] = NULL;
    }

    size_t bufsize = 2048;
    char buffer[bufsize+1];
    ssize_t bufread;

    int currentLen = 0;

    lineStatus nextLine;
    nextLine.line = NULL;
    nextLine.len = 0;
    nextLine.isComplete = false;
    
    size_t buf_offset = 0;

    while (bufread = read(fd, buffer, bufsize)) {
        if (bufread == -1) {
            break;
        }
        
        while (buf_offset < bufsize) {
            buf_offset += getline(buffer+buf_offset, bufsize-buf_offset, &nextLine);
            // is line complete?
            if (nextLine.isComplete) {
                // displace line from linebuf
                if (c.length == c.maxlen) {
                    free(c.linebuf[c.insert]);
                    c.remove = (c.remove + 1) % c.maxlen;
                }
                else {
                    c.length += 1;
                }
                c.linebuf[c.insert] = nextLine.line;
                c.insert = (c.insert + 1) % c.maxlen;

                nextLine.isComplete = false;
                nextLine.len = 0;
                nextLine.line = NULL;
            }
        }
        buf_offset = 0;        
        memset(buffer, 0, bufsize * sizeof(char));
    }
    
    // change to account for wrapping
    int offset;
    for (int i = 0; i < c.maxlen; i++) {
        offset = (c.remove + i) % c.maxlen;
        if (c.linebuf[offset] != NULL) {
            printf("%s", c.linebuf[offset]);
        }
    }

    for (int i = 0; i < c.maxlen; i++) {
        if (c.linebuf[i] != NULL) {
            free(c.linebuf[i]);
        }
    }
    free(c.linebuf);

    if (fd != STDIN_FILENO) {
        close(fd);
    }
    exit(EXIT_SUCCESS);
}
