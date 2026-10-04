
undefined1
FUN_005e2e1b(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6,
            int *param_7,int *param_8)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  uint local_c;
  
  piVar3 = param_4;
  piVar2 = param_3;
  local_c = 0;
  if (*param_1 < (int)param_5) {
    local_c = 4;
  }
  if ((int)param_7 < *param_1) {
    local_c = local_c + 8;
  }
  if (*param_2 < (int)param_6) {
    local_c = local_c + 1;
  }
  if ((int)param_8 < *param_2) {
    local_c = local_c + 2;
  }
  iVar1 = *param_3;
  param_3 = (int *)0x0;
  if (iVar1 < (int)param_5) {
    param_3 = (int *)0x4;
  }
  if ((int)param_7 < iVar1) {
    param_3 = (int *)((int)param_3 + 8);
  }
  if (*param_4 < (int)param_6) {
    param_3 = (int *)((int)param_3 + 1);
  }
  piVar4 = param_1;
  piVar5 = param_1;
  if ((int)param_8 < *param_4) {
    param_3 = (int *)((int)param_3 + 2);
  }
  while( true ) {
    if (param_3 == (int *)0x0 && local_c == 0) {
      return 1;
    }
    if (((uint)param_3 & local_c) != 0) break;
    uVar6 = local_c;
    if (local_c == 0) {
      uVar6 = (uint)param_3;
    }
    if ((uVar6 & 1) == 0) {
      if ((uVar6 & 2) == 0) {
        if ((uVar6 & 8) == 0) {
          if ((uVar6 & 4) != 0) {
            piVar4 = (int *)((((int)param_5 - *param_1) * (*piVar3 - *param_2)) /
                             (*piVar2 - *param_1) + *param_2);
            piVar5 = param_5;
          }
        }
        else {
          piVar4 = (int *)((((int)param_7 - *param_1) * (*piVar3 - *param_2)) / (*piVar2 - *param_1)
                          + *param_2);
          piVar5 = param_7;
        }
      }
      else {
        piVar4 = param_8;
        piVar5 = (int *)((((int)param_8 - *param_2) * (*piVar2 - *param_1)) / (*piVar3 - *param_2) +
                        *param_1);
      }
    }
    else {
      piVar4 = param_6;
      piVar5 = (int *)((((int)param_6 - *param_2) * (*piVar2 - *param_1)) / (*piVar3 - *param_2) +
                      *param_1);
    }
    if (uVar6 == local_c) {
      param_4 = (int *)0x0;
      *param_1 = (int)piVar5;
      *param_2 = (int)piVar4;
      if (*param_1 < (int)param_5) {
        param_4 = (int *)0x4;
      }
      if ((int)param_7 < *param_1) {
        param_4 = (int *)((int)param_4 + 8);
      }
      if ((int)piVar4 < (int)param_6) {
        param_4 = (int *)((int)param_4 + 1);
      }
      if ((int)param_8 < (int)piVar4) {
        param_4 = (int *)((int)param_4 + 2);
      }
      local_c = (uint)param_4;
    }
    else {
      param_4 = (int *)0x0;
      *piVar2 = (int)piVar5;
      *piVar3 = (int)piVar4;
      if (*piVar2 < (int)param_5) {
        param_4 = (int *)0x4;
      }
      if ((int)param_7 < *piVar2) {
        param_4 = (int *)((int)param_4 + 8);
      }
      if ((int)piVar4 < (int)param_6) {
        param_4 = (int *)((int)param_4 + 1);
      }
      if ((int)param_8 < (int)piVar4) {
        param_4 = (int *)((int)param_4 + 2);
      }
      param_3 = param_4;
    }
  }
  return 0;
}

