
void __fastcall FUN_005995c6(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x60);
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x134);
    *(undefined4 *)(iVar1 + 0x134) = uVar2;
  }
  *(undefined4 *)(param_1 + 0xa8) = uVar2;
  *(undefined4 *)(param_1 + 0xac) = uVar2;
  return;
}

