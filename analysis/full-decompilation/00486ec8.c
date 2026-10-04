
void __thiscall FUN_00486ec8(int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  
  if ((short)param_2 != *(short *)(param_1 + 0x4c)) {
    iVar1 = FUN_00492b10(*(short *)(param_1 + 0x4c));
    if (iVar1 != 0) {
      FUN_00432189(*(uint *)(iVar1 + 0x114) & 0xe);
    }
    *(short *)(param_1 + 0x4c) = (short)param_2;
    iVar1 = FUN_00492b10(param_2);
    if (iVar1 != 0) {
      FUN_00432189(*(uint *)(iVar1 + 0x114) & 0x1e | -(uint)(param_3 != '\0') & 0x10 | 1);
    }
  }
  return;
}

