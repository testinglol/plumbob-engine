
void __fastcall FUN_005ebb05(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  piVar2 = (int *)FUN_004b46a0();
  uVar3 = 0;
  if ((*(int *)(param_1 + 0x194) - *(int *)(param_1 + 400)) / 0x28 != 0) {
    iVar4 = 0;
    do {
      iVar1 = *(int *)(iVar4 + 0xc + *(int *)(param_1 + 400));
      if (iVar1 != 0) {
        (**(code **)(*piVar2 + 0x24))(iVar1);
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0x28;
    } while (uVar3 < (uint)((*(int *)(param_1 + 0x194) - *(int *)(param_1 + 400)) / 0x28));
  }
  *(undefined1 *)(param_1 + 0x14c) = 0;
  return;
}

