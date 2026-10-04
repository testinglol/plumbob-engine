
void __thiscall FUN_00439016(int param_1,uint *param_2,byte param_3)

{
  uint *puVar1;
  uint uVar2;
  
  if (DAT_006d6184 != 0) {
    if ((param_3 & 1) != 0) {
      puVar1 = (uint *)(param_1 + 0x160);
      *puVar1 = *param_2;
      *(uint *)(param_1 + 0x164) = param_2[1];
      *(uint *)(param_1 + 0x168) = param_2[2];
      *(uint *)(param_1 + 0x16c) = param_2[3];
      if ((int)*puVar1 < *(int *)(param_1 + 0x168)) {
        *puVar1 = *puVar1 & 0xfffffffc;
        *(uint *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + 3U & 0xfffffffc;
      }
    }
    if ((param_3 & 2) != 0) {
      puVar1 = (uint *)(param_1 + 0x170);
      *puVar1 = *param_2;
      *(uint *)(param_1 + 0x174) = param_2[1];
      *(uint *)(param_1 + 0x178) = param_2[2];
      *(uint *)(param_1 + 0x17c) = param_2[3];
      uVar2 = *(uint *)(param_1 + 0x178);
      if ((int)*puVar1 < (int)uVar2) {
        *puVar1 = *puVar1 & 0xfffffffc;
        *(uint *)(param_1 + 0x178) = uVar2 + 3 & 0xfffffffc;
      }
    }
  }
  return;
}

