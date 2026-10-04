
bool FUN_0063ae4f(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 local_8;
  
  if (param_1 < 0x100) {
    return (*(byte *)((int)&DAT_00705240 + param_1 + 1) & 0x20) == 0x20;
  }
  local_8 = 0;
  uVar3 = (undefined1)param_1;
  uVar1 = param_1 >> 8;
  param_1 = CONCAT13(uVar3,CONCAT12((char)uVar1,(undefined2)param_1));
  if (DAT_0070513c != 0) {
    iVar2 = FUN_00645ea8(1,(int)&param_1 + 2,2,&local_8,DAT_00705124,DAT_00705344,1);
    if (((iVar2 != 0) && (local_8._2_2_ == 0)) && ((local_8 & 2) != 0)) {
      return true;
    }
  }
  return false;
}

