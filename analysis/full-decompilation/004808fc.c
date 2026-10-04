
void FUN_004808fc(short *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined2 extraout_var;
  char *pcVar2;
  
  FUN_0046fa24(0x28);
  FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0xc9,*param_1 + 1);
  FUN_0046f917(&DAT_006e54e8,0xffffffff);
  FUN_0046f847(&DAT_006c5894,0xffffffff);
  bVar1 = *(byte *)(param_1 + 3);
  if ((bVar1 & 1) == 0) {
    if ((bVar1 & 2) == 0) {
      if ((bVar1 & 4) == 0) goto LAB_00480977;
      pcVar2 = s_Room_Only_006c5868;
    }
    else {
      pcVar2 = s_Inside_Only_006c5874;
    }
  }
  else {
    pcVar2 = s_Outside_Only_006c5884;
  }
  FUN_0046f847(pcVar2,0xffffffff);
LAB_00480977:
  if ((*(byte *)(param_1 + 3) & 8) != 0) {
    FUN_0046f847(s_Relative_to__006c5858,0xffffffff);
    FUN_0047e457(*(undefined4 *)(param_2 + 0xc),CONCAT22(extraout_var,param_1[2]),
                 CONCAT22(extraout_var,param_1[1]),param_3,param_4);
  }
  FUN_0046fa24(0x29);
  return;
}

