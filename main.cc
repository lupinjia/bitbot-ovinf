#include "user_func.hpp"

int main(int argc, char const *argv[]) {
  MakeBitbotEverywhere everyone(
      "/home/huahui/Project/bitbot-ovinf/config/hhfc/hhfc_cifx.xml",
      "/home/huahui/Project/bitbot-ovinf/config/hhfc/robot-deploy.yaml");
  everyone.WillMake();
  everyone.BeMaking();
  everyone.HaveMade();
  return 0;
}
