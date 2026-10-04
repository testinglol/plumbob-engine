
void __fastcall FUN_00555324(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  FUN_004733e4(DAT_006e5490);
  iVar2 = FUN_00473417();
  if (iVar2 != 0) {
    *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) + 1;
    if (5 < *(int *)(param_1 + 0x120)) {
      *(undefined4 *)(param_1 + 0x120) = 0;
    }
  }
  piVar3 = (int *)(param_1 + 0x14c);
  iVar2 = 9;
  do {
    iVar1 = *piVar3;
    if ((((*(int *)(iVar1 + 0x1d8) < 0x5a) || (0x5c < *(int *)(iVar1 + 0x1d8))) &&
        (*(uint *)(param_1 + 0x118) != 0)) &&
       ((*(uint *)(iVar1 + 0x1b4) & *(uint *)(param_1 + 0x118)) != 0)) {
      FUN_005553b1(*(int *)(iVar1 + 0x208) + -0x18,*(int *)(iVar1 + 0x20c) + -0x46);
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

