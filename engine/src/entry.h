#pragma once

#include "core/application.h"

int main(int argc, char* argv[]) {
  Lord::Application app;

  app.create();
  app.run();

  return 0;
}
