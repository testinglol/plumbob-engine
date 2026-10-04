
char * FUN_00639d23(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  DWORD DVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  char *pcVar8;
  
  pcVar3 = param_1;
  param_1 = (char *)0x0;
  DVar4 = GetCurrentThreadId();
  cVar1 = *pcVar3;
  pcVar8 = pcVar3;
  while (cVar1 != '\0') {
    pcVar8 = pcVar8 + 1;
    cVar1 = *pcVar8;
  }
  while ((pcVar8 = pcVar8 + -1, pcVar3 <= pcVar8 &&
         (iVar5 = FUN_00645ba5(pcVar3,pcVar8), iVar5 == 0))) {
    if (*pcVar8 != 'X') {
      return (char *)0x0;
    }
    if (4 < (int)param_1) break;
    param_1 = (char *)((int)param_1 + 1);
    *pcVar8 = (char)(DVar4 % 10) + '0';
    DVar4 = DVar4 / 10;
  }
  if ((*pcVar8 == 'X') && (4 < (int)param_1)) {
    *pcVar8 = 'a';
    param_1 = (char *)0x62;
    puVar6 = (undefined4 *)FUN_0063d796();
    uVar2 = *puVar6;
    puVar6 = (undefined4 *)FUN_0063d796();
    *puVar6 = 0;
    while( true ) {
      iVar5 = FUN_00639cdd(pcVar3,0);
      if ((iVar5 != 0) && (piVar7 = (int *)FUN_0063d796(), *piVar7 != 0xd)) {
        puVar6 = (undefined4 *)FUN_0063d796();
        *puVar6 = uVar2;
        return pcVar3;
      }
      puVar6 = (undefined4 *)FUN_0063d796();
      *puVar6 = 0;
      if (param_1 == (char *)0x7b) break;
      *pcVar8 = (char)param_1;
      param_1 = (char *)((int)param_1 + 1);
    }
    puVar6 = (undefined4 *)FUN_0063d796();
    *puVar6 = uVar2;
  }
  return (char *)0x0;
}

