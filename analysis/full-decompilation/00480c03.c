
void FUN_00480c03(byte *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  undefined2 extraout_var;
  char *pcVar3;
  undefined **local_110 [3];
  undefined1 local_104 [256];
  
  FUN_0046fa24(0x28);
  FUN_0046f824(local_104,0,0x100);
  local_110[0] = &PTR_FUN_00666524;
  uVar1 = (uint)*param_1;
  if (uVar1 == 0) {
    uVar2 = 7;
  }
  else if (uVar1 == 1) {
    uVar2 = 9;
  }
  else if (uVar1 - 2 == 0) {
    uVar2 = 0x19;
  }
  else {
    uVar2 = CONCAT31((int3)(uVar1 - 2 >> 8),param_1[1]);
  }
  FUN_0047e457(*(undefined4 *)(param_2 + 0xc),
               CONCAT22((short)((uint)uVar2 >> 0x10),(ushort)(byte)uVar2),
               CONCAT22((short)((uint)local_110 >> 0x10),*(undefined2 *)(param_1 + 2)),local_110,
               param_4);
  if ((param_1[4] & 1) == 0) {
    if ((~(param_1[4] >> 1) & 1) == 0) {
      pcVar3 = &DAT_006c5724;
    }
    else {
      pcVar3 = s_subtract_006c5904;
    }
    FUN_0046f847(pcVar3,0xffffffff);
    FUN_0046f917(local_110,0xffffffff);
  }
  else {
    FUN_0046f847(s_test_if_006c5934,0xffffffff);
    FUN_0046f917(local_110,0xffffffff);
    if ((~(param_1[4] >> 1) & 1) == 0) {
      pcVar3 = s_may_be_added_006c5910;
    }
    else {
      pcVar3 = s_may_be_subtracted_006c5920;
    }
    FUN_0046f847(pcVar3,0xffffffff);
  }
  FUN_0046f847(&DAT_006c58fc,0xffffffff);
  FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0xf0,
               CONCAT22(extraout_var,(ushort)param_1[6]) + 1);
  FUN_0046f917(&DAT_006e54e8,0xffffffff);
  FUN_0046fa24(0x29);
  return;
}

