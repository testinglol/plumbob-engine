
undefined4 FUN_00425fb0(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = FUN_00401f73();
  cVar1 = FUN_00410285(uVar2);
  if (cVar1 == '\0') {
    uVar2 = FUN_00401f73();
    FUN_004108dc(uVar2);
    FUN_0042a2fe();
    uVar2 = FUN_00401f73();
    iVar3 = FUN_00410263(uVar2);
    if (iVar3 != 0) {
      uVar2 = FUN_00401f73();
      iVar3 = FUN_0044097d(uVar2);
      if (iVar3 != 0) {
        *(short *)(iVar3 + 0x606) = (short)*(undefined4 *)(param_2 + 0x10c);
        *(undefined2 *)(iVar3 + 0x612) = 0;
      }
      *(short *)(param_1 + 0xee) = (short)*(undefined4 *)(param_2 + 0x10c);
      *(undefined2 *)(param_1 + 0xfa) = 0;
      *(uint *)(param_2 + 0x138) = *(uint *)(param_2 + 0x138) & 0xfffffff7;
      *(undefined1 *)(param_2 + 0x124) = 1;
      FUN_0040766a(0xe8,0);
      return 0;
    }
  }
  return 0xffffffff;
}

