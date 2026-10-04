
void FUN_004dff2c(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    FUN_004dff2c(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(param_1 + 8);
    FUN_004dff5a(param_1);
    param_1 = iVar1;
  }
  return;
}

