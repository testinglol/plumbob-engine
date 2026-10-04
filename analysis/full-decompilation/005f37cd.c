
void __fastcall FUN_005f37cd(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  iVar6 = param_1[0x3f] + param_1[0x37];
  iVar5 = param_1[0x40] + param_1[0x38];
  iVar1 = (**(code **)(*(int *)param_1[0x45] + 0x58))();
  if ((param_1[0x4d] == 1) && ((param_1[0x3d] - param_1[0x3c] & 0xfffffffcU) != 0)) {
    if (iVar6 < param_1[0x46]) {
      local_10 = iVar6 - param_1[0x46];
      local_8 = (param_1[0x21] - param_1[0x1f]) / -2;
      piVar2 = &local_8;
      if (iVar6 - param_1[0x46] <= local_8) {
        piVar2 = &local_10;
      }
      local_8 = *piVar2;
      if (((param_1[0x3d] - param_1[0x3c] >> 2 != 0) && (iVar6 = *(int *)param_1[0x3c], iVar6 != 0))
         && ((*(int *)(iVar6 + 0x18) - *(int *)(iVar6 + 0x14) & 0xfffffffcU) != 0)) {
        iVar4 = param_1[0x35];
        if (iVar4 < 0) {
          iVar4 = 0;
        }
        else if (*(int *)(iVar6 + 0x18) - *(int *)(iVar6 + 0x14) >> 2 <= iVar4) {
          iVar4 = (*(int *)(iVar6 + 0x18) - *(int *)(iVar6 + 0x14) >> 2) + -1;
        }
        iVar6 = *(int *)(*(int *)(iVar6 + 0x14) + iVar4 * 4) + *(int *)(iVar6 + 0xc);
        if (iVar6 < param_1[0x48] - param_1[0x46]) {
          local_10 = -iVar6;
          piVar3 = &local_10;
          if (*piVar2 <= local_10) {
            piVar3 = &local_8;
          }
          local_8 = *piVar3;
        }
      }
    }
    else if (param_1[0x48] <= iVar6) {
      local_8 = (iVar6 - param_1[0x48]) + 1;
    }
  }
  if (iVar5 < param_1[0x47]) {
    local_c = iVar5 - param_1[0x47];
  }
  else if (param_1[0x49] <= iVar5 + iVar1) {
    local_c = (iVar5 - param_1[0x49]) + 1 + iVar1;
  }
  if (local_8 != 0) {
    param_1[0x3f] = param_1[0x3f] - local_8;
    if (0 < param_1[0x3f]) {
      param_1[0x3f] = 0;
    }
    (**(code **)(*param_1 + 0x168))();
  }
  if (local_c != 0) {
    iVar1 = param_1[0x4b];
    iVar5 = param_1[0x36];
    iVar6 = iVar5;
    if ((iVar1 <= iVar5) && (iVar6 = iVar1, param_1[0x4c] + iVar1 <= iVar5)) {
      iVar6 = (iVar5 - param_1[0x4c]) + 1;
    }
    FUN_005f398c(iVar6);
  }
  if ((char)param_1[0x55] != '\0') {
    *(undefined1 *)((int)param_1 + 0x15d) = 1;
  }
  return;
}

