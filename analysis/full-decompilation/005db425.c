
void __fastcall FUN_005db425(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2] - *param_1 >> 4;
  if (iVar1 != 0) {
    FUN_0040189d(*param_1,iVar1 << 4);
  }
  return;
}

