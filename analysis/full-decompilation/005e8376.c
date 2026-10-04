
void FUN_005e8376(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    FUN_005e8376(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(param_1 + 8);
    FUN_0040189d(param_1,0x1c);
    param_1 = iVar1;
  }
  return;
}

