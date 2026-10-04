
void __fastcall FUN_005670fe(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  FUN_004733e4(DAT_006e5490);
  iVar3 = FUN_00473417();
  if (iVar3 != 0) {
    *(int *)(param_1 + 0x114) = *(int *)(param_1 + 0x114) + 1;
    if (5 < *(int *)(param_1 + 0x114)) {
      *(undefined4 *)(param_1 + 0x114) = 0;
    }
  }
  piVar4 = (int *)(param_1 + 0x3d8);
  iVar3 = 9;
  do {
    if ((*(uint *)(param_1 + 0x10c) != 0) &&
       (iVar1 = *piVar4, (*(uint *)(iVar1 + 0x1b4) & *(uint *)(param_1 + 0x10c)) != 0)) {
      if (*(int *)(iVar1 + 0x1d8) == 0x53) {
        iVar2 = -10;
      }
      else {
        iVar2 = -0x46;
      }
      FUN_00567189(*(int *)(iVar1 + 0x208) + -0x18,*(int *)(iVar1 + 0x20c) + iVar2);
    }
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

