
undefined4 __thiscall FUN_004d586b(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_1[0x35] == 0) {
    uVar2 = FUN_005dd854(param_2,param_3,param_4);
  }
  else {
    if (param_1[0x35] == 1) {
      iVar5 = param_1[0x39] - (param_2 + param_1[0x1f]);
      param_1[0x39] = param_2 + param_1[0x1f];
      iVar3 = param_1[0x3a] - (param_3 + param_1[0x20]);
      param_1[0x3a] = param_3 + param_1[0x20];
      if ((iVar5 != 0) || (iVar3 != 0)) {
        local_10 = param_1[0x20];
        iVar1 = param_1[0x1f];
        local_c = param_1[0x21];
        local_8 = param_1[0x22];
        if (*(char *)((int)param_1 + 0xed) != '\0') {
          iVar1 = iVar1 - iVar5;
        }
        if ((char)param_1[0x3b] != '\0') {
          local_10 = local_10 - iVar3;
        }
        if (*(char *)((int)param_1 + 0xee) != '\0') {
          local_c = local_c - iVar5;
        }
        if (*(char *)((int)param_1 + 0xef) != '\0') {
          local_8 = local_8 - iVar3;
        }
        iVar5 = param_1[0x36];
        iVar3 = iVar5 * 3 + iVar1;
        iVar4 = local_c;
        if ((local_c <= iVar3) && (iVar4 = iVar3, *(char *)((int)param_1 + 0xed) != '\0')) {
          iVar1 = local_c + iVar5 * -3;
          iVar4 = local_c;
        }
        local_c = iVar4;
        iVar3 = iVar5 * 3 + local_10;
        iVar4 = local_8;
        if ((local_8 <= iVar3) && (iVar4 = iVar3, (char)param_1[0x3b] != '\0')) {
          local_10 = local_8 + iVar5 * -3;
          iVar4 = local_8;
        }
        local_8 = iVar4;
        iVar6 = local_c - iVar1;
        iVar4 = *(int *)(param_1[0x10] + 0x84) - *(int *)(param_1[0x10] + 0x7c);
        iVar3 = iVar5 * 2;
        if (local_c + iVar5 * -2 < 0) {
          iVar1 = iVar3 - iVar6;
          local_c = iVar3;
        }
        else if (iVar4 <= iVar3 + iVar1) {
          iVar1 = iVar4 + iVar5 * -2;
          local_c = iVar6 + iVar1;
        }
        if (local_8 + iVar5 * -2 < 0) {
          local_10 = iVar3 - iVar6;
          local_8 = iVar3;
        }
        else if (iVar4 <= local_10 + iVar3) {
          local_10 = iVar4 + iVar5 * -2;
          local_8 = iVar6 + local_10;
        }
        (**(code **)(*param_1 + 0x60))(iVar1,local_10,local_c,local_8);
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}

