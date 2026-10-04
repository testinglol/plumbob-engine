
undefined4 __fastcall FUN_004bb700(int *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  byte bVar3;
  int iVar4;
  
  pvVar1 = operator_new(param_1[1] * 8 + 4);
  *param_1 = (int)pvVar1;
  if (pvVar1 == (void *)0x0) {
LAB_004bb775:
    uVar2 = 1;
  }
  else {
    iVar4 = 0;
    if (0 < param_1[1] * 2 + 1) {
      do {
        bVar3 = (byte)param_1[3] - 1;
        pvVar1 = _malloc(((0x3a << (bVar3 & 0x1f)) + (8 << ((byte)param_1[3] & 0x1f))) *
                         (0x10 << (bVar3 & 0x1f)));
        *(void **)(*param_1 + iVar4 * 4) = pvVar1;
        if (*(int *)(*param_1 + iVar4 * 4) == 0) {
          FUN_004bb6c5();
          goto LAB_004bb775;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_1[1] * 2 + 1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

