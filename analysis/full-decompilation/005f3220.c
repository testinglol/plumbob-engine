
bool __thiscall FUN_005f3220(int param_1,char *param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  size_t sVar4;
  DWORD DVar5;
  int iVar6;
  int local_10;
  size_t local_c;
  bool local_5;
  
  if ((param_2 != (char *)0x0) &&
     ((((*(int *)(param_1 + 0x140) < *(int *)(param_1 + 0x144) ||
        (iVar3 = _strcmp(param_2,&DAT_006c3d7c), iVar3 == 0)) ||
       (sVar4 = _strlen(param_2), 1 < sVar4)) ||
      (((*(int *)(param_1 + 0x16c) - *(int *)(param_1 + 0x168) & 0xfffffffcU) == 0 ||
       (DVar5 = timeGetTime(), 2999 < DVar5 - *(int *)(param_1 + 0x180))))))) {
    FUN_005f4710();
  }
  iVar3 = *(int *)(param_1 + 0x140);
  if (iVar3 < *(int *)(param_1 + 0x144)) {
    FUN_00406466(iVar3,*(int *)(param_1 + 0x144) - iVar3);
    *(undefined1 *)(param_1 + 0x160) = 1;
    if (*(int *)(param_1 + 0x140) < *(int *)(param_1 + 0xd4)) {
      *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0x140);
    }
  }
  uVar1 = *(undefined4 *)(param_1 + 0xd4);
  sVar4 = _strlen(param_2);
  if (sVar4 == 0) {
    FUN_005f3a06(uVar1);
    FUN_005f2c6c(0,0,0);
    local_5 = true;
  }
  else {
    if ((int)(*(int *)(param_1 + 0xd4) + sVar4) <=
        (*(int *)(param_1 + 0xe8) - *(int *)(param_1 + 0xe4)) + -1) {
      cVar2 = (**(code **)(**(int **)(param_1 + 0x114) + 0x48))();
      local_c = sVar4;
      if ((cVar2 != '\0') && (local_10 = 0, 0 < (int)sVar4)) {
        do {
          iVar3 = **(int **)(param_1 + 0x114);
          iVar6 = FUN_004096c2(0xffffffff);
          iVar3 = (**(code **)(iVar3 + 0x44))(iVar6 + *(int *)(param_1 + 0xd4) + local_10);
          if (1 < iVar3) {
            local_10 = local_10 + -1 + iVar3;
            local_c = (local_c - 1) + iVar3;
          }
          local_10 = local_10 + 1;
        } while (local_10 < (int)local_c);
      }
      FUN_00406466(*(undefined4 *)(param_1 + 0xd4),local_c);
      *(undefined1 *)(param_1 + 0x160) = 1;
    }
    iVar3 = *(int *)(param_1 + 0x138);
    local_5 = iVar3 < (int)((*(int *)(param_1 + 0xe8) - *(int *)(param_1 + 0xe4)) + -1 + sVar4);
    if (local_5) {
      sVar4 = (*(int *)(param_1 + 0xe4) - *(int *)(param_1 + 0xe8)) + 1 + iVar3;
    }
    local_5 = !local_5;
    if ((int)sVar4 < 1) {
      local_5 = false;
    }
    else {
      FUN_005bd71d(*(undefined4 *)(param_1 + 0xd4),param_2,sVar4);
      *(undefined1 *)(param_1 + 0x160) = 1;
      if (*(int *)(param_1 + 0x48) != 0) {
        FUN_005da644(*(int *)(param_1 + 0x48),3,0x16,param_1,0);
      }
    }
    FUN_005f3a06(uVar1);
    FUN_005f2c6c(sVar4,0,0);
  }
  return local_5;
}

