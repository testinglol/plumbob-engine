
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_0052587a(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar2 = *(int *)(DAT_006e54dc + 0x10) / 2;
  FUN_00422055(iVar2,iVar2);
  iVar2 = *(int *)(param_1 + 0xd8);
  if (iVar2 != 0) {
    if (*(short *)(*(int *)(iVar2 + 0x118) + 0x14) == 0) {
      local_18 = *(undefined4 *)(iVar2 + 0xf4);
      local_14 = *(undefined4 *)(iVar2 + 0xf8);
    }
    else {
      iVar1 = *(int *)(iVar2 + 400);
      iVar3 = iVar1;
      if (iVar1 == 0) {
        iVar3 = iVar2;
      }
      if (iVar1 != 0 || iVar2 != 0) {
        do {
          iVar3 = *(int *)(iVar3 + 0x18c);
        } while (iVar3 != 0);
      }
      local_14 = __ftol();
      local_18 = __ftol();
    }
  }
  *param_2 = local_18;
  param_2[1] = local_14;
  return param_2;
}

