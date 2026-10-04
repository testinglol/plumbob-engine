
void __thiscall FUN_00418b8f(int param_1,int param_2)

{
  int iVar1;
  undefined2 extraout_var;
  
  iVar1 = param_2;
  FUN_00464a5e(param_1,1);
  param_2 = CONCAT22(extraout_var,*(undefined2 *)(param_1 + 4));
  FUN_00464973(&param_2,1);
  *(int *)(param_1 + 4) = (int)(short)param_2;
  FUN_00464973((undefined2 *)(param_1 + 10),1);
  if (*(int *)(iVar1 + 0xc) == 0) {
    *(undefined2 *)(param_1 + 8) = *(undefined2 *)(param_1 + 10);
  }
  FUN_00464d2c(param_1 + 0x10);
  return;
}

