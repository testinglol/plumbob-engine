
void FUN_006141b0(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = -param_1[1];
  param_1[1] = iVar1;
  return;
}

