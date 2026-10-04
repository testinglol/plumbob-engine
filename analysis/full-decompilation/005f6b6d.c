
undefined4 __fastcall FUN_005f6b6d(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  piVar2 = (int *)FUN_00492d2c();
  if ((((piVar2 == param_1) && ((char)param_1[0x55] != '\0')) && (0 < param_1[0x54])) &&
     (param_1[0x54] < 5)) {
    uVar3 = FUN_005fd8ea();
    if (200 < uVar3) {
      iVar1 = param_1[0x54];
      if (iVar1 == 1) {
        (**(code **)(param_1[0x49] + 8))();
      }
      else if (iVar1 == 2) {
        (**(code **)(param_1[0x49] + 0xc))();
      }
      else if (iVar1 == 3) {
        (**(code **)(param_1[0x49] + 0x10))();
      }
      else if (iVar1 == 4) {
        (**(code **)(param_1[0x49] + 0x14))();
      }
      param_1[0x50] = 0;
      param_1[0x4e] = 0;
      param_1[0x51] = 0;
      param_1[0x4f] = 0;
      FUN_005772e2();
    }
    (**(code **)(*param_1 + 0x168))();
  }
  if (param_1[0x42] == 0) {
    FUN_005f69c1();
  }
  else {
    FUN_005f6677();
  }
  return 1;
}

