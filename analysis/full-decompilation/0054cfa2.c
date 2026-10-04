
void __fastcall FUN_0054cfa2(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (*(int *)(param_1 + 0x104) != *(int *)(param_1 + 0x1c8)) {
    *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + 1;
    *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x1c8);
    if (5 < *(int *)(param_1 + 0x108)) {
      *(undefined4 *)(param_1 + 0x108) = 0;
    }
  }
  piVar4 = (int *)(param_1 + 0x14c);
  iVar3 = 10;
  do {
    if ((*(uint *)(param_1 + 0x100) != 0) &&
       (iVar1 = *piVar4, (*(uint *)(iVar1 + 0x1b4) & *(uint *)(param_1 + 0x100)) != 0)) {
      if (*(int *)(iVar1 + 0x1d8) == 0x17) {
        iVar2 = -10;
      }
      else {
        iVar2 = -0x46;
      }
      FUN_0054d021(*(int *)(iVar1 + 0x208) + -0x18,*(int *)(iVar1 + 0x20c) + iVar2);
    }
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

