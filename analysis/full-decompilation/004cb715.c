
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004cb715(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4) & 0xfffffffcU) == 0) {
    return 0;
  }
  uVar1 = __ftol(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2,0);
  return uVar1;
}

