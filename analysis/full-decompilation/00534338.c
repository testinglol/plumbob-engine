
void FUN_00534338(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    FUN_00534338(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(param_1 + 8);
    FUN_0053486d(param_1);
    param_1 = iVar1;
  }
  return;
}

