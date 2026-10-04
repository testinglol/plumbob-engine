
int __thiscall FUN_005f22d5(int *param_1,int *param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int local_8;
  
  piVar2 = param_2;
  if (param_4[1] < param_1[4]) {
    return -3;
  }
  if (param_1[2] + param_1[4] <= param_4[1]) {
    return -1;
  }
  if (((*param_4 < param_1[3]) || ((param_1[6] - param_1[5] & 0xfffffffcU) == 0)) ||
     (*param_4 < *(int *)param_1[5] / 2 + param_1[3])) {
    return *param_1;
  }
  cVar3 = (**(code **)(*param_2 + 0x48))();
  if (cVar3 == '\0') {
    iVar4 = 1;
    if (4 < (int)(param_1[6] - param_1[5] & 0xfffffffcU)) {
      piVar2 = (int *)param_1[5];
      do {
        if (*param_4 <= (*piVar2 + piVar2[1]) / 2 + param_1[3]) break;
        iVar4 = iVar4 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar4 < param_1[6] - param_1[5] >> 2);
      if (iVar4 < 1) goto LAB_005f242f;
    }
    if ((iVar4 == param_1[1]) &&
       ((*(char *)((int)param_1 + 0x21) != '\0' || ((char)param_1[8] != '\0')))) {
      iVar4 = iVar4 + -1;
    }
  }
  else {
    iVar4 = (**(code **)(*param_2 + 0x44))(*param_1 + param_3,0xffffffff);
    param_2 = (int *)*(int *)(param_1[5] + -4 + iVar4 * 4);
    local_8 = iVar4;
    for (; iVar4 < param_1[6] - param_1[5] >> 2; iVar4 = iVar4 + local_8) {
      local_8 = (**(code **)(*piVar2 + 0x44))(*param_1 + iVar4 + param_3,0xffffffff);
      iVar1 = *(int *)(param_1[5] + (iVar4 - local_8) * 4);
      if (*param_4 <= ((int)param_2 + iVar1) / 2 + param_1[3]) break;
      param_2 = (int *)iVar1;
    }
    if (((0 < iVar4) && (iVar4 == param_1[1])) &&
       ((*(char *)((int)param_1 + 0x21) != '\0' || ((char)param_1[8] != '\0')))) {
      iVar4 = iVar4 - local_8;
    }
  }
LAB_005f242f:
  return *param_1 + iVar4;
}

