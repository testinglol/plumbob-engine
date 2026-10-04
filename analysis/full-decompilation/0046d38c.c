
void FUN_0046d38c(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int local_8;
  
  local_8 = 1;
  FUN_00464a5e(&local_8,1);
  iVar2 = 8;
  puVar1 = param_1;
  if (local_8 == 0) {
    iVar2 = 7;
  }
  for (; iVar2 != 0; iVar2 = iVar2 + -1) {
    param_1 = (undefined4 *)*puVar1;
    FUN_00464a4e(&param_1,1);
    *puVar1 = param_1;
    puVar1 = puVar1 + 1;
  }
  return;
}

