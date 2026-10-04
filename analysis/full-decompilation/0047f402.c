
void FUN_0047f402(byte *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined **local_32c [3];
  undefined1 local_320 [256];
  undefined **local_220 [2];
  short local_218;
  undefined1 local_214 [256];
  undefined **local_114;
  undefined1 *local_110;
  undefined2 local_10c;
  undefined1 local_108 [256];
  undefined4 local_8;
  
  FUN_0046f824(local_108,0,0x100);
  local_10c = 0;
  local_8 = *param_2;
  local_114 = &PTR_FUN_00666524;
  *local_110 = 0;
  bVar1 = param_1[1];
  if (bVar1 < 2) {
    FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0xeb,
                 CONCAT22((short)((uint)local_110 >> 0x10),(ushort)bVar1) + 1);
    FUN_0046f917(&DAT_006e54e8,0xffffffff);
  }
  else if (bVar1 == 2) {
    FUN_0046f847(s_stack_object_to_006c53e8,0xffffffff);
    FUN_0047e457(param_2[3],0x19,CONCAT22((short)((uint)&local_114 >> 0x10),(ushort)param_1[3]),
                 &local_114,param_4);
  }
  else if (bVar1 == 3) {
    FUN_0047e457(param_2[3],0x19,CONCAT22((short)((uint)&local_114 >> 0x10),(ushort)param_1[3]),
                 &local_114,param_4);
    FUN_0046f847(s_to_stack_object_006c53fc,0xffffffff);
  }
  FUN_0046f824(local_214,0,0x100);
  local_220[0] = &PTR_FUN_00666524;
  FUN_00465b21(local_220,local_8,0x102,CONCAT22(extraout_var,(ushort)*param_1) + 1);
  if (local_218 == 0) {
    FUN_0046f847(&DAT_006c53e0,0xffffffff);
    FUN_0046fa40(*param_1);
  }
  FUN_0046f824(local_320,0,0x100);
  local_32c[0] = &PTR_FUN_00666524;
  FUN_0046f917(local_220,0xffffffff);
  FUN_0046f847(&DAT_006c532c,0xffffffff);
  FUN_0046f917(&local_114,0xffffffff);
  FUN_0046fa24(0x28);
  if ((param_1[2] & 4) == 0) {
    FUN_0047e457(param_2[3],CONCAT22(extraout_var_00,(ushort)param_1[4]),
                 CONCAT22(extraout_var_00,*(undefined2 *)(param_1 + 6)),param_3,param_4);
    FUN_0046f847(&DAT_006c53d8,0xffffffff);
    FUN_0046f917(local_32c,0xffffffff);
  }
  else {
    FUN_0046f917(local_32c,0xffffffff);
    FUN_0046f847(&DAT_006c53d8,0xffffffff);
    FUN_0047e457(param_2[3],CONCAT22(extraout_var_01,(ushort)param_1[4]),
                 CONCAT22(extraout_var_01,*(undefined2 *)(param_1 + 6)),param_3,param_4);
  }
  if ((~param_1[2] & 1) == 0) {
    FUN_0046f847(s___fail_if_too_small_006c53c4,0xffffffff);
  }
  if ((param_1[2] & 2) != 0) {
    FUN_0046f847(s___use_neighbors_006c53b4,0xffffffff);
  }
  FUN_0046fa24(0x29);
  return;
}

