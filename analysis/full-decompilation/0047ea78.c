
void FUN_0047ea78(byte *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined2 extraout_var;
  
  FUN_0046fa24(0x28);
  bVar1 = *param_1;
  if (bVar1 != 0) {
    FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0xef,
                 CONCAT22(extraout_var,(ushort)bVar1) + 1);
    FUN_0046f917(&DAT_006e54e8,0xffffffff);
  }
  if ((param_1[2] & 1) != 0) {
    if (bVar1 != 0) {
      FUN_0046f847(&DAT_006c25a8,0xffffffff);
    }
    FUN_0046f847(s_start_at_006c520c,0xffffffff);
    FUN_0047e457(*(undefined4 *)(param_2 + 0xc),0x19,param_1[1],param_3,param_4);
  }
  if ((param_1[2] & 4) != 0) {
    FUN_0046f847(s___user_editable_006c51fc,0xffffffff);
  }
  if ((~param_1[2] & 2) != 0) {
    FUN_0046f847(s___prefer_empty_006c51ec,0xffffffff);
  }
  FUN_0046fa24(0x29);
  return;
}

