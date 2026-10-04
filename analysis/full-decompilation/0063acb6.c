
uint FUN_0063acb6(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined4 local_8;
  
  if (param_1 < 0x100) {
    if (1 < DAT_006dae24) {
      uVar2 = FUN_0063cdac(param_1,8);
      return uVar2;
    }
    return (byte)PTR_DAT_006dac18[param_1 * 2] & 8;
  }
  local_8 = 0;
  uVar3 = (undefined1)param_1;
  uVar2 = param_1 >> 8;
  param_1 = CONCAT13(uVar3,CONCAT12((char)uVar2,(undefined2)param_1));
  if (DAT_0070513c != 0) {
    iVar1 = FUN_00645ea8(1,(int)&param_1 + 2,2,&local_8,DAT_00705124,DAT_00705344,1);
    if (((iVar1 != 0) && (local_8._2_2_ == 0)) && ((local_8 & 8) != 0)) {
      return 1;
    }
  }
  return 0;
}

