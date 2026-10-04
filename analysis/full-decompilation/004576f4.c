
undefined4 __fastcall FUN_004576f4(int param_1)

{
  int iVar1;
  undefined3 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x60);
  uVar2 = (undefined3)((uint)iVar1 >> 8);
  if (*(short *)(iVar1 + 0x14) != 0) {
    return CONCAT31(uVar2,1);
  }
  return CONCAT31(uVar2,*(short *)(iVar1 + 8) != 0);
}

