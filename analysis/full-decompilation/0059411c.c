
undefined4 FUN_0059411c(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_208 [256];
  undefined1 local_108 [256];
  int local_8;
  
  cVar1 = FUN_005b9095(&local_8);
  if (cVar1 == '\0') {
LAB_00594192:
    uVar2 = 0;
  }
  else {
    iVar3 = 0;
    if (0 < local_8) {
      do {
        cVar1 = FUN_005b90c2(local_208,0x100);
        if ((cVar1 == '\0') || (cVar1 = FUN_005b90c2(local_108,0x100), cVar1 == '\0'))
        goto LAB_00594192;
        FUN_00594331(local_208,local_108);
        iVar3 = iVar3 + 1;
      } while (iVar3 < local_8);
    }
    uVar2 = 1;
  }
  return uVar2;
}

