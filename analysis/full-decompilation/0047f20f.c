
void FUN_0047f20f(char *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 extraout_var;
  undefined **local_32c;
  undefined1 *local_328;
  undefined2 local_324;
  undefined1 local_320 [256];
  undefined **local_220 [3];
  undefined1 local_214 [256];
  undefined **local_114 [2];
  short local_10c;
  undefined1 local_108 [256];
  undefined4 local_8;
  
  FUN_0046f824(local_320,0,0x100);
  local_324 = 0;
  local_8 = *param_2;
  local_32c = &PTR_FUN_00666524;
  *local_328 = 0;
  FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0xaa,
               CONCAT22((short)((uint)local_328 >> 0x10),(short)param_1[3]) + 1);
  FUN_0046f917(&DAT_006e54e8,0xffffffff);
  FUN_0046f824(local_108,0,0x100);
  local_114[0] = &PTR_FUN_00666524;
  FUN_00465b21(local_114,local_8,0x102,CONCAT22(extraout_var,(short)param_1[1]) + 1);
  if (local_10c == 0) {
    FUN_0046f847(&DAT_006c53e0,0xffffffff);
    FUN_0046fa40((int)param_1[1]);
  }
  FUN_0046f824(local_214,0,0x100);
  local_220[0] = &PTR_FUN_00666524;
  FUN_0046f917(local_114,0xffffffff);
  FUN_0046f847(&DAT_006c532c,0xffffffff);
  FUN_0046f917(&local_32c,0xffffffff);
  FUN_0046fa24(0x28);
  if (*param_1 == '\0') {
    FUN_0047e457(param_2[3],9,(short)param_1[2],param_3,param_4);
    FUN_0046f847(&DAT_006c53d8,0xffffffff);
    FUN_0046f917(local_220,0xffffffff);
  }
  else {
    FUN_0046f917(local_220,0xffffffff);
    FUN_0046f847(&DAT_006c53d8,0xffffffff);
    FUN_0047e457(param_2[3],9,(short)param_1[2],param_3,param_4);
  }
  if ((~param_1[4] & 1U) == 0) {
    FUN_0046f847(s___fail_if_too_small_006c53c4,0xffffffff);
  }
  if (((byte)param_1[4] >> 1 & 1) != 0) {
    FUN_0046f847(s___use_neighbors_006c53b4,0xffffffff);
  }
  FUN_0046fa24(0x29);
  return;
}

