
undefined4 FUN_0063afe3(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 local_8;
  
  uVar3 = (undefined1)param_1;
  if (param_1 < 0x100) {
    if (((*(ushort *)(&DAT_006dac22 + (param_1 & 0xff) * 2) & 0x103) != 0) ||
       ((*(byte *)((int)&DAT_00705240 + (param_1 & 0xff) + 1) & 1) != 0)) {
      return 1;
    }
  }
  else {
    local_8 = 0;
    uVar1 = param_1 >> 8;
    param_1 = CONCAT13(uVar3,CONCAT12((char)uVar1,(undefined2)param_1));
    if ((((DAT_0070513c != 0) &&
         (iVar2 = FUN_00645ea8(1,(int)&param_1 + 2,2,&local_8,DAT_00705124,DAT_00705344,1),
         iVar2 != 0)) && (local_8._2_2_ == 0)) && ((local_8 & 0x103) != 0)) {
      return 1;
    }
  }
  return 0;
}

