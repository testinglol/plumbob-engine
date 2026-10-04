
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049c15e(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  float10 extraout_ST0;
  
  iVar2 = 0;
  if (0 < param_3) {
    do {
      iVar1 = __ftol();
      if (iVar1 < 0x100) {
        if (extraout_ST0 < (float10)_DAT_0066657c) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = 0xff;
      }
      *(char *)(iVar2 + param_1) = (char)iVar1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_3);
  }
  return;
}

