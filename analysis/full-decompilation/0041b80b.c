
void __thiscall FUN_0041b80b(undefined2 *param_1,int param_2)

{
  int iVar1;
  undefined2 extraout_var;
  
  iVar1 = param_2;
  FUN_00464a5e(param_1 + 6,1);
  param_2 = CONCAT22(extraout_var,*param_1);
  FUN_00464973(&param_2,1);
  *param_1 = (undefined2)param_2;
  FUN_00464973(param_1 + 2,1);
  if (*(int *)(iVar1 + 0xc) == 0) {
    param_1[1] = param_1[2];
  }
  FUN_00464d2c(param_1 + 8);
  return;
}

