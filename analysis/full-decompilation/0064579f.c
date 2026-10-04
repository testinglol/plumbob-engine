
int FUN_0064579f(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int local_8;
  int local_4;
  
  iVar4 = -1;
  FUN_0063d88b(0x12);
  local_8 = 0;
  local_4 = 0;
  piVar3 = &DAT_00704000;
  while (puVar2 = (undefined4 *)*piVar3, puVar1 = puVar2, puVar2 != (undefined4 *)0x0) {
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      if ((*(byte *)(puVar2 + 1) & 1) == 0) {
        if (puVar2[2] == 0) {
          FUN_0063d88b(0x11);
          if (puVar2[2] == 0) {
            InitializeCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
            puVar2[2] = puVar2[2] + 1;
          }
          FUN_0063d8ec(0x11);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
        if ((*(byte *)(puVar2 + 1) & 1) == 0) {
          *puVar2 = 0xffffffff;
          iVar4 = ((int)puVar2 - *piVar3) / 0x24 + local_4;
          if (iVar4 != -1) goto LAB_006458b1;
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
      }
      puVar1 = (undefined4 *)*piVar3;
    }
    local_4 = local_4 + 0x20;
    piVar3 = piVar3 + 1;
    local_8 = local_8 + 1;
    if (0x7040ff < (int)piVar3) goto LAB_006458b1;
  }
  puVar2 = _malloc(0x480);
  if (puVar2 != (undefined4 *)0x0) {
    DAT_00704100 = DAT_00704100 + 0x20;
    (&DAT_00704000)[local_8] = puVar2;
    puVar1 = puVar2;
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      puVar2[2] = 0;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar1 = (undefined4 *)(&DAT_00704000)[local_8];
    }
    iVar4 = local_8 << 5;
    FUN_006459ff(iVar4);
  }
LAB_006458b1:
  FUN_0063d8ec(0x12);
  return iVar4;
}

