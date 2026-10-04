
int * FUN_005e7b7d(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  int *piVar4;
  void *pvVar5;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar4 = (int *)(**(code **)(*extraout_ECX + 0x10))(0);
  iVar1 = *piVar4;
  uVar3 = FUN_005dfe3b(0xff,0,0xff);
  (**(code **)(iVar1 + 0x68))(uVar3);
  pvVar5 = operator_new(0x1ac);
  *(void **)(unaff_EBP + -0x10) = pvVar5;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar5 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_005f7201(piVar4);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (piVar4 != (int *)0x0) {
    uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
    piVar4[2] = *(int *)(unaff_EBP + 8);
    (**(code **)(*piVar4 + 0x9c))(uVar2);
    piVar4[0x3d] = 0;
    if (piVar4[0x21] - piVar4[0x1f] < 100) {
      FUN_004ec186(100);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar4;
}

