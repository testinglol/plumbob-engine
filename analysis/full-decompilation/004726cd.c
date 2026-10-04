
void FUN_004726cd(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00420048(param_1);
  *(undefined4 *)(iVar1 + 0x8c) = *(undefined4 *)(iVar1 + 0x1c);
  uVar2 = FUN_004726f7();
  *(undefined4 *)(iVar1 + 0x1c) = uVar2;
  FUN_0042004f(param_1);
  return;
}

