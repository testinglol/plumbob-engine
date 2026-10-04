
undefined1 __fastcall FUN_005f1ad8(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    uVar2 = FUN_005dbf32();
    return uVar2;
  }
  cVar1 = FUN_005dbf32();
  if (cVar1 == '\0') {
    return 0;
  }
  if (param_1[0x48] == param_1[0x46]) {
    param_1[0x46] = 5;
    param_1[0x47] = 0;
    param_1[0x48] = param_1[0x21] - param_1[0x1f];
    param_1[0x49] = param_1[0x22] - param_1[0x20];
  }
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  iVar3 = (**(code **)(*(int *)param_1[0x45] + 0x58))();
  iVar3 = (param_1[0x49] - param_1[0x47]) / iVar3;
  param_1[0x4c] = iVar3;
  if (iVar3 == 0) {
    param_1[0x4c] = 1;
  }
  if (param_1[0x4d] == 1) {
    iVar3 = (**(code **)(*(int *)param_1[0x45] + 0x58))();
    param_1[0x42] = 0x7fff;
    param_1[0x43] = iVar3;
  }
  else {
    param_1[0x42] = (param_1[0x48] - param_1[0x46]) + -5;
    param_1[0x43] = 0x7fff;
  }
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  FUN_005f3a06(0);
  uVar4 = FUN_005e749a(2);
  FUN_005dde6d(uVar4);
  if (((param_1[0x22] == param_1[0x20]) || (param_1[0x4c] < 1)) ||
     ((int *)param_1[0x45] == (int *)0x0)) {
    param_1[0x41] = 0;
  }
  else {
    iVar3 = (**(code **)(*(int *)param_1[0x45] + 0x58))();
    param_1[0x41] = ((param_1[0x22] - param_1[0x20]) - iVar3 * param_1[0x4c]) / 2;
  }
  FUN_005f398c(param_1[0x4b]);
  return 1;
}

