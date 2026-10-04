
int __fastcall FUN_005894e6(int param_1)

{
  int iVar1;
  
  iVar1 = (*(int *)(param_1 + 0xb04) - *(int *)(param_1 + 0xb00)) / 0xc;
  if (0 < iVar1) {
    return *(int *)(*(int *)(param_1 + 0xb00) + -0xc + iVar1 * 0xc);
  }
  return param_1;
}

