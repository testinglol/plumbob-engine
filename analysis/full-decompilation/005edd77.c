
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_005edd77(void)

{
  char cVar1;
  undefined1 uVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    cVar1 = FUN_005dbf32();
    uVar2 = 0;
    if (cVar1 != '\0') {
      if (extraout_ECX[0x37] != 0) {
        *(undefined1 *)((int)extraout_ECX + 0x1b1) = 0;
        FUN_005dadff(extraout_ECX,extraout_ECX[0x3a],0);
      }
      extraout_ECX[0x35] = 0;
      InitializeCriticalSection((LPCRITICAL_SECTION)(extraout_ECX + 0x4e));
      InitializeCriticalSection((LPCRITICAL_SECTION)(extraout_ECX + 0x6f));
      FUN_004734bd(_DAT_00666c18,_DAT_00666c18,0,DAT_006e5490);
      FUN_004734bd(0x3f800000,0x3f800000,0,DAT_006e5490);
      FUN_005ddda7();
      FUN_005db0b7();
      pvVar3 = operator_new(0x20);
      *(void **)(unaff_EBP + -0x10) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar3 == (void *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = (undefined4 *)FUN_005ed88f();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x75] = (int)puVar4;
      if (puVar4 != (undefined4 *)0x0) {
        (**(code **)*puVar4)(0xfa);
        (**(code **)(*(int *)extraout_ECX[0x75] + 0x20))(&LAB_005eea52,extraout_ECX);
        (**(code **)(*(int *)extraout_ECX[0x75] + 0x10))(1000);
      }
      uVar2 = 1;
    }
  }
  else {
    uVar2 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

