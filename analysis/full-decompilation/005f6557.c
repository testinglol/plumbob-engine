
void __thiscall FUN_005f6557(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  if (param_1[0x42] != 0) {
    if (param_1[0x35] == 2) {
      param_4 = (param_1[0x45] - param_1[0x43]) + param_2;
    }
    else {
      if (param_1[0x35] != 1) goto LAB_005f65b2;
      param_5 = (param_1[0x46] - param_1[0x44]) + param_3;
    }
  }
  FUN_005dda18(param_2,param_3,param_4,param_5);
LAB_005f65b2:
  (**(code **)(*param_1 + 0x1c8))();
  return;
}

