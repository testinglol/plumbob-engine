
uint __fastcall FUN_00599cd3(int param_1)

{
  char cVar1;
  int iVar2;
  uint in_EAX;
  uint uVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x10);
  uVar3 = in_EAX & 0xffffff00;
  do {
    if (piVar4 == *(int **)(param_1 + 0x14)) {
      return uVar3;
    }
    iVar2 = *piVar4;
    piVar4 = piVar4 + 1;
    cVar1 = *(char *)(iVar2 + 300);
    uVar3 = CONCAT31((int3)((uint)iVar2 >> 8),cVar1);
  } while (cVar1 == '\0');
  return uVar3;
}

