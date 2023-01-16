#include "App.h"
//keep this clean!
int main(int argc, char** argv) {
    GlutApp* app = new App(argc, argv, 1280, 720, "Asteroids");

    app->run();
}
