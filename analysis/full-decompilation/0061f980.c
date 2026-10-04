
undefined4 FUN_0061f980(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = *(int **)(param_1 + 0xc);
  iVar6 = piVar1[1];
  uVar2 = *(undefined4 *)(param_2 + 0x10);
  iVar5 = 0x100;
  if (((*(int **)(param_1 + 0x14) != (int *)0x0) && (0 < *(int *)(param_1 + 0x10))) &&
     (iVar5 = **(int **)(param_1 + 0x14), iVar5 < 2)) {
    iVar5 = 0x100;
  }
  param_1 = *(int *)(param_2 + 0x14);
  if (0 < param_1) {
    iVar3 = *piVar1;
    iVar4 = piVar1[2];
    do {
      FUN_0061fa10(param_3,iVar6,iVar3 + 0x28,uVar2,*(undefined4 *)(iVar3 + 0x18),iVar5);
      iVar6 = iVar6 + iVar4;
      param_3 = param_3 + param_4;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return 1;
}

