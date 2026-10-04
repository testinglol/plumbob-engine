
void FUN_0042a2fe(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  short sVar4;
  int *piVar5;
  
  iVar1 = *(int *)(*DAT_006e486c + 0x14);
  piVar5 = *(int **)(iVar1 + 0x84);
  if (piVar5 != *(int **)(iVar1 + 0x88)) {
    do {
      sVar4 = *(short *)(*piVar5 + 0x5cc);
      if (sVar4 == 0) {
        sVar4 = 1;
      }
      cVar3 = FUN_0041022e(*piVar5);
      if (cVar3 != '\0') {
        sVar4 = 0;
      }
      cVar3 = FUN_004074bc();
      if ((cVar3 == '\0') && (sVar4 == 0)) {
        sVar4 = 1;
      }
      iVar2 = *piVar5;
      piVar5 = piVar5 + 1;
      *(short *)(iVar2 + 0x5cc) = sVar4;
    } while (piVar5 != *(int **)(iVar1 + 0x88));
  }
  return;
}

