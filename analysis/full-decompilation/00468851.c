
undefined1 __fastcall FUN_00468851(short *param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  
  if (*(char *)((int)param_1 + 0x71) == '\0') {
    iVar3 = *(int *)(param_1 + 2);
    *(undefined1 *)(param_1 + 0x3b) = 1;
    for (; iVar3 != *(int *)(param_1 + 4); iVar3 = iVar3 + 3) {
      sVar2 = FUN_004688c4(iVar3);
      if (sVar2 == *param_1) {
        bVar1 = FUN_0044530c(iVar3);
        *(undefined1 *)((int)param_1 + 0x71) = 1;
        *(byte *)(param_1 + 0x39) = bVar1 >> 2 & 1;
        break;
      }
    }
    if (*(char *)((int)param_1 + 0x71) == '\0') {
      if ((*(int *)(param_1 + 4) - *(int *)(param_1 + 2)) / 3 == 1) {
        *(undefined1 *)(param_1 + 0x39) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 0x39) = 0;
      }
      *(undefined1 *)((int)param_1 + 0x71) = 1;
    }
  }
  return (char)param_1[0x39];
}

