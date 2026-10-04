
undefined4 FUN_00620550(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar1 = (*(int **)(param_1 + 0xc))[1];
  iVar5 = **(int **)(param_1 + 0xc);
  uVar2 = *(undefined4 *)(iVar5 + 0x10);
  iVar3 = *(int *)(iVar5 + 0x14);
  uVar4 = *(undefined4 *)(iVar5 + 0x18);
  iVar5 = 1;
  if ((*(int **)(param_1 + 0x14) != (int *)0x0) && (0 < *(int *)(param_1 + 0x10))) {
    iVar5 = **(int **)(param_1 + 0x14);
  }
  if (iVar5 == 1) {
    FUN_00620630(iVar1,param_3,uVar2,iVar3,param_4,uVar4);
  }
  else {
    if (iVar5 == 2) {
      FUN_00620720(iVar1,param_3,iVar3,param_4);
      return 1;
    }
    if (iVar5 == 3) {
      iVar5 = FUN_005a9320(iVar3 * param_4);
      if (iVar5 != 0) {
        FUN_00620630(iVar1,iVar5,uVar2,iVar3,param_4,uVar4);
        FUN_00620720(iVar5,param_3,iVar3,param_4);
        FUN_005a9340(iVar5);
        return 1;
      }
      return 0;
    }
  }
  return 1;
}

