
undefined4 __fastcall FUN_00562d9f(int *param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  
  cVar2 = (**(code **)(*param_1 + 200))();
  if (cVar2 != '\0') {
    uVar3 = thunk_FUN_005dbf32();
    return uVar3;
  }
  thunk_FUN_005dbf32();
  FUN_005a5631(0x13b0,param_1 + 0x66,4);
  piVar1 = (int *)param_1[0x66];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x68))(DAT_006f2a64);
  }
  param_1[0x3e] = 0;
  param_1[0x3d] = 1;
  (**(code **)(*DAT_006fe8bc + 0x18))();
  iVar4 = FUN_005e74ca(0x20);
  param_1[0x74] = iVar4;
  (**(code **)(*DAT_006fe8bc + 0x18))();
  iVar4 = FUN_005e74ca(0x24);
  param_1[0x54] = 0;
  param_1[0x75] = iVar4;
  return 1;
}

