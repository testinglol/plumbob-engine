
void FUN_005c22fb(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char local_104 [256];
  
  iVar3 = 0;
  iVar1 = *param_1;
  iVar2 = param_1[1];
  iVar5 = 0;
  do {
    iVar4 = iVar5 + 1;
    if (*(char *)(iVar1 + iVar5) == '_') {
      iVar3 = iVar3 + 1;
    }
    iVar5 = iVar4;
  } while (iVar3 < 2);
  iVar5 = 0;
  for (; (iVar4 < iVar2 - iVar1 && (*(char *)(iVar1 + iVar4) != '.')); iVar4 = iVar4 + 1) {
    local_104[iVar5] = *(char *)(iVar1 + iVar4);
    iVar5 = iVar5 + 1;
  }
  local_104[iVar5] = '\0';
  FUN_005d4bbf(local_104);
  return;
}

