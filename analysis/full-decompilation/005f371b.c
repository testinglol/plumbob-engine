
void __thiscall FUN_005f371b(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_2 == param_3) {
    param_2 = param_2 - param_1[0x35];
    uVar1 = 0;
  }
  else if (param_2 < param_3) {
    if (param_2 < 0) {
      param_2 = 0;
    }
    if ((param_1[0x3a] - param_1[0x39]) + -1 < param_3) {
      param_3 = (param_1[0x3a] - param_1[0x39]) + -1;
    }
    FUN_005f2c6c(param_2 - param_1[0x35],0,0);
    param_2 = param_3 - param_2;
    uVar1 = 1;
  }
  else {
    if (param_3 < 0) {
      param_3 = 0;
    }
    if ((param_1[0x3a] - param_1[0x39]) + -1 < param_2) {
      param_2 = (param_1[0x3a] - param_1[0x39]) + -1;
    }
    FUN_005f2c6c(param_2 - param_1[0x35],0,0);
    uVar1 = 1;
    param_2 = param_3 - param_2;
  }
  FUN_005f2c6c(param_2,uVar1,0);
  (**(code **)(*param_1 + 0x168))();
  return;
}

