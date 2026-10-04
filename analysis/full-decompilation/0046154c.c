
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0046154c(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1[2] != 1 && -1 < param_1[2] + -1) {
    do {
      *(float *)(param_1[1] + iVar1 * 4) =
           _DAT_00666748 / (*(float *)(*param_1 + 8 + iVar1 * 8) - *(float *)(*param_1 + iVar1 * 8))
      ;
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1[2] + -1);
  }
  return;
}

