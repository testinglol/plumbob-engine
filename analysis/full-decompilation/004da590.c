
undefined4 FUN_004da590(undefined4 param_1,char *param_2)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  char local_1408 [5108];
  undefined4 uStackY_14;
  
  FUN_00636080();
  iVar4 = 0;
  uStackY_14 = 0x4da5ae;
  sVar2 = _strlen(param_2);
  iVar3 = 0;
  cVar1 = *param_2;
  while ((cVar1 != '\0' && (iVar3 < 0x32))) {
    if (((int)sVar2 < 0x33) || (iVar3 < 0x2f)) {
      cVar1 = param_2[iVar3];
      if (cVar1 == '\n') {
        local_1408[iVar4] = ' ';
      }
      else if (cVar1 == '\"') {
        builtin_strncpy(local_1408 + iVar4,"&quot;",6);
        iVar4 = iVar4 + 5;
      }
      else {
        local_1408[iVar4] = cVar1;
      }
    }
    else {
      local_1408[iVar4] = '.';
    }
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 1;
    cVar1 = param_2[iVar3];
  }
  local_1408[iVar4] = '\0';
  uStackY_14 = 0x4da642;
  FUN_005b870f();
  return param_1;
}

