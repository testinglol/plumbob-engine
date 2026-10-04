
undefined4 __fastcall FUN_00589fd2(int param_1)

{
  int iVar1;
  
  iVar1 = (*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24;
  if (iVar1 == 1 || iVar1 + -1 < 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x130) + 0x24;
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),*(short *)(iVar1 + 0x10) != 0);
}

