
void FUN_0047e94c(byte *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  
  FUN_0046fa24(0x28);
  if ((param_1[3] & 1) == 0) {
    FUN_0047e457(*(undefined4 *)(param_2 + 0xc),0xe,param_1[2],param_3,param_4);
    FUN_0046f847(&DAT_006c51d8,0xffffffff);
    FUN_0047e457(*(undefined4 *)(param_2 + 0xc),CONCAT22(extraout_var,(ushort)*param_1),
                 CONCAT22(extraout_var,*(undefined2 *)(param_1 + 4)),param_3,param_4);
    FUN_0046f847(s_per_hr__stop_at_006c51c4,0xffffffff);
    FUN_0047e457(*(undefined4 *)(param_2 + 0xc),CONCAT22(extraout_var_00,(ushort)param_1[1]),
                 CONCAT22(extraout_var_00,*(undefined2 *)(param_1 + 6)),param_3,param_4);
  }
  else {
    FUN_0046f847(s_clear_all_006c51e0,0xffffffff);
  }
  FUN_0046fa24(0x29);
  return;
}

