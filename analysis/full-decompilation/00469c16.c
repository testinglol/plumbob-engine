
uint __thiscall FUN_00469c16(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  tagRECT local_30;
  int *local_20;
  float local_1c;
  LONG *local_18;
  int local_14;
  uint local_10;
  int *local_c;
  int *local_8;
  
  piVar4 = param_2;
  iVar9 = *param_2;
  iVar8 = param_2[1];
  iVar1 = param_2[2];
  local_1c = 2.8026e-43;
  iVar2 = param_2[3];
  iVar3 = *(int *)(*param_1 + 0x28);
  if ((((*(char *)(*param_1 + 0x24) != '\0') &&
       ((piVar6 = (int *)(param_2[2] - *param_2), iVar3 < param_2[2] - *param_2 ||
        (piVar6 = (int *)(param_2[3] - param_2[1]), iVar3 < param_2[3] - param_2[1])))) ||
      ((local_14 = iVar3, local_8 = param_1, piVar5 = (int *)FUN_004697dd(param_2),
       piVar5 != (int *)0x0 && (piVar6 = piVar5, piVar5[4] == 0x7fffffff)))) ||
     (local_20 = piVar5, piVar6 = (int *)FUN_00469792(param_2), piVar6 != (int *)0xffffffff))
  goto LAB_00469eee;
  local_c = (int *)0x0;
  if (piVar5 != (int *)0x0) {
    local_c = piVar5;
  }
  if (*(char *)(*local_8 + 0x24) == '\0') {
    local_30.bottom = 0x20;
  }
  else {
    local_30.bottom = iVar3 / 4;
    if (local_30.bottom < 1) {
      local_30.bottom = 1;
    }
  }
  local_30.right = local_30.bottom;
  local_30.top = -local_30.bottom;
  local_30.left = -local_30.bottom;
  local_10 = 0;
  param_2 = (int *)0x0;
  do {
    while( true ) {
      iVar3 = (&local_30.left)[local_10];
      local_18 = &local_30.left + local_10;
      if (iVar3 == 0) break;
      piVar4[local_10] = piVar4[local_10] + iVar3;
      param_2 = (int *)0x0;
      piVar6 = piVar4 + local_10;
      if ((*(char *)(*local_8 + 0x24) == '\0') ||
         ((piVar4[2] - *piVar4 <= local_14 && (piVar4[3] - piVar4[1] <= local_14)))) {
        piVar5 = (int *)FUN_004697dd(piVar4);
        if (((piVar5 == local_20) &&
            (((piVar5 == (int *)0x0 || (piVar5[4] != 0x7fffffff)) &&
             (iVar7 = FUN_00469792(piVar4), iVar7 == -1)))) &&
           ((local_c == (int *)0x0 ||
            (((*local_c <= *piVar4 && (piVar4[2] <= local_c[2])) &&
             ((local_c[1] <= piVar4[1] && (piVar4[3] <= local_c[3])))))))) goto LAB_00469d7d;
        *piVar6 = *piVar6 - iVar3;
      }
      else {
        *piVar6 = *piVar6 - iVar3;
      }
      *local_18 = iVar3 / 2;
    }
    param_2 = (int *)((int)param_2 + 1);
LAB_00469d7d:
    local_1c = (float)((int)local_1c + -1);
    local_10 = local_10 + 1 & 3;
  } while ((local_1c != 0.0) && ((int)param_2 < 4));
  iVar3 = *local_8;
  if (*(char *)(iVar3 + 0x1d) != '\0') {
    local_30.left = *piVar4;
    local_1c = (float)(piVar4[2] - *piVar4);
    iVar7 = piVar4[3] - piVar4[1];
    local_30.top = piVar4[1];
    local_30.right = piVar4[2];
    local_30.bottom = piVar4[3];
    if (iVar7 < (int)local_1c) {
      local_10 = *(int *)(iVar3 + 0x20);
      local_20 = (int *)((float)(int)local_1c / (float)iVar7);
      local_1c = (float)(int)local_10;
      if (local_1c < (float)local_20) {
        local_30.right = local_30.left + local_10 * iVar7;
        OffsetRect(&local_30,((iVar1 + iVar9) / 2 - (int)(local_10 * iVar7) / 2) - local_30.left,0);
        if (local_30.left < *piVar4) {
          iVar8 = *piVar4 - local_30.left;
        }
        else {
          if (local_30.right <= piVar4[2]) goto LAB_00469ed2;
          iVar8 = piVar4[2] - local_30.right;
        }
        iVar9 = 0;
LAB_00469ecc:
        OffsetRect(&local_30,iVar8,iVar9);
      }
    }
    else {
      local_10 = *(int *)(iVar3 + 0x20);
      local_20 = (int *)(float)(int)local_10;
      if ((float)local_20 < (float)iVar7 / (float)(int)local_1c) {
        local_30.bottom = local_30.top + local_10 * (int)local_1c;
        OffsetRect(&local_30,0,
                   ((iVar2 + iVar8) / 2 - (int)(local_10 * (int)local_1c) / 2) - local_30.top);
        if (local_30.top < piVar4[1]) {
          iVar9 = piVar4[1] - local_30.top;
        }
        else {
          if (local_30.bottom <= piVar4[3]) goto LAB_00469ed2;
          iVar9 = piVar4[3] - local_30.bottom;
        }
        iVar8 = 0;
        goto LAB_00469ecc;
      }
    }
LAB_00469ed2:
    *piVar4 = local_30.left;
    piVar4[1] = local_30.top;
    piVar4[2] = local_30.right;
    piVar4[3] = local_30.bottom;
  }
  piVar6 = (int *)*piVar4;
  if (((int)piVar6 < piVar4[2]) && (piVar6 = (int *)piVar4[1], (int)piVar6 < piVar4[3])) {
    return CONCAT31((int3)((uint)piVar6 >> 8),1);
  }
LAB_00469eee:
  return (uint)piVar6 & 0xffffff00;
}

