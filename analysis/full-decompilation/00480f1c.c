
void FUN_00480f1c(short *param_1)

{
  short sVar1;
  
  FUN_0046fa24(0x28);
  FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0xcf,param_1[1] + 1);
  FUN_0046f917(&DAT_006e54e8,0xffffffff);
  sVar1 = param_1[1];
  if ((sVar1 == 0) || ((2 < sVar1 && (sVar1 < 5)))) {
    FUN_0046f847(&DAT_006c3d7c,0xffffffff);
    FUN_0046fa40((int)*param_1);
  }
  if ((*(byte *)(param_1 + 2) & 2) != 0) {
    FUN_0046f847(s___ask_person_to_move_006c5984,0xffffffff);
  }
  if ((*(byte *)(param_1 + 2) & 4) != 0) {
    FUN_0046f847(s___use_footprint_006c5974,0xffffffff);
  }
  FUN_0046fa24(0x29);
  return;
}

