
int * __fastcall FUN_004a1c1e(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00401742(0xc);
  *param_1 = iVar1;
  *(int *)iVar1 = iVar1;
  *(int *)(*param_1 + 4) = *param_1;
  return param_1;
}

