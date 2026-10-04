
undefined4 FUN_004da537(undefined4 param_1,char *param_2)

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
  while ((cVar1 != '\0' && (iVar2 < 0x1400))) {
    if (param_2[iVar2] != '^') {
      local_1408[iVar3] = param_2[iVar2];
      iVar3 = iVar3 + 1;
    }
    iVar2 = iVar2 + 1;
    cVar1 = param_2[iVar2];
  }
  local_1408[iVar3] = '\0';
  pcStack_c = local_1408;
  uStack_10 = 0x4da58a;
  FUN_005b870f();
  return param_1;
}

