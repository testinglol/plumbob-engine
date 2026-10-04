
void FUN_005a5b18(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    FUN_005a5b18(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(param_1 + 8);
    FUN_005a5c34(param_1);
    param_1 = iVar1;
  }
  return;
}

