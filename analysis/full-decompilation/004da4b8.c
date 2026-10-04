
undefined4 FUN_004da4b8(undefined4 param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char local_1408 [5112];
  undefined4 uStack_10;
  char *pcStack_c;
  
  FUN_00636080();
  iVar2 = 0;
  iVar3 = 0;
  cVar1 = *param_2;
  while ((cVar1 != '\0' && (iVar3 < 0x1400))) {
    if (param_2[iVar3] == '\n') {
      builtin_strncpy(local_1408 + iVar2,"<br>",4);
      iVar2 = iVar2 + 3;
    }
    else {
      local_1408[iVar2] = param_2[iVar3];
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 1;
    cVar1 = param_2[iVar3];
  }
  local_1408[iVar2] = '\0';
  pcStack_c = local_1408;
  uStack_10 = 0x4da531;
  FUN_005b870f();
  return param_1;
}

