
undefined4 __thiscall FUN_00422e17(int param_1,int *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_c;
  int local_8;
  
  iVar4 = *param_2;
  iVar5 = param_2[1];
  param_2 = (int *)param_3;
  iVar2 = *(int *)(param_1 + 400);
  if (*(int *)(param_1 + 400) == 0) {
    iVar2 = param_1;
  }
  if (param_1 != iVar2) {
    piVar3 = (int *)FUN_00422055(*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x1a4));
    iVar5 = iVar5 - piVar3[1];
    iVar4 = iVar4 - *piVar3;
    param_2 = (int *)(param_3 - *(int *)(param_1 + 0x1a8));
  }
  if (*(int *)(param_1 + 400) != 0) {
    param_1 = *(int *)(param_1 + 400);
  }
  while( true ) {
    if (param_1 == 0) {
      return 1;
    }
    local_c = iVar4;
    local_8 = iVar5;
    piVar3 = (int *)FUN_00422055(*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x1a4));
    local_8 = local_8 + piVar3[1];
    local_c = local_c + *piVar3;
    cVar1 = FUN_004355c7(&local_c,*(int *)(param_1 + 0x1a8) + (int)param_2,0,0);
    if (cVar1 == '\0') break;
    param_1 = *(int *)(param_1 + 0x18c);
  }
  return 0;
}

