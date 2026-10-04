
undefined4 FUN_0047b670(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_3 >> 0x10;
  param_3._0_2_ = CONCAT11((&DAT_006e481d)[param_3 * 3],(&DAT_006e481c)[param_3 * 3]);
  param_3 = CONCAT22((short)uVar2,(undefined2)param_3) & 0xff00ffff;
  FUN_0046185f(&param_2,&param_3);
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x1c) + 0xc) + (char)param_2 * 4);
  return CONCAT31((int3)((uint)iVar1 >> 8),
                  *(char *)(iVar1 + param_2._1_1_) ==
                  *(char *)(*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 0xc) + (char)param_2 * 4) +
                           (int)param_2._1_1_));
}

