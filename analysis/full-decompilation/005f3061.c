
undefined1 __thiscall FUN_005f3061(int param_1,char *param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  size_t sVar4;
  DWORD DVar5;
  int local_c;
  undefined1 local_5;
  
  if (*(int *)(param_1 + 0x13c) == 2) {
    return 0;
  }
  if (param_2 != (char *)0x0) {
    bVar1 = *(int *)(param_1 + 0x140) < *(int *)(param_1 + 0x144);
    if (!bVar1) {
      iVar3 = _strcmp(param_2,&DAT_006c3d7c);
      if ((((iVar3 == 0) || (sVar4 = _strlen(param_2), 1 < sVar4)) ||
          ((*(int *)(param_1 + 0x16c) - *(int *)(param_1 + 0x168) & 0xfffffffcU) == 0)) ||
         (DVar5 = timeGetTime(), 2999 < DVar5 - *(int *)(param_1 + 0x180))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    if (*(int *)(param_1 + 0x138) <= (*(int *)(param_1 + 0xe8) - *(int *)(param_1 + 0xe4)) + -1) {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_005f4710();
    }
  }
  iVar3 = *(int *)(param_1 + 0x140);
  if (iVar3 == -1) {
    return 0;
  }
  if (iVar3 < *(int *)(param_1 + 0x144)) {
    FUN_00406466(iVar3,*(int *)(param_1 + 0x144) - iVar3);
    iVar3 = *(int *)(param_1 + 0x140);
    *(undefined1 *)(param_1 + 0x160) = 1;
    *(int *)(param_1 + 0x144) = iVar3;
    if (iVar3 < *(int *)(param_1 + 0xd4)) {
      *(int *)(param_1 + 0xd4) = iVar3;
    }
  }
  sVar4 = _strlen(param_2);
  local_5 = 1;
  if (*(int *)(param_1 + 0x138) <
      (int)((*(int *)(param_1 + 0xe8) - *(int *)(param_1 + 0xe4)) + -1 + sVar4)) {
    local_5 = 0;
    sVar4 = (*(int *)(param_1 + 0xe4) - *(int *)(param_1 + 0xe8)) + 1 + *(int *)(param_1 + 0x138);
    cVar2 = '\0';
    local_c = 0;
    if ((int)sVar4 < 1) goto LAB_005f31e2;
    do {
      if (cVar2 == '\x01') {
        cVar2 = '\x02';
      }
      else {
        cVar2 = (**(code **)(**(int **)(param_1 + 0x114) + 0x40))((int)param_2[local_c]);
        cVar2 = cVar2 != '\0';
      }
      local_c = local_c + 1;
    } while (local_c < (int)sVar4);
    local_5 = 0;
    if (cVar2 == '\x01') {
      sVar4 = sVar4 - 1;
    }
  }
  if (0 < (int)sVar4) {
    FUN_005bd71d(*(undefined4 *)(param_1 + 0xd4),param_2,sVar4);
    *(undefined1 *)(param_1 + 0x160) = 1;
  }
LAB_005f31e2:
  FUN_005f3a06(*(int *)(param_1 + 0xd4) + -1);
  FUN_005f2c6c(sVar4,0,0);
  if (*(int *)(param_1 + 0x48) != 0) {
    FUN_005da644(*(int *)(param_1 + 0x48),3,0x16,param_1,0);
  }
  return local_5;
}

