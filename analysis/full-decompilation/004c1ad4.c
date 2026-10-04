
void __thiscall FUN_004c1ad4(int param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_8;
  
  iVar2 = (int)param_2;
  local_8 = 0;
  if (*(int *)(param_1 + 4) != 1 && -1 < *(int *)(param_1 + 4) + -1) {
    piVar6 = (int *)((int)param_2 + 0xc);
    param_2 = param_4;
    do {
      iVar4 = piVar6[1];
      iVar1 = *piVar6;
      pvVar3 = operator_new(iVar4 - iVar1);
      *param_2 = pvVar3;
      if (pvVar3 == (void *)0x0) {
        return;
      }
      if (*(int *)(param_1 + 0x20) < 0x1f6) {
        iVar5 = piVar6[-1];
      }
      else {
        iVar5 = *piVar6;
      }
      FUN_005a92b0(pvVar3,iVar2 + iVar5,iVar4 - iVar1);
      param_2 = param_2 + 1;
      local_8 = local_8 + 1;
      piVar6 = piVar6 + 1;
    } while (local_8 < *(int *)(param_1 + 4) + -1);
  }
  iVar4 = *(int *)(param_1 + 4) + -1;
  if (*(int *)(param_1 + 0x20) < 0x1f6) {
    iVar4 = *(int *)(iVar2 + 8 + iVar4 * 4);
  }
  else {
    iVar4 = *(int *)(iVar2 + 0xc + iVar4 * 4);
  }
  pvVar3 = operator_new(param_3 - iVar4);
  param_4[*(int *)(param_1 + 4) + -1] = pvVar3;
  iVar1 = *(int *)(param_1 + 4);
  if (*(int *)(param_1 + 0x20) < 0x1f6) {
    iVar5 = *(int *)(iVar2 + 4 + iVar1 * 4);
  }
  else {
    iVar5 = *(int *)(iVar2 + 8 + iVar1 * 4);
  }
  FUN_005a92b0(param_4[iVar1 + -1],iVar5 + iVar2,param_3 - iVar4);
  return;
}

