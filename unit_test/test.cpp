#include "gtest/gtest.h"

#include "enchant_TEST.hpp"
#include "seqMan_TEST.hpp"
#include "creation_TEST.hpp"
#include "attacks_TEST.hpp"
#include "battle_TEST.hpp"
#include "storage_TEST.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
