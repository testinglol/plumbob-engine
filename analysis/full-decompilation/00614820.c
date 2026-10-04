
undefined4 FUN_00614820(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  
  iVar1 = *(int *)(*param_2 + 0x10);
  iVar6 = *(int *)(*param_2 + 0x14);
  if (iVar6 < 1) {
    return 1;
  }
  iVar2 = param_2[2];
  puVar5 = (undefined1 *)param_2[1];
  iVar7 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(param_1 + 8);
  param_1 = iVar6;
  do {
    iVar6 = iVar1;
    puVar8 = puVar5;
    iVar9 = iVar7;
    if (0 < iVar1) {
      do {
        uVar4 = FUN_006148c0(iVar9,param_3);
        *puVar8 = uVar4;
        puVar8 = puVar8 + 1;
        iVar9 = iVar9 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    puVar5 = puVar5 + iVar2;
    iVar7 = iVar7 + iVar3;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  return 1;
}

