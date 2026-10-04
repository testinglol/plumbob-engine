
undefined4 __fastcall FUN_004354e5(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_006e4a84 == 0) {
    cVar1 = FUN_0043538d();
    if ((cVar1 == '\0') || ((*(byte *)(param_1 + 0xa0) & 8) == 0)) {
      return 0;
    }
    iVar4 = (*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -2;
    if (-1 < iVar4) {
      iVar3 = (iVar4 * 9 + 9) * 4;
      if (iVar4 < 0) goto LAB_0043554a;
      do {
        if (iVar4 < (*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1) {
          iVar2 = *(int *)(param_1 + 0x130) + iVar3;
        }
        else {
LAB_0043554a:
          iVar2 = 0;
        }
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = FUN_00407498((int)*(short *)(iVar2 + 0x10));
        }
        if (iVar2 != 0) {
          return 0;
        }
        iVar4 = iVar4 + -1;
        iVar3 = iVar3 + -0x24;
      } while (-1 < iVar4);
    }
  }
  return 1;
}

