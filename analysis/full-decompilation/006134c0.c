
void FUN_006134c0(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  double local_10;
  double local_8;
  
  local_10 = (double)*param_1;
  local_8 = (double)*param_2;
  FUN_00613520(&local_10,&local_8,param_3,param_4);
  iVar1 = __ftol();
  *param_1 = iVar1;
  iVar1 = __ftol();
  *param_2 = iVar1;
  return;
}

