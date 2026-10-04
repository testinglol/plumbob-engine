
void __thiscall FUN_005f436c(int *param_1,undefined4 param_2,char param_3,char param_4)

{
  int iVar1;
  int iVar2;
  
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x4b] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  FUN_005f2c6c(0,0,1);
  FUN_005f3a06(0);
  FUN_005f371b(0,(param_1[0x3a] - param_1[0x39]) + -1);
  FUN_005f3220(param_2);
  if ((param_3 == '\0') || (param_1[0x3a] - param_1[0x39] == 1)) {
    if (param_4 == '\0') {
      iVar1 = (param_1[0x3a] - param_1[0x39]) + -1;
      goto LAB_005f441a;
    }
    iVar1 = 0;
  }
  else {
    if (param_4 == '\0') {
      iVar1 = 0;
LAB_005f441a:
      iVar2 = (param_1[0x3a] - param_1[0x39]) + -1;
      goto LAB_005f4428;
    }
    iVar1 = (param_1[0x3a] - param_1[0x39]) + -1;
  }
  iVar2 = 0;
LAB_005f4428:
  FUN_005f371b(iVar2,iVar1);
  (**(code **)(*param_1 + 0x168))();
  return;
}

