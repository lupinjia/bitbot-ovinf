#include "user_func.hpp"

int main(int argc, char const *argv[]) {
  MakeBitbotEverywhere everyone(
      "/home/jason/bitbot-ovinf/config/hhfc/hhfc_mj.xml",
      "/home/jason/bitbot-ovinf/config/hhfc/robot.yaml");
  everyone.WillMake();
  everyone.BeMaking();
  everyone.HaveMade();
  return 0;
}
