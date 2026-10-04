
void FUN_00615230(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar1 = *(int *)(*param_1 + 0x10);
  iVar2 = *(int *)(*param_1 + 0x14);
  iVar8 = -param_4;
  if (-param_4 == param_4 || iVar8 < param_4) {
    iVar3 = param_1[2];
    iVar6 = iVar8 + param_3;
    param_3 = iVar3 * iVar6 + param_1[1] + param_2 * 4;
    iVar4 = param_4 * 2 + 1;
    do {
      param_1 = (int *)param_3;
      if (-param_4 == param_4 || iVar8 < param_4) {
        iVar5 = iVar8 + param_2;
        iVar7 = param_4 * 2 + 1;
        do {
          if ((((-1 < iVar5) && (iVar5 < iVar1)) && (-1 < iVar6)) && (iVar6 < iVar2)) {
            FUN_00615300(param_1);
          }
          param_1 = (int *)((int)param_1 + 4);
          iVar5 = iVar5 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      param_3 = param_3 + iVar3;
      iVar6 = iVar6 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}

