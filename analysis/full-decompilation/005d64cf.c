
uint __thiscall FUN_005d64cf(int param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0;
  uVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc;
  if (uVar1 != 0) {
    iVar4 = 0;
    do {
      iVar2 = _strcmp(param_2,*(char **)(iVar4 + *(int *)(param_1 + 4)));
      if (iVar2 == 0) {
        return uVar3;
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0xc;
    } while (uVar3 < uVar1);
  }
  return 0xffffffff;
}

