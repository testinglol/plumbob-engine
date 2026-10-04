
void __thiscall
FUN_00533258(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  FUN_005dda18(param_2,param_3,param_4,param_5);
  param_1[0x43] = param_1[0x1f];
  param_1[0x44] = param_1[0x20];
  param_1[0x45] = param_1[0x21];
  param_1[0x46] = param_1[0x22];
  iVar2 = param_1[0x44];
  iVar1 = param_1[0x43];
  param_1[0x44] = param_1[0x44] + -iVar2;
  param_1[0x46] = param_1[0x46] + -iVar2;
  param_1[0x43] = param_1[0x43] + -iVar1;
  param_1[0x45] = param_1[0x45] + -iVar1;
  param_1[0x44] = param_1[0x44] + 5;
  param_1[0x45] = param_1[0x45] + -100;
  param_1[0x4b] = param_1[0x1f];
  param_1[0x4c] = param_1[0x20];
  param_1[0x4d] = param_1[0x21];
  param_1[0x4e] = param_1[0x22];
  param_1[0x4b] = param_1[0x45];
  param_1[0x47] = param_1[0x43];
  param_1[0x48] = param_1[0x44];
  param_1[0x49] = param_1[0x45];
  param_1[0x4a] = param_1[0x46];
  if ((int *)param_1[0x39] == (int *)0x0) {
    param_1[0x48] = param_1[0x4a];
  }
  else {
    iVar2 = (**(code **)(*(int *)param_1[0x39] + 0x58))();
    param_1[0x48] = param_1[0x4a] - iVar2;
    param_1[0x46] = param_1[0x4a] - iVar2;
  }
  param_1[0x4f] = param_1[0x45];
  (**(code **)(*param_1 + 0x168))();
  return;
}

