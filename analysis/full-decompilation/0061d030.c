
void FUN_0061d030(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x102c0) < 0x200) {
    *(undefined4 *)(*(int *)(param_1 + 0x102c4) + 4 + *(int *)(param_1 + 0x102c0) * 0xc) = param_4;
    *(undefined4 *)(*(int *)(param_1 + 0x102c4) + *(int *)(param_1 + 0x102c0) * 0xc) = param_3;
    *(undefined4 *)(*(int *)(param_1 + 0x102c4) + 8 + *(int *)(param_1 + 0x102c0) * 0xc) = 0;
    iVar1 = *(int *)(param_1 + 0x102c0);
    *(int *)(param_1 + 0x102c0) = iVar1 + 1;
    FUN_0061ab10(*(undefined4 *)(param_1 + 0x102bc),param_2,iVar1);
  }
  return;
}

