
uint __thiscall FUN_0047c29a(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = FUN_00434ffd(-*(int *)(param_1 + 0x84) & 3);
  if ((param_2._2_1_ == '\x01') && (uVar2 = 0, *(int *)(param_1 + 0x60) != 0)) {
    iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x60) + 0x10) + (char)param_2 * 4);
    uVar2 = CONCAT31((int3)((uint)iVar1 >> 8),*(byte *)(iVar1 + param_2._1_1_) < 0x10);
  }
  else {
    uVar2 = uVar2 & 0xffffff00;
  }
  return uVar2;
}

