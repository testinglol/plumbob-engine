
undefined4 FUN_0059e426(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = param_1;
  param_1 = 0;
  uVar1 = *(undefined4 *)(iVar3 + 0x10);
  iVar5 = *(int *)(iVar3 + 0x20) - *(int *)(iVar3 + 0x1c) >> 2;
  if (0 < iVar5) {
    do {
      iVar2 = *(int *)(*(int *)(iVar3 + 0x1c) + param_1 * 4);
      if (*(int *)(iVar2 + 0x1c) == 0) {
        iVar4 = FUN_0059e1b5(uVar1,iVar2 + 0x10);
        if (iVar4 != 0) {
          FUN_00473577(iVar2);
        }
        FUN_00594d67(iVar4);
      }
      param_1 = param_1 + 1;
    } while (param_1 < iVar5);
  }
  return 0;
}

