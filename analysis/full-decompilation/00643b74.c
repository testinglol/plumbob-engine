
uint FUN_00643b74(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_7c [120];
  
  uVar1 = FUN_00643e17(param_1);
  iVar2 = (*DAT_00703c48)(uVar1,(-(uint)(DAT_00703c2c != 0) & 0xfffff005) + 0x1002,local_7c,0x78);
  if (iVar2 == 0) {
    DAT_00703c40 = 0;
    uVar3 = 1;
  }
  else {
    iVar2 = FUN_00646330(DAT_00703c3c,local_7c);
    if (iVar2 == 0) {
      iVar2 = FUN_00643c7a(uVar1);
      if (iVar2 != 0) {
        DAT_00703c40 = DAT_00703c40 | 4;
        DAT_00703c28 = uVar1;
        DAT_00703c44 = uVar1;
      }
    }
    uVar3 = ~DAT_00703c40 >> 2 & 1;
  }
  return uVar3;
}

