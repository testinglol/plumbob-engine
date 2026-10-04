
void __fastcall FUN_004b503e(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2] - *param_1 >> 2;
  if (iVar1 != 0) {
    FUN_0040189d(*param_1,iVar1 << 2);
  }
  return;
}

