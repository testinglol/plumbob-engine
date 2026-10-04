
undefined4 __thiscall FUN_005f499f(int param_1,char *param_2)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  
  if (*(char *)(param_1 + 0x195) != '\0') {
    sVar2 = _strlen(param_2);
    pcVar5 = param_2 + sVar2;
    for (; param_2 < pcVar5; param_2 = param_2 + iVar3) {
      cVar1 = (**(code **)(**(int **)(param_1 + 0x114) + 0x40))((int)*param_2);
      if (cVar1 == '\0') {
        uVar4 = 0;
        do {
          if (*param_2 == (&DAT_00675574)[uVar4]) {
            return 0;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < 0x14);
      }
      iVar3 = (**(code **)(**(int **)(param_1 + 0x114) + 0x44))(param_2,0xffffffff);
    }
  }
  return 1;
}

