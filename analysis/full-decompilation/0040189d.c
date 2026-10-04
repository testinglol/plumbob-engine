
void FUN_0040189d(undefined4 *param_1,uint param_2)

{
  if (0x80 < param_2) {
    FUN_00634ecc(param_1);
    return;
  }
  FUN_004017b8();
  *param_1 = *(undefined4 *)(&DAT_006de560 + (param_2 + 7 >> 3) * 4);
  *(undefined4 **)(&DAT_006de560 + (param_2 + 7 >> 3) * 4) = param_1;
  DAT_006de5a4 = 0;
  return;
}

