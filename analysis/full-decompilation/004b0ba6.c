
void __thiscall FUN_004b0ba6(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(param_1 + 0x4a4) < 1) {
    if (*(int *)(param_1 + 0x4a4) < 0) {
      FUN_004b06db(param_1 + 0x494,0xffffff,param_2,0);
      if ((*(int *)(param_1 + 0x68) != 0) && (DAT_006e4870 == '\0')) {
        FUN_005cf0fa(param_1 + 0x494);
      }
      *(undefined4 *)(param_1 + 0x47c) = 0;
      return;
    }
  }
  else {
    FUN_004b06db(param_1 + 0x494,0xffffff,param_2,0);
    if ((*(int *)(param_1 + 0x68) != 0) && (DAT_006e4870 == '\0')) {
      FUN_005cf0fa(param_1 + 0x494);
    }
  }
  if (DAT_006e5490 < *(uint *)(param_1 + 0x4b4)) {
    FUN_00473496(DAT_006e5490);
    if (*(int *)(param_1 + 0x480) == 0) {
      iVar2 = *(int *)(param_1 + 0x484);
      local_8 = *(int *)(param_1 + 0x28) - iVar2;
      local_18 = __ftol();
      local_18 = local_18 + iVar2;
      iVar2 = *(int *)(param_1 + 0x488);
      local_8 = *(int *)(param_1 + 0x2c) - iVar2;
      local_14 = __ftol();
      local_14 = local_14 + iVar2;
      iVar2 = *(int *)(param_1 + 0x48c);
      local_8 = *(int *)(param_1 + 0x30) - iVar2;
      local_10 = __ftol();
      local_10 = local_10 + iVar2;
      iVar2 = *(int *)(param_1 + 0x490);
      local_8 = *(int *)(param_1 + 0x34) - iVar2;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x28);
      local_8 = *(int *)(param_1 + 0x484) - iVar2;
      local_18 = __ftol();
      local_18 = local_18 + iVar2;
      iVar2 = *(int *)(param_1 + 0x2c);
      local_8 = *(int *)(param_1 + 0x488) - iVar2;
      local_14 = __ftol();
      local_14 = local_14 + iVar2;
      iVar2 = *(int *)(param_1 + 0x30);
      local_8 = *(int *)(param_1 + 0x48c) - iVar2;
      local_10 = __ftol();
      local_10 = local_10 + iVar2;
      iVar2 = *(int *)(param_1 + 0x34);
      local_8 = *(int *)(param_1 + 0x490) - iVar2;
    }
    local_c = __ftol();
    local_c = local_c + iVar2;
  }
  else {
    *(undefined4 *)(param_1 + 0x4a4) = 0xffffffff;
    if (*(int *)(param_1 + 0x480) == 0) {
      piVar1 = (int *)(param_1 + 0x28);
    }
    else {
      piVar1 = (int *)(param_1 + 0x484);
    }
    local_18 = *piVar1;
    local_14 = piVar1[1];
    local_10 = piVar1[2];
    local_c = piVar1[3];
  }
  FUN_004b06db(&local_18,0xffffff,param_2,0);
  *(int *)(param_1 + 0x494) = local_18;
  *(int *)(param_1 + 0x498) = local_14;
  *(int *)(param_1 + 0x49c) = local_10;
  *(int *)(param_1 + 0x4a0) = local_c;
  if (-1 < *(int *)(param_1 + 0x4a4)) {
    *(int *)(param_1 + 0x4a4) = *(int *)(param_1 + 0x4a4) + 1;
  }
  if ((*(int *)(param_1 + 0x68) != 0) && (DAT_006e4870 == '\0')) {
    FUN_005cf0fa((int *)(param_1 + 0x494));
  }
  return;
}

