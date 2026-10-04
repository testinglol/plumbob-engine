
uint __thiscall FUN_00488924(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  FUN_00434ffd(-*(int *)(param_1 + 0x84) & 3);
  if (DAT_006e4a84 == 0) {
    uVar1 = ((byte)~*(byte *)(*(int *)(*(int *)(*(int *)(param_1 + 0x34) + 0xc) + (char)param_2 * 4)
                             + (int)param_2._1_1_) & 0x20) >> 5;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

