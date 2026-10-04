
void FUN_00627f40(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_10;
  int local_c;
  int local_8;
  
  piVar2 = param_2;
  iVar1 = *param_2;
  local_10 = 0;
  local_c = 0;
  iVar4 = FUN_00628080(param_2,0,0);
  iVar7 = 1;
  iVar3 = local_c;
  if (1 < *(int *)(iVar1 + 0x10) + -1) {
    do {
      iVar5 = FUN_00628080(param_2,iVar7,0);
      iVar3 = iVar7;
      if (iVar4 != iVar5) break;
      iVar7 = iVar7 + 1;
      iVar3 = local_c;
    } while (iVar7 < *(int *)(iVar1 + 0x10) + -1);
  }
  local_c = iVar3;
  local_8 = 0;
  iVar5 = *(int *)(iVar1 + 0x14) + -1;
  iVar8 = 1;
  iVar3 = local_c;
  iVar7 = local_8;
  if (1 < *(int *)(iVar1 + 0x10) + -1) {
    do {
      iVar6 = FUN_00628080(param_2,iVar8,iVar5);
      iVar3 = iVar8;
      iVar7 = iVar5;
      if (iVar4 != iVar6) break;
      iVar8 = iVar8 + 1;
      iVar3 = local_c;
      iVar7 = local_8;
    } while (iVar8 < *(int *)(iVar1 + 0x10) + -1);
  }
  local_8 = iVar7;
  local_c = iVar3;
  iVar7 = 0;
  iVar3 = local_10;
  if (0 < *(int *)(iVar1 + 0x14)) {
    do {
      iVar5 = FUN_00628080(param_2,0,iVar7);
      iVar3 = iVar7;
      if (iVar4 != iVar5) break;
      iVar7 = iVar7 + 1;
      iVar3 = local_10;
    } while (iVar7 < *(int *)(iVar1 + 0x14));
  }
  local_10 = iVar3;
  param_2 = (int *)0x0;
  iVar5 = *(int *)(iVar1 + 0x10) + -1;
  iVar8 = 0;
  iVar3 = (int)param_2;
  iVar7 = local_10;
  if (0 < *(int *)(iVar1 + 0x14)) {
    do {
      iVar6 = FUN_00628080(piVar2,iVar5,iVar8);
      iVar3 = iVar5;
      iVar7 = iVar8;
      if (iVar4 != iVar6) break;
      iVar8 = iVar8 + 1;
      iVar3 = (int)param_2;
      iVar7 = local_10;
    } while (iVar8 < *(int *)(iVar1 + 0x14));
  }
  local_10 = iVar7;
  param_2 = (int *)iVar3;
  *param_1 = (int)param_2;
  param_1[1] = local_10;
  param_1[2] = local_c;
  param_1[3] = local_8;
  return;
}

