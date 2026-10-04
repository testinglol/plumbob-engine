
void FUN_005e6d21(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    FUN_005e6d21(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(param_1 + 8);
    FUN_005e7036(param_1);
    param_1 = iVar1;
  }
  return;
}

