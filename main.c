#include <stdio.h>

void main(void) {
        
        char hello_world = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";

        unsigned char cells[30000];

        int ptr = 0;

        for(int i = 0; i < strlen(hello_world); ++i) {
                switch(hello_world[i]) {
                    case '>':
                        ++ptr;
                        break;
                    case '<':
                        --ptr;
                        break;
                    case '+':
                        ++cells[ptr] ;
                        break;
                    case '-':
                        --cells[ptr] ;
                        break;
                    case '[':
                        break;
                    case ']':
                        break;
                    case ',':
                        unsigned char value = getchar();
                        ptr = value;
                        break;
                    case '.':
                        putchar(cells[ptr]);
                    default:
                        continue;
                }
        }

}
