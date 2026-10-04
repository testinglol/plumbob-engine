
uint FUN_00643a80(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_7c [120];
  
  uVar1 = FUN_00643e17(param_1);
  iVar2 = (*DAT_00703c48)(uVar1,(-(uint)(DAT_00703c34 != 0) & 0xfffff002) + 0x1001,local_7c,0x78);
  if (iVar2 == 0) {
    DAT_00703c40 = 0;
    return 1;
  }
  iVar2 = FUN_00646330(DAT_00703c38,local_7c);
  if (iVar2 == 0) {
    if (DAT_00703c34 == 0) {
      uVar3 = 1;
      goto LAB_00643b0c;
    }
  }
  else {
    if (((DAT_00703c34 != 0) || (DAT_00703c30 == 0)) ||
       (iVar2 = FUN_00646400(DAT_00703c38,local_7c,DAT_00703c30), iVar2 != 0)) goto LAB_00643b2b;
    uVar3 = 0;
LAB_00643b0c:
    iVar2 = FUN_00643c99(uVar1,uVar3);
    if (iVar2 == 0) goto LAB_00643b2b;
  }
  DAT_00703c40 = DAT_00703c40 | 4;
  DAT_00703c28 = uVar1;
  DAT_00703c44 = uVar1;
LAB_00643b2b:
  return ~DAT_00703c40 >> 2 & 1;
}

