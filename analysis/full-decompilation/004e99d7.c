
void FUN_004e99d7(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_004e8d71(param_1);
  if (*(int *)(*DAT_006e486c + 0x14) == 0) {
    return;
  }
  if ((iVar2 != 0) && (iVar2 = FUN_00440914(iVar2), iVar2 != 0)) {
    cVar1 = FUN_004074bc();
    if (cVar1 == '\x01') {
      if ((DAT_006e4f14 != 0) || (*(short *)(iVar2 + 0x5cc) == 0)) goto LAB_004e9a8e;
    }
    else {
      cVar1 = FUN_004074f7();
      if (cVar1 == '\x01') {
        if (DAT_006e4f14 != 0) goto LAB_004e9a8e;
      }
      else {
        cVar1 = FUN_0045e447();
        if (cVar1 == '\0') {
          return;
        }
        if ((DAT_006e4f14 != 0) ||
           ((int)*(short *)(iVar2 + 0x606) == *(int *)(*(int *)(*DAT_006e486c + 0x10) + 0x10c)))
        goto LAB_004e9a8e;
      }
      if (*(short *)(iVar2 + 0x5cc) != 2) goto LAB_004e9a8e;
    }
  }
  iVar2 = 0;
LAB_004e9a8e:
  FUN_00445489(iVar2);
  return;
}

