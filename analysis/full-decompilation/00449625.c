
void FUN_00449625(int param_1)

{
  int iVar1;
  undefined4 extraout_var;
  
  while (param_1 != 0) {
    FUN_00449625(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(param_1 + 8);
    FUN_0040189d(param_1,0x18,extraout_var);
    param_1 = iVar1;
  }
  return;
}

