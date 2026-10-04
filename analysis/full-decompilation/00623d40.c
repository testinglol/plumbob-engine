
void FUN_00623d40(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  piVar5 = param_1;
  iVar1 = *(int *)(*param_1 + 0x10);
  iVar2 = *(int *)(*param_1 + 0x14);
  param_1 = (int *)0x0;
  if (0 < iVar2) {
    iVar3 = piVar5[2];
    iVar4 = piVar5[1];
    iVar7 = iVar4;
    do {
      if (0 < iVar1) {
        iVar8 = (((*(int *)(param_2 + 8) - iVar3) * (int)param_1 + *(int *)(param_2 + 4)) - iVar4) +
                iVar7;
        iVar6 = iVar1;
        iVar9 = iVar7;
        do {
          FUN_00623dd0(iVar9,iVar8);
          iVar9 = iVar9 + 4;
          iVar8 = iVar8 + 4;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      param_1 = (int *)((int)param_1 + 1);
      iVar7 = iVar7 + iVar3;
    } while ((int)param_1 < iVar2);
  }
  return;
}

