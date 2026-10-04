
int __fastcall FUN_004753b0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1[3] - param_1[2] & 0xfffffffcU) != 0) {
    iVar1 = *(int *)(param_1[2] + -4 + (param_1[3] - param_1[2] >> 2) * 4);
    iVar2 = FUN_00475305();
    return iVar2 + (iVar1 - *param_1);
  }
  return 0;
}

