
undefined1 __fastcall FUN_0048749e(int param_1)

{
  short sVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  if (((*(int *)(param_1 + 0x3c) != 0) && (*(int *)(*(int *)(param_1 + 0x3c) + 0x1ac) != 0)) &&
     (cVar3 = FUN_004358e3(), cVar3 != '\0')) {
    if ((*(int *)(param_1 + 0x34) == 4) || (*(int *)(param_1 + 0x34) == 3)) {
      iVar4 = -1;
      iVar5 = 1;
      do {
        (**(code **)(**(int **)(param_1 + 0x3c) + 0x4c))(iVar5);
        piVar2 = *(int **)(param_1 + 0x3c);
        if ((piVar2[0x6b] != 0) && ((short)piVar2[0x6c] != 0)) {
          return 0;
        }
        if (DAT_006e4a7c == 0x16) {
          return 0;
        }
        (**(code **)(*piVar2 + 0x4c))(iVar4);
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + -1;
      } while (-4 < iVar4);
    }
    else {
      sVar1 = *(short *)(*(int *)(param_1 + 0x3c) + 0x78);
      iVar4 = -1;
      iVar5 = 1;
      do {
        (**(code **)(**(int **)(param_1 + 0x3c) + 0x4c))(iVar5);
        piVar2 = *(int **)(param_1 + 0x3c);
        if ((piVar2[0x6b] != 0) && ((short)piVar2[0x6c] != 0)) {
          return 1;
        }
        (**(code **)(*piVar2 + 0x4c))(iVar4);
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar5 < 8 / (int)sVar1);
    }
  }
  return 0;
}

