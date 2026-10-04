
int __fastcall FUN_00435968(int param_1)

{
  byte bVar1;
  int iStack_8;
  
  bVar1 = *(byte *)(param_1 + 100) & 5;
  if (bVar1 == 1) {
    iStack_8 = 2;
  }
  else {
    if (bVar1 != 4) {
      return 0;
    }
    iStack_8 = 8;
  }
  if (*(short *)(param_1 + 0x4c) != 0) {
    iStack_8 = *(int *)(&DAT_006f4620 +
                       (((int)*(short *)(param_1 + 0x4c) / 2) * 0x40 + iStack_8) * 4);
  }
  return iStack_8;
}

