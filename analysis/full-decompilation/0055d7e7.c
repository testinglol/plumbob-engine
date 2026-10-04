
void __fastcall FUN_0055d7e7(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x148);
  iVar1 = *(int *)(iVar2 + 8);
  while (iVar1 != iVar2) {
    if ((*(int *)(param_1 + 0x194) != 0) &&
       (iVar2 = FUN_0042ba25(*(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x1d8)), iVar2 == 2)) {
      if (*(char *)(param_1 + 0x121) == '\0') {
        FUN_0054f7ae(1);
      }
      iVar2 = *(int *)(iVar1 + 0x14);
      if ((*(uint *)(param_1 + 0x194) & *(uint *)(iVar2 + 0x1b4)) != 0) {
        FUN_0055d87f(*(int *)(iVar2 + 0x208) + -0x18,*(int *)(iVar2 + 0x20c) + -0x46);
      }
    }
    FUN_0041674f();
    iVar2 = *(int *)(param_1 + 0x148);
  }
  return;
}

