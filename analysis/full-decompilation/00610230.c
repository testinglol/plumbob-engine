
undefined4 FUN_00610230(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  piVar1 = (int *)(param_1 + 0xc);
  iVar7 = *(int *)(*piVar1 + 4);
  uVar2 = *(undefined4 *)(param_2 + 0x10);
  puVar3 = *(undefined4 **)(param_1 + 0x14);
  uVar6 = 0;
  uVar5 = 0;
  if (puVar3 != (undefined4 *)0x0) {
    if (0 < *(int *)(param_1 + 0x10)) {
      uVar6 = *puVar3;
    }
    if (1 < *(int *)(param_1 + 0x10)) {
      uVar5 = puVar3[2];
    }
  }
  param_1 = *(int *)(param_2 + 0x14);
  if (0 < param_1) {
    iVar4 = *(int *)(*piVar1 + 8);
    do {
      FUN_006102b0(iVar7,param_3,uVar2,uVar6,uVar5);
      iVar7 = iVar7 + iVar4;
      param_3 = param_3 + param_4;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return 1;
}

