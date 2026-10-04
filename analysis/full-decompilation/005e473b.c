
void __thiscall FUN_005e473b(int param_1,uint param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  if ((*(uint *)(param_1 + 0x150) & param_2) != 0) {
    if (param_2 == 1) {
      pcVar2 = *(char **)(param_1 + 0x184);
      pcVar1 = DAT_006fe938;
    }
    else if (param_2 == 2) {
      pcVar2 = *(char **)(param_1 + 0x188);
      pcVar1 = DAT_006fe928;
    }
    else if (param_2 == 4) {
      pcVar2 = *(char **)(param_1 + 0x180);
      pcVar1 = DAT_006fe948;
    }
    else {
      if (param_2 != 8) {
        return;
      }
      pcVar2 = *(char **)(param_1 + 0x18c);
      pcVar1 = DAT_006fe918;
    }
    if (((pcVar2 != (char *)0x0) || (pcVar2 = pcVar1, pcVar1 != (char *)0x0)) && (*pcVar2 != '\0'))
    {
      FUN_0057a14d(pcVar2);
    }
  }
  return;
}

