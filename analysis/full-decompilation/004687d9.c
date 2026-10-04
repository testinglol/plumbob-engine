
undefined4 __thiscall FUN_004687d9(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  
  FUN_00434ffd(-*(int *)(param_1 + 0x84) & 3);
  uVar1 = *(uint *)(&DAT_006f4620 + ((-*(int *)(param_1 + 0x84) & 3U) * 0x40 + param_3) * 4);
  return CONCAT31((int3)(uVar1 >> 8),
                  (*(byte *)(*(int *)(*(int *)(*(int *)(param_1 + 0x40 + param_2._2_1_ * 4) + 0xc) +
                                     (char)param_2 * 4) + param_2._1_1_ * 0xe) & uVar1) == uVar1);
}

