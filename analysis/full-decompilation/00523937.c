
void FUN_00523937(void)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (extraout_ECX[0x3c] == 0) {
    pvVar1 = operator_new(0x1b8);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_005f179a();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x3c] = iVar2;
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(unaff_EBP + 0xc);
      piVar3 = (int *)FUN_005e7743();
      piVar3 = (int *)(**(code **)(*piVar3 + 8))(0);
      FUN_005f42c3(piVar3);
      FUN_005f436c(**(undefined4 **)(unaff_EBP + 8),1,0);
      FUN_005f42b6(1);
      FUN_005f435f(0x40);
      (**(code **)(*(int *)extraout_ECX[0x3c] + 0x60))(0,0,100,100);
      uVar4 = (**(code **)(*piVar3 + 0x1c))();
      uVar5 = (**(code **)(*piVar3 + 0x1c))(uVar4);
      FUN_005f4256(DAT_006f2a54,uVar5,uVar4);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3c]);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

