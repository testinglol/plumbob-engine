
void FUN_0047ee5a(undefined1 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 extraout_var;
  uint uVar1;
  undefined2 extraout_var_00;
  undefined1 local_31c [256];
  undefined **local_21c;
  undefined1 local_210 [256];
  undefined **local_110;
  undefined1 local_104 [256];
  
  FUN_0046f824(local_210,0,0x100);
  local_21c = &PTR_FUN_00666524;
  FUN_0046f824(local_104,0,0x100);
  local_110 = &PTR_FUN_00666524;
  FUN_0046f824(local_31c,0,0x100);
  FUN_0046f847(&DAT_006c5334,0xffffffff);
  FUN_0046fa40(*param_1);
  FUN_0046f847(&DAT_006c532c,0xffffffff);
  uVar1 = CONCAT31((int3)(CONCAT22(extraout_var,(ushort)(byte)param_1[1]) >> 8),param_1[3]) &
          0xffffff02;
  FUN_0047e457(*(undefined4 *)(param_2 + 0xc),
               CONCAT22((short)(uVar1 >> 0x10),(ushort)(byte)uVar1) << 3 | 9,
               CONCAT22(extraout_var,(ushort)(byte)param_1[1]),param_3,param_4);
  FUN_0046f847(s_onto_the_stack_object_s_queue__006c5308,0xffffffff);
  FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0xe0,
               CONCAT22(extraout_var_00,(ushort)(byte)param_1[2]) + 1);
  FUN_0046f917(&DAT_006e54e8,0xffffffff);
  if ((param_1[3] & 1) != 0) {
    FUN_0046f847(s___use_icon_from_006c52f4,0xffffffff);
    FUN_0047e457(*(undefined4 *)(param_2 + 0xc),0x19,param_1[4],param_3,param_4);
  }
  if ((param_1[3] & 4) != 0) {
    FUN_0046f847(s___continue_as_current_006c52dc,0xffffffff);
  }
  if ((param_1[3] & 8) != 0) {
    FUN_0046f847(s___use_name_006c52d0,0xffffffff);
  }
  FUN_0046fa24(0x29);
  return;
}

