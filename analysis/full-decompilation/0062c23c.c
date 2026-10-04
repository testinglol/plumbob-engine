
undefined4 FUN_0062c23c(char *param_1,uint *param_2,uint *param_3,uint *param_4,uint *param_5)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_10;
  uint local_c;
  
  iVar5 = 0;
  local_10 = 1;
  local_c = 0x80000000;
  if (*(char **)(param_1 + 0x20) == (char *)0x0) {
    local_10 = 2;
  }
  else if (*(int *)(param_1 + 0x24) == 0) {
    *param_3 = 0;
    *param_2 = 0;
    local_10 = 0;
  }
  else {
    cVar1 = **(char **)(param_1 + 0x20);
    while (cVar1 != '\0') {
      iVar4 = FUN_0062ccc1();
      iVar3 = *(int *)(param_1 + 0x20);
      while (bVar2 = *(byte *)(iVar3 + iVar5 * 2 + iVar4), 0xf9 < bVar2) {
        iVar5 = iVar5 + (uint)bVar2;
      }
      iVar5 = iVar5 + (uint)*(byte *)(iVar3 + iVar5 * 2 + iVar4);
      local_c = local_c >> 1;
      if ((local_c == 0) && (DAT_0067d214 <= iVar5)) goto LAB_0062c2ef;
      cVar1 = *(char *)(iVar3 + iVar5 * 2);
    }
    *param_2 = (uint)(*(byte *)(iVar5 * 2 + 1 + *(int *)(param_1 + 0x20)) >> 4);
    local_10 = 0;
    *param_3 = *(byte *)(iVar5 * 2 + 1 + *(int *)(param_1 + 0x20)) & 0xf;
LAB_0062c2ef:
    if ((*param_1 == '3') && ((param_1[1] == '2' || (param_1[1] == '3')))) {
      *param_4 = (int)*param_3 >> 3 & 1;
      *param_5 = (int)*param_3 >> 2 & 1;
      *param_2 = (int)*param_3 >> 1 & 1;
      *param_3 = *param_3 & 1;
      if ((*param_4 != 0) && (iVar5 = FUN_0062ccc1(), iVar5 != 0)) {
        *param_4 = -*param_4;
      }
      if ((*param_5 != 0) && (iVar5 = FUN_0062ccc1(), iVar5 != 0)) {
        *param_5 = -*param_5;
      }
      if ((*param_2 != 0) && (iVar5 = FUN_0062ccc1(), iVar5 != 0)) {
        *param_2 = -*param_2;
      }
    }
    else {
      if ((*(int *)(param_1 + 0xc) != 0) && (*(int *)(param_1 + 4) - 1U == *param_2)) {
        iVar5 = FUN_0062cc47(*(int *)(param_1 + 0xc));
        *param_2 = *param_2 + iVar5;
      }
      if ((*param_2 != 0) && (iVar5 = FUN_0062ccc1(), iVar5 != 0)) {
        *param_2 = -*param_2;
      }
      if ((*(int *)(param_1 + 0xc) != 0) && (*(int *)(param_1 + 8) - 1U == *param_3)) {
        iVar5 = FUN_0062cc47(*(int *)(param_1 + 0xc));
        *param_3 = *param_3 + iVar5;
      }
    }
    if ((*param_3 != 0) && (iVar5 = FUN_0062ccc1(), iVar5 != 0)) {
      *param_3 = -*param_3;
    }
  }
  return local_10;
}

