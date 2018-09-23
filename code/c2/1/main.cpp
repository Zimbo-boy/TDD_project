#include <gmock/gmock.h>
#include "Playground.h"

int main(int argc, char** argv) {
   testing::InitGoogleMock(&argc, argv);
   Playground();
   return RUN_ALL_TESTS();
}

