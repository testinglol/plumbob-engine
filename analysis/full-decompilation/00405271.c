
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00405271(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined *puVar2;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  uVar1 = FUN_004ea800(*(undefined4 *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + 0xc) = uVar1;
  FUN_005d4956(&DAT_006de560);
  *(float *)(unaff_EBP + -0x10) = (float)*(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (0 < *(int *)(unaff_EBP + 0xc)) {
    *(float *)(unaff_EBP + -0x10) = *(float *)(unaff_EBP + -0x10) * _DAT_00666578;
  }
  uVar1 = __ftol();
  *(undefined4 *)(unaff_EBP + 0xc) = uVar1;
  FUN_0063b26a(uVar1,unaff_EBP + -0x20,10);
  FUN_005b8789(unaff_EBP + -0x20);
  if (*(float *)(unaff_EBP + -0x10) - (float)*(int *)(unaff_EBP + 0xc) == _DAT_0066657c) {
    puVar2 = &DAT_006c0e90;
  }
  else {
    puVar2 = &DAT_006c0e94;
  }
  FUN_005b8789(puVar2);
  FUN_005b86bd(unaff_EBP + -0x2c);
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}

