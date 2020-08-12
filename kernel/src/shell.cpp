#include <types.h>
#include <keyboard.h>
#include <memory.h>
#include <screen.h>
#include <shell.h>

void printPrefix() {
    print("$ ");
}

void run(char *cmd) {
    
}

void shell() {
    char cmd[1024];
    size_t i = 0;

    printPrefix();

    while (true) {
        KeyEvent e = readKey();
        
        if (e.type != KeyEventType::Pressed) {
            continue;
        }
        
        if (e.key == KeyCode::Backspace) {
            if (i > 0) {
                backspace();
                cmd[i--] = '\0';
            }
        } 
        else if (e.key == KeyCode::Enter) {
            enter();
            run(cmd);
            printPrefix();
            
            memset(cmd, 0, 1024);
            i = 0;
        }
        else if (e.key == KeyCode::Tab) {
            memset(cmd + i, ' ', 4);
            i += 4;
            print("    ");
        }
        else {
            uint_8 c = keyEventToAscii(&e);
            if (c != 0) {
                cmd[i++] = c;
                print(c);
            }
        }
    }
}