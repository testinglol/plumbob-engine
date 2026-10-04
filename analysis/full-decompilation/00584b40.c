
void __fastcall FUN_00584b40(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0xac))();
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 0xc))();
    (**(code **)(*param_1 + 0x10))();
    iVar1 = param_1[3];
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 0xac))(iVar1);
      FUN_005a0903(iVar1);
      param_1[3] = 0;
    }
    iVar1 = param_1[4];
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 0xac))(iVar1);
      FUN_005a0903(iVar1);
      param_1[4] = 0;
    }
    iVar1 = param_1[5];
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 0xac))(iVar1);
      FUN_005a0903(iVar1);
      param_1[5] = 0;
    }
    iVar1 = param_1[2];
    if (iVar1 != 0) {
      FUN_005a0759();
      FUN_006321f0(iVar1);
    }
    param_1[2] = 0;
  }
  return;
}

