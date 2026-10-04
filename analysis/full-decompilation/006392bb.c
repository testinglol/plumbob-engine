
void FUN_006392bb(char *param_1,undefined4 param_2,undefined1 *param_3)

{
  char cVar1;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  int iVar5;
  char *pcVar6;
  char local_10c [264];
  
  iVar2 = FUN_00639cdd(param_1,0);
  if (iVar2 == 0) {
    iVar2 = FUN_0063950c(param_3,param_1,0x104);
    if (iVar2 == 0) {
      *param_3 = 0;
    }
  }
  else {
    iVar2 = FUN_006384a8(param_2);
    if (iVar2 == 0) {
LAB_006393bb:
      *param_3 = 0;
    }
    else {
      do {
        do {
          iVar2 = FUN_0064528f(iVar2,local_10c,0x104);
          if ((iVar2 == 0) || (local_10c[0] == '\0')) goto LAB_006393bb;
          sVar3 = _strlen(local_10c);
          cVar1 = local_10c[sVar3 - 1];
          pcVar6 = local_10c + sVar3;
          if ((cVar1 != '/') && ((cVar1 != '\\' && (cVar1 != ':')))) {
            *pcVar6 = '\\';
            pcVar6 = local_10c + sVar3 + 1;
            sVar3 = sVar3 + 1;
          }
          sVar4 = _strlen(param_1);
        } while (0x104 < sVar4 + sVar3);
        FUN_006358b0(pcVar6,param_1);
        iVar5 = FUN_00639cdd(local_10c,0);
      } while (iVar5 != 0);
      FUN_006358b0(param_3,local_10c);
    }
  }
  return;
}

