
void FUN_00480e69(short *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  
  FUN_0046fa24(0x28);
  FUN_0046f847(s_from_slot_006c5968,0xffffffff);
  if (*param_1 == 0) {
    FUN_0046fa40((int)param_1[1]);
  }
  else {
    FUN_0046f847(&DAT_006c54e4,0xffffffff);
    FUN_0047e457(*(undefined4 *)(param_2 + 0xc),9,CONCAT22(extraout_var,param_1[1]),param_3,param_4)
    ;
  }
  FUN_0046f847(s_to_slot_006c595c,0xffffffff);
  if (param_1[2] == 0) {
    FUN_0046fa40((int)param_1[3]);
  }
  else {
    FUN_0046f847(&DAT_006c54e4,0xffffffff);
    FUN_0047e457(*(undefined4 *)(param_2 + 0xc),9,CONCAT22(extraout_var_00,param_1[3]),param_3,
                 param_4);
  }
  FUN_0046fa24(0x29);
  return;
}

