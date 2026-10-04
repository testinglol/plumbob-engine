
void __thiscall FUN_00524f41(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2[1];
  iVar2 = *param_2;
  param_1[1] = param_1[1] + -iVar1;
  param_1[3] = param_1[3] + -iVar1;
  *param_1 = *param_1 + -iVar2;
  param_1[2] = param_1[2] + -iVar2;
  return;
}

