
void __thiscall FUN_0047270c(int param_1,int *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  uint uVar5;
  char *pcVar6;
  
  iVar2 = *(int *)(param_1 + 0x10);
  iVar3 = *(int *)(param_1 + 0xc);
  uVar5 = 0xffffffff;
  pcVar6 = param_3;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  sVar4 = _strlen(param_3);
  FUN_00412d8a(param_3,param_3 + sVar4);
  *param_2 = iVar2 - iVar3;
  param_2[1] = ~uVar5 - 1;
  return;
}

