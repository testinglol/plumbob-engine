
void __fastcall FUN_0055d388(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x148);
  iVar2 = *(int *)(iVar1 + 8);
  while (iVar2 != iVar1) {
    FUN_0054f484(0);
    iVar1 = *(int *)(*(int *)(iVar2 + 0x14) + 0x1d8);
    if ((*(char *)(param_1 + 0x121) == '\0') && (iVar3 = FUN_0042ba25(iVar1), iVar3 == 2)) {
      FUN_0054f7ae(1);
    }
    if ((*(int *)(param_1 + 0xd4) == 3) ||
       ((*(char *)(param_1 + 0x118) != '\0' && (*(int *)(param_1 + 0xd4) != 5)))) {
      iVar3 = FUN_0042ba25(iVar1);
      if (iVar3 == 2) {
        FUN_0054f7ae(1);
      }
      else {
        iVar3 = FUN_0042ba25(iVar1);
        if (iVar3 == 1) {
          if (*(int *)(*(int *)(iVar2 + 0x14) + 0x1b8) == -1) {
            FUN_0054f7c3(1);
          }
          else {
            FUN_0054f7d8(1);
          }
        }
      }
    }
    if ((*(int *)(param_1 + 0xd4) == 5) && (iVar1 != *(int *)(param_1 + 0x11c))) {
      FUN_0054f7d8(1);
    }
    FUN_0041674f();
    iVar1 = *(int *)(param_1 + 0x148);
  }
  return;
}

