
undefined4 FUN_00537809(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *piVar4;
  int *extraout_ECX;
  int iVar5;
  int unaff_EBP;
  int *piVar6;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    cVar1 = FUN_005dbf32();
    if ((cVar1 == '\0') || (extraout_ECX[0x38] == 0)) {
      uVar2 = 0;
    }
    else {
      piVar6 = extraout_ECX + 0x35;
      iVar5 = 3;
      do {
        pvVar3 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x10) = pvVar3;
        piVar4 = (int *)0x0;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar3 != (void *)0x0) {
          piVar4 = (int *)FUN_005e372a();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *piVar6 = (int)piVar4;
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 0x19c))(extraout_ECX[0x38],6,1);
          FUN_005e4a3a(1);
          (**(code **)(*extraout_ECX + 0x20))(*piVar6);
        }
        piVar6 = piVar6 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      uVar2 = 1;
    }
  }
  else {
    uVar2 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

