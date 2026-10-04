
void __thiscall FUN_00406635(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  piVar3 = (int *)(param_1 + 0xc);
  do {
    if (*piVar3 == 0) {
      iVar1 = param_1 + iVar2 * 0x14;
      *(undefined4 *)(iVar1 + 0xc) = param_2;
      *(undefined2 *)(iVar1 + 0x1c) = 1;
      FUN_004071be(*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(param_1 + (iVar2 * 5 + 5) * 4));
      return;
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 5;
  } while (iVar2 < 8);
  return;
}

