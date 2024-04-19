#include <stdlib.h>

int main() {
    // Open index.html in default web browser
    system("start Frontend\\index.html");

    // Run backend.py
    system("python Backend\\backend.py");

    return 0;
}
