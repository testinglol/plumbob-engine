
undefined4 __fastcall FUN_00574a7e(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x100) == *(int *)(param_1 + 0x108)) {
    return DAT_006ceae8;
  }
  FUN_00570d5f();
  uVar1 = FUN_005711e7();
  if ((uVar1 < 0x14) || (0x1d < uVar1)) {
    iVar2 = FUN_00570fb5(0,4);
    if ((0x12 < iVar2) || (iVar2 < 6)) {
      return DAT_006ceae0;
    }
  }
  return 0;
}

