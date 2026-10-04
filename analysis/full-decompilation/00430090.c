
void FUN_00430090(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    FUN_00430090(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(param_1 + 8);
    FUN_00430263(param_1);
    param_1 = iVar1;
  }
  return;
}

