
void __fastcall FUN_00588232(int *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0xc))();
  (**(code **)(*param_1 + 0x10))();
  if (param_1[0x93] != 0) {
    FUN_005954c1();
  }
  if (param_1[2] != 0) {
    if (param_1[3] != 0) {
      FUN_005a0903(param_1[3]);
      param_1[3] = 0;
    }
    if (param_1[4] != 0) {
      FUN_005a0903(param_1[4]);
      param_1[4] = 0;
    }
    if (param_1[0x4f] != 0) {
      FUN_005a0903(param_1[0x4f]);
      param_1[0x4f] = 0;
    }
    if (param_1[5] != 0) {
      FUN_005a0903(param_1[5]);
      param_1[5] = 0;
    }
  }
  iVar1 = param_1[0x53];
  if (iVar1 != 0) {
    FUN_00588349();
    FUN_006321f0(iVar1);
  }
  iVar1 = param_1[0x51];
  param_1[0x53] = 0;
  if (iVar1 != 0) {
    FUN_00588349();
    FUN_006321f0(iVar1);
  }
  iVar1 = param_1[0x50];
  param_1[0x51] = 0;
  if (iVar1 != 0) {
    FUN_00588349();
    FUN_006321f0(iVar1);
  }
  iVar1 = param_1[0x52];
  param_1[0x50] = 0;
  if (iVar1 != 0) {
    FUN_00588349();
    FUN_006321f0(iVar1);
  }
  param_1[0x52] = 0;
  iVar1 = param_1[2];
  if (iVar1 != 0) {
    FUN_005a0759();
    FUN_006321f0(iVar1);
  }
  param_1[2] = 0;
  return;
}

