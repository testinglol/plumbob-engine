
int * __fastcall FUN_006078bf(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00401742(0x28);
  *param_1 = iVar1;
  *(int *)iVar1 = iVar1;
  *(int *)(*param_1 + 4) = *param_1;
  return param_1;
}

