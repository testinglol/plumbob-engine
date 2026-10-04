
void __fastcall FUN_0042a392(int *param_1)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  pcVar3 = (char *)*param_1;
  if ((*pcVar3 == '\0') && (*(char **)(*(int *)(pcVar3 + 4) + 4) == pcVar3)) {
    iVar2 = *(int *)(pcVar3 + 0xc);
  }
  else {
    iVar4 = *(int *)(pcVar3 + 8);
    if (*(int *)(pcVar3 + 8) == 0) {
      iVar4 = *(int *)(pcVar3 + 4);
      while (pcVar1 = *(char **)(iVar4 + 8), *param_1 = iVar4, pcVar3 == pcVar1) {
        iVar4 = *(int *)(iVar4 + 4);
        pcVar3 = (char *)*param_1;
      }
      return;
    }
    do {
      iVar2 = iVar4;
      iVar4 = *(int *)(iVar2 + 0xc);
    } while (*(int *)(iVar2 + 0xc) != 0);
  }
  *param_1 = iVar2;
  return;
}

