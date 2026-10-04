
void FUN_004ea53c(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  void *pvVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  if (((DAT_006f2630 == 0) && (iVar1 = *(int *)(unaff_EBP + 8), -1 < iVar1)) &&
     (iVar1 < (DAT_006f264c - DAT_006f2648) / 0x44)) {
    iVar2 = FUN_004e9744(iVar1);
    if (iVar2 == 0) {
      FUN_004e978e(iVar1);
    }
    piVar3 = (int *)FUN_004e9744(iVar1);
    uVar4 = FUN_004e8a7a();
    *(undefined4 *)(unaff_EBP + 8) = uVar4;
    FUN_004e9c34(iVar1,&DAT_006f2638);
    pvVar5 = operator_new(0x98);
    *(void **)(unaff_EBP + -0x10) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar5 == (void *)0x0) {
      DAT_006f2630 = 0;
    }
    else {
      DAT_006f2630 = FUN_00408b9d();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00409377(*(undefined4 *)(unaff_EBP + 8),0);
    if (piVar3 != (int *)0x0) {
      FUN_0046f824(unaff_EBP + -0x50,0,0x40);
      *(undefined ***)(unaff_EBP + -0x5c) = &PTR_FUN_0066651c;
      FUN_0046f847(s_design_a_person_006c9e20,0xffffffff);
      uVar4 = FUN_00402246(unaff_EBP + -0x5c);
      if ((short)uVar4 == 0) {
        FUN_0044582f((int)(short)piVar3[0x3c],1,0);
      }
      else {
        (**(code **)(*piVar3 + 0x34))(piVar3,0,uVar4,0);
      }
    }
    uVar4 = FUN_004425e2();
    FUN_0046d7b3(uVar4);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

