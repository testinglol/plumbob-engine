
void FUN_00469192(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    FUN_00469192(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(param_1 + 8);
    FUN_004693c9(param_1);
    param_1 = iVar1;
  }
  return;
}

