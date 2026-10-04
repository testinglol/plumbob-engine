
undefined4 FUN_004ede68(char *param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char local_24 [32];
  
  sVar1 = _strlen(param_1);
  iVar4 = sVar1 - 1;
  if (-1 < iVar4) {
    do {
      if (param_1[iVar4] == '.') break;
      iVar4 = iVar4 + -1;
    } while (-1 < iVar4);
    if (((-1 < iVar4) && (iVar4 = iVar4 + -1, -1 < iVar4)) &&
       (iVar2 = FUN_006368c3((int)param_1[iVar4]), iVar5 = iVar4, iVar2 != 0)) {
      do {
        iVar2 = FUN_006368c3((int)param_1[iVar5]);
        if (iVar2 == 0) break;
        iVar5 = iVar5 + -1;
      } while (-1 < iVar5);
      iVar5 = iVar5 + 1;
      for (iVar2 = iVar5; iVar2 <= iVar4; iVar2 = iVar2 + 1) {
        local_24[iVar2 - iVar5] = param_1[iVar2];
      }
      local_24[iVar2 - iVar5] = '\0';
      uVar3 = FUN_00635f62(local_24);
      return uVar3;
    }
  }
  return 0xffffffff;
}

