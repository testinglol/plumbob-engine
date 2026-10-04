
int __thiscall FUN_0060b5cc(int *param_1,byte *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte *local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  local_10 = 0;
  bVar3 = false;
  local_14 = param_2;
  if (param_3 < 1) {
    return 0;
  }
  piVar5 = (int *)((uint)*param_2 * 0x1c + param_1[4]);
  iVar8 = piVar5[2] - *piVar5;
  iVar6 = local_10;
  if (iVar8 <= param_4) {
    do {
      local_10 = iVar6;
      iVar6 = local_10 + 1;
      if (param_3 <= iVar6) {
        return iVar6;
      }
      cVar4 = (**(code **)(*param_1 + 0x34))((int)(char)*local_14);
      if (cVar4 != '\0') {
        bVar3 = true;
        local_c = iVar6;
        break;
      }
      cVar4 = (**(code **)(*param_1 + 0x30))((int)(char)*local_14);
      if ((cVar4 != '\0') && (iVar8 <= param_4)) {
        local_c = iVar6;
      }
      piVar5 = (int *)((uint)*local_14 * 0x1c + param_1[4]);
      iVar1 = *piVar5;
      iVar2 = piVar5[2];
      iVar7 = (**(code **)(*param_1 + 0x5c))((int)(char)*local_14);
      iVar8 = (iVar1 - iVar2) + iVar8 + iVar7;
      if (local_14 < param_2 + param_3) {
        local_14 = local_14 + 1;
        piVar5 = (int *)((uint)*local_14 * 0x1c + param_1[4]);
        iVar8 = (piVar5[2] - *piVar5) + iVar8;
      }
    } while (iVar8 <= param_4);
    if (local_c != 0) goto LAB_0060b6fc;
    if (1 < iVar6) {
      local_c = local_10;
      goto LAB_0060b6fc;
    }
  }
  if (0 < param_3) {
    do {
      if (((param_2[local_c] == 0) ||
          (cVar4 = (**(code **)(*param_1 + 0x34))((int)(char)param_2[local_c]), cVar4 != '\0')) ||
         (cVar4 = (**(code **)(*param_1 + 0x38))((int)(char)param_2[local_c]), cVar4 != '\0'))
      break;
      local_c = local_c + 1;
    } while (local_c < param_3);
  }
LAB_0060b6fc:
  if (!bVar3) {
    while ((local_c < param_3 &&
           (cVar4 = (**(code **)(*param_1 + 0x38))((int)(char)param_2[local_c]), cVar4 != '\0'))) {
      local_c = local_c + 1;
    }
  }
  if (local_c == 0) {
    local_c = 1;
  }
  return local_c;
}

