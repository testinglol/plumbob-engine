
undefined1 FUN_005a4387(void)

{
  uint *puVar1;
  int iVar2;
  void *pvVar3;
  int extraout_ECX;
  undefined1 uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046f8e4(*(undefined4 *)(unaff_EBP + 8));
  FUN_00412122(extraout_ECX + 4,extraout_ECX + 0x114);
  FUN_0041308b();
  uVar4 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = FUN_004130d2(*(undefined4 *)(unaff_EBP + 8),0);
  if (iVar2 == 0) {
    puVar1 = (uint *)(extraout_ECX + 0x228);
    iVar2 = FUN_00412fc7(puVar1);
    if (iVar2 == 0) {
      FUN_004131a0(0);
      pvVar3 = operator_new(*puVar1);
      *(void **)(extraout_ECX + 0x224) = pvVar3;
      iVar2 = FUN_00413178(pvVar3,puVar1);
      if (iVar2 == 0) {
        *(undefined4 *)(extraout_ECX + 0x22c) = 0;
        *(undefined4 *)(extraout_ECX + 0x230) = 0;
        *(undefined4 *)(extraout_ECX + 0x234) = 0;
        *(undefined4 *)(extraout_ECX + 0x238) = 0;
        *(undefined4 *)(extraout_ECX + 0x23c) = 0;
        uVar4 = 1;
      }
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004130c0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

