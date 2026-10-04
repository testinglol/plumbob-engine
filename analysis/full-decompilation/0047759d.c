
void __thiscall FUN_0047759d(int param_1,char *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  int local_2c [9];
  undefined1 local_8 [4];
  
  pcVar4 = (char *)(*(int *)(*(int *)(param_1 + 0x10) + *param_2 * 4) + (int)param_2[1]);
  if (*pcVar4 != -1) {
    *pcVar4 = -1;
    iVar6 = 0;
    local_2c[5] = 0;
    local_2c[4] = 2;
    local_2c[6] = 3;
    local_2c[7] = 1;
    local_2c[0] = 8;
    local_2c[1] = 4;
    local_2c[2] = 2;
    local_2c[3] = 1;
    do {
      iVar2 = *(int *)((int)local_2c + iVar6 + 0x10);
      uVar3 = (uint)param_2 >> 0x10;
      param_2._0_2_ = CONCAT11((&DAT_006e481d)[iVar2 * 3],(&DAT_006e481c)[iVar2 * 3]);
      param_2 = (char *)(CONCAT22((short)uVar3,param_2._0_2_) & 0xff00ffff);
      pcVar4 = (char *)FUN_0046185f(local_8,&param_2);
      local_2c[8] = (int)pcVar4[1];
      pbVar5 = (byte *)(*(int *)(*(int *)(param_1 + 0x10) + *pcVar4 * 4) + local_2c[8]);
      bVar1 = *pbVar5;
      if (bVar1 != 0xff) {
        *pbVar5 = ~(byte)*(undefined4 *)((int)local_2c + iVar6) & bVar1;
      }
      iVar6 = iVar6 + 4;
    } while (iVar6 < 0x10);
  }
  return;
}

