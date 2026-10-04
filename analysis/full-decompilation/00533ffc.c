
void __fastcall FUN_00533ffc(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xe8);
  iVar2 = *(int *)(iVar1 + 8);
  while (iVar2 != iVar1) {
    *(undefined4 *)(iVar2 + 0x30) = 0;
    *(undefined4 *)(iVar2 + 0x34) = 0;
    *(undefined4 *)(iVar2 + 0x40) = 0;
    *(undefined4 *)(iVar2 + 0x38) = 0;
    *(undefined4 *)(iVar2 + 0x3c) = 0;
    FUN_0041674f();
  }
  return;
}

