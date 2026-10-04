
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00625c10(int *param_1,int param_2,int param_3,undefined4 param_4,undefined1 *param_5,
                 double *param_6,code *param_7)

{
  double dVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_19c;
  int local_198;
  int local_194;
  int local_190;
  int local_18c;
  int local_188;
  int local_184;
  int local_180 [96];
  
  piVar3 = local_180;
  for (iVar2 = 0x60; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  iVar2 = 0;
  local_184 = param_2 - param_3;
  local_19c = 0;
  local_188 = 1;
  local_18c = param_3;
  local_194 = param_3;
  do {
    local_194 = local_194 + 1;
    local_18c = local_18c + -1;
    if (9 < local_188) break;
    iVar5 = local_184 + local_18c;
    local_190 = local_184 + local_194;
    if (iVar5 < local_190) {
      piVar3 = local_180 + iVar2 * 3 + 1;
      iVar4 = iVar5;
      do {
        if ((((-1 < iVar4) && (-1 < local_18c)) &&
            (iVar2 = *param_1, iVar4 < *(int *)(iVar2 + 0x10))) &&
           (local_18c < *(int *)(iVar2 + 0x14))) {
          iVar2 = *(int *)(iVar2 + 0x18) * iVar4;
          local_198 = *(int *)(((int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3) + param_1[2] * local_18c +
                              param_1[1]);
          iVar2 = (*param_7)(&local_198,param_4);
          if (iVar2 != 0) {
            piVar3[-1] = local_198;
            *piVar3 = iVar4;
            local_19c = local_19c + 1;
            piVar3[1] = local_18c;
            piVar3 = piVar3 + 3;
          }
        }
        iVar4 = iVar4 + 1;
        iVar2 = local_19c;
      } while (iVar4 < local_190);
    }
    if (iVar5 < local_190) {
      piVar3 = local_180 + iVar2 * 3 + 1;
      iVar4 = iVar5;
      do {
        if (((-1 < iVar4) && (-1 < local_194)) &&
           ((iVar2 = *param_1, iVar4 < *(int *)(iVar2 + 0x10) &&
            (local_194 < *(int *)(iVar2 + 0x14))))) {
          iVar2 = *(int *)(iVar2 + 0x18) * iVar4;
          local_198 = *(int *)(((int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3) + param_1[2] * local_194 +
                              param_1[1]);
          iVar2 = (*param_7)(&local_198,param_4);
          if (iVar2 != 0) {
            piVar3[-1] = local_198;
            *piVar3 = iVar4;
            local_19c = local_19c + 1;
            piVar3[1] = local_194;
            piVar3 = piVar3 + 3;
          }
        }
        iVar4 = iVar4 + 1;
        iVar2 = local_19c;
      } while (iVar4 < local_190);
    }
    if (local_18c < local_194) {
      piVar3 = local_180 + iVar2 * 3 + 1;
      iVar4 = local_18c;
      do {
        if (((-1 < iVar5) && (-1 < iVar4)) &&
           ((iVar2 = *param_1, iVar5 < *(int *)(iVar2 + 0x10) && (iVar4 < *(int *)(iVar2 + 0x14)))))
        {
          iVar2 = *(int *)(iVar2 + 0x18) * iVar5;
          local_198 = *(int *)(((int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3) + param_1[2] * iVar4 +
                              param_1[1]);
          iVar2 = (*param_7)(&local_198,param_4);
          if (iVar2 != 0) {
            piVar3[-1] = local_198;
            *piVar3 = iVar5;
            local_19c = local_19c + 1;
            piVar3[1] = iVar4;
            piVar3 = piVar3 + 3;
          }
        }
        iVar4 = iVar4 + 1;
        iVar2 = local_19c;
      } while (iVar4 < local_194);
    }
    if (local_18c < local_194) {
      piVar3 = local_180 + iVar2 * 3 + 1;
      iVar5 = local_18c;
      do {
        if ((((-1 < local_190) && (-1 < iVar5)) &&
            (iVar2 = *param_1, local_190 < *(int *)(iVar2 + 0x10))) &&
           (iVar5 < *(int *)(iVar2 + 0x14))) {
          iVar2 = *(int *)(iVar2 + 0x18) * local_190;
          local_198 = *(int *)(((int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3) + param_1[2] * iVar5 +
                              param_1[1]);
          iVar2 = (*param_7)(&local_198,param_4);
          if (iVar2 != 0) {
            piVar3[-1] = local_198;
            *piVar3 = local_190;
            local_19c = local_19c + 1;
            piVar3[1] = iVar5;
            piVar3 = piVar3 + 3;
          }
        }
        iVar5 = iVar5 + 1;
        iVar2 = local_19c;
      } while (iVar5 < local_194);
    }
    local_188 = local_188 + 1;
  } while (iVar2 == 0);
  iVar5 = 0;
  if (iVar2 < 1) {
    *(undefined4 *)param_6 = 0;
    *(undefined4 *)((int)param_6 + 4) = 0;
    param_5[3] = 0;
    param_5[2] = 0;
    param_5[1] = 0xff;
    *param_5 = 0;
    return;
  }
  iVar4 = 0;
  iVar2 = 0;
  local_188 = 0;
  dVar1 = _DAT_006669e8;
  if (0 < local_19c) {
    local_190 = local_19c;
    piVar3 = local_180 + 2;
    do {
      iVar2 = iVar2 + (uint)*(byte *)((int)piVar3 + -5);
      iVar5 = iVar5 + (uint)*(byte *)((int)piVar3 + -6);
      iVar4 = iVar4 + (uint)*(byte *)((int)piVar3 + -7);
      local_188 = local_188 + (uint)*(byte *)(piVar3 + -2);
      local_190 = local_190 + -1;
      dVar1 = SQRT((double)((param_3 - *piVar3) * (param_3 - *piVar3) +
                           (param_2 - piVar3[-1]) * (param_2 - piVar3[-1]))) + dVar1;
      piVar3 = piVar3 + 3;
    } while (local_190 != 0);
  }
  *param_6 = dVar1 / (double)local_19c;
  param_5[3] = (char)(iVar2 / local_19c);
  param_5[2] = (char)(iVar5 / local_19c);
  param_5[1] = (char)(iVar4 / local_19c);
  *param_5 = (char)(local_188 / local_19c);
  return;
}

