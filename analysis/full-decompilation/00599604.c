
void __fastcall FUN_00599604(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x60);
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    uVar2 = FUN_0059964b();
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x130) = uVar2;
      for (iVar1 = *(int *)(iVar1 + 0x28); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
        FUN_00596389();
      }
    }
  }
  *(undefined4 *)(param_1 + 0xa0) = uVar2;
  *(undefined4 *)(param_1 + 0xa4) = uVar2;
  return;
}

