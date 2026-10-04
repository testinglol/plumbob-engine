
int FUN_00417fc5(int param_1)

{
  int iVar1;
  undefined **local_50 [3];
  undefined1 local_44 [64];
  
  if ((*(int *)(param_1 + 8) != -1) && (iVar1 = FUN_00418036(*(int *)(param_1 + 8)), iVar1 != 0)) {
    return iVar1;
  }
  if (*(int *)(param_1 + 0xc) != -1) {
    FUN_0046f824(local_44,0,0x40);
    local_50[0] = &PTR_FUN_0066651c;
    FUN_0046f847(0,0xffffffff);
    FUN_00416c4d(*(undefined4 *)(param_1 + 0xc),local_50);
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00420028(*(int *)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 0;
}

