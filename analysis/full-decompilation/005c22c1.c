
undefined4 FUN_005c22c1(char *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  char local_10 [12];
  
  if (*param_1 == '_') {
    iVar3 = 0;
    while( true ) {
      pcVar1 = param_1 + 1;
      param_1 = param_1 + 1;
      if (*pcVar1 == '_') break;
      local_10[iVar3] = *pcVar1;
      iVar3 = iVar3 + 1;
    }
    local_10[iVar3] = '\0';
    uVar2 = FUN_00635f62(local_10);
  }
  else {
    uVar2 = 0x80000000;
  }
  return uVar2;
}

