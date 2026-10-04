
void FUN_006151c0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = 0;
  DAT_006ff840 = 0;
  if (0 < *(int *)(iVar1 + 0x458)) {
    do {
      FUN_00615230(param_1,*(undefined4 *)(iVar1 + 0x87c + iVar2 * 8),
                   *(undefined4 *)(iVar1 + 0x880 + iVar2 * 8),DAT_006da270);
      iVar1 = *param_1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(iVar1 + 0x458));
  }
  FUN_00615600(param_1,0,0,param_2);
  FUN_00615600(param_1,*(int *)(*param_1 + 0x10) + -1,0,param_2);
  return;
}

