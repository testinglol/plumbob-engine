
void __fastcall FUN_0059951f(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x60);
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x150);
    *(undefined4 *)(iVar1 + 0x150) = uVar2;
  }
  *(undefined4 *)(param_1 + 0xb0) = uVar2;
  *(undefined4 *)(param_1 + 0xb4) = uVar2;
  return;
}

