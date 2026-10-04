
void __fastcall FUN_005771b0(int param_1)

{
  uint uVar1;
  int iVar3;
  undefined8 uVar4;
  uint uVar2;
  
  if (*(int *)(param_1 + 8) != 0 || *(int *)(param_1 + 0xc) != 0) {
    uVar4 = FUN_005fd8c4();
    uVar1 = *(uint *)(param_1 + 8);
    uVar2 = *(uint *)(param_1 + 8);
    iVar3 = *(int *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(uint *)(param_1 + 0x10) = (uint)uVar4 - uVar2;
    *(uint *)(param_1 + 0x14) =
         ((int)((ulonglong)uVar4 >> 0x20) - iVar3) - (uint)((uint)uVar4 < uVar1);
  }
  return;
}

