
uint __thiscall FUN_00578560(int *param_1,uint *param_2,int *param_3)

{
  uint *puVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  void *pvVar5;
  void *pvVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint local_10;
  uint local_c;
  int local_8;
  
  piVar2 = param_3;
  puVar1 = param_2;
  iVar4 = _rand();
  uVar9 = (int)(short)((ushort)((uint)iVar4 >> 8) & 0xff) % *(int *)(param_1[0xd] + 0x24);
  iVar4 = (int)((longlong)(ulonglong)(uint)(int)(short)((ushort)iVar4 & 0xff) %
               (longlong)*(int *)(param_1[0xd] + 0x28));
  *param_2 = uVar9;
  if ((int)uVar9 < *(int *)(param_1[0xd] + 0x24)) {
    do {
      *param_3 = iVar4;
      if (iVar4 < *(int *)(param_1[0xd] + 0x28)) {
        do {
          if (((*(int *)(param_1[*param_2 * 0x40 + *param_3 + 0x25] + 8) == 4) &&
              (cVar3 = (**(code **)(*param_1 + 0x84))(*param_2,*param_3), cVar3 == '\0')) &&
             (iVar8 = param_1[*param_2 * 0x40 + *param_3 + 0x25], *(char *)(iVar8 + 0x15) == '\0'))
          goto LAB_00578843;
          *param_3 = *param_3 + 1;
        } while (*param_3 < *(int *)(param_1[0xd] + 0x28));
      }
      *param_3 = 0;
      if (0 < iVar4) {
        do {
          if (((*(int *)(param_1[*param_2 * 0x40 + *param_3 + 0x25] + 8) == 4) &&
              (cVar3 = (**(code **)(*param_1 + 0x84))(*param_2,*param_3), cVar3 == '\0')) &&
             (iVar8 = param_1[*param_2 * 0x40 + *param_3 + 0x25], *(char *)(iVar8 + 0x15) == '\0'))
          goto LAB_00578843;
          *param_3 = *param_3 + 1;
        } while (*param_3 < iVar4);
      }
      *param_2 = *param_2 + 1;
    } while ((int)*param_2 < *(int *)(param_1[0xd] + 0x24));
  }
  *param_2 = 0;
  if (0 < (int)uVar9) {
    do {
      *param_3 = iVar4;
      if (iVar4 < *(int *)(param_1[0xd] + 0x28)) {
        do {
          if (((*(int *)(param_1[*param_2 * 0x40 + *param_3 + 0x25] + 8) == 4) &&
              (cVar3 = (**(code **)(*param_1 + 0x84))(*param_2,*param_3), cVar3 == '\0')) &&
             (iVar8 = param_1[*param_2 * 0x40 + *param_3 + 0x25], *(char *)(iVar8 + 0x15) == '\0'))
          goto LAB_00578843;
          *param_3 = *param_3 + 1;
        } while (*param_3 < *(int *)(param_1[0xd] + 0x28));
      }
      *param_3 = 0;
      if (0 < iVar4) {
        do {
          if (((*(int *)(param_1[*param_2 * 0x40 + *param_3 + 0x25] + 8) == 4) &&
              (cVar3 = (**(code **)(*param_1 + 0x84))(*param_2,*param_3), cVar3 == '\0')) &&
             (iVar8 = param_1[*param_2 * 0x40 + *param_3 + 0x25], *(char *)(iVar8 + 0x15) == '\0'))
          goto LAB_00578843;
          *param_3 = *param_3 + 1;
        } while (*param_3 < iVar4);
      }
      *param_2 = *param_2 + 1;
    } while ((int)*param_2 < (int)uVar9);
  }
  local_c = param_1[0x11] - param_1[0x1e];
  local_8 = param_1[0x12] - param_1[0x1d];
  if ((int)local_c < 0) {
    local_c = 0;
  }
  if (local_8 < 0) {
    local_8 = 0;
  }
  param_3 = (int *)(param_1[0x1e] + param_1[0x11]);
  param_2 = (uint *)(param_1[0x1d] + param_1[0x12]);
  iVar4 = *(int *)(param_1[0xd] + 0x24);
  if (iVar4 <= (int)param_3) {
    param_3 = (int *)(iVar4 - 1);
  }
  iVar4 = *(int *)(param_1[0xd] + 0x28);
  if (iVar4 <= (int)param_2) {
    param_2 = (uint *)(iVar4 + -1);
  }
  uVar9 = (((int)param_2 - local_8) + 1) * (((int)param_3 - local_c) + 1) * 4;
  pvVar5 = operator_new(uVar9);
  pvVar6 = operator_new(uVar9);
  local_10 = 0;
  *puVar1 = local_c;
  if ((int)local_c <= (int)param_3) {
    do {
      *piVar2 = local_8;
      if (local_8 <= (int)param_2) {
        piVar7 = (int *)((int)pvVar6 + local_10 * 4);
        do {
          iVar4 = param_1[*puVar1 * 0x40 + *piVar2 + 0x25];
          if (((*(int *)(iVar4 + 8) == 4) && (*(int *)(*(int *)(iVar4 + 0xc) + 0x2c) != 0x14)) &&
             (*(char *)(iVar4 + 0x15) == '\0')) {
            local_10 = local_10 + 1;
            *(uint *)(((int)pvVar5 - (int)pvVar6) + (int)piVar7) = *puVar1;
            *piVar7 = *piVar2;
            piVar7 = piVar7 + 1;
          }
          *piVar2 = *piVar2 + 1;
        } while (*piVar2 <= (int)param_2);
      }
      *puVar1 = *puVar1 + 1;
    } while ((int)*puVar1 <= (int)param_3);
    local_c = (uint)param_3;
    if (local_10 != 0) {
      uVar9 = FUN_005bc6fb();
      iVar4 = (uVar9 % local_10) * 4;
      *puVar1 = *(uint *)(iVar4 + (int)pvVar5);
      iVar8 = *(int *)(iVar4 + (int)pvVar6);
      *piVar2 = iVar8;
LAB_00578843:
      return CONCAT31((int3)((uint)iVar8 >> 8),1);
    }
  }
  return local_c & 0xffffff00;
}

