
void FUN_00603117(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    FUN_00603117(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(param_1 + 8);
    FUN_0040189d(param_1,0x18);
    param_1 = iVar1;
  }
  return;
}

