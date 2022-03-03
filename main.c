#include <stdio.h>
#include <string.h>

int stack[100];

int *sp;

#define push(sp, n) (*((sp)++) = (n))
#define pop(sp) (*--(sp))

void main(void) {
        
        sp = stack;
        
        char hello_world[256] = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";

        unsigned char cells[30000];

        int ptr = 0;
        for(size_t i = 0; i < strlen(hello_world); ++i) {
                switch(hello_world[i]) {
                    case '>':
                        ++ptr;
                        break;
                    case '<':
                        --ptr;
                        break;
                    case '+':
                        cells[ptr]++;
                        break;
                    case '-':
                        cells[ptr]--;
                        break;
                    case '[':
                        if (cells[ptr] != 0) {
                               push(sp, i);
                        }
                        break;
                    case ']':
                        if (cells[ptr] != 0) {
                            size_t x = pop(sp);
                            i = (--x);
                        } else {
                                pop(sp);
                        }
                        break;
                    case ',': ;
                        char value = getchar();
                        ptr = value;
                        break;
                    case '.':
                        putchar(cells[ptr]);
                        break;
                    default:
                        continue;
                }
        }

}
