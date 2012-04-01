#include <QApplication>
#include "Hasher.h"

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  Hasher theHasher;
  theHasher.show();

  return app.exec();
}
