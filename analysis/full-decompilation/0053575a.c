
undefined1 FUN_0053575a(void)

{
  char cVar1;
  undefined1 uVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 uVar5;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    cVar1 = FUN_005dbf32();
    uVar2 = 0;
    if (cVar1 != '\0') {
      (**(code **)(*extraout_ECX + 0x174))(1,0);
      FUN_005ddfdc(1);
      (**(code **)(*extraout_ECX + 0x90))(4,1);
      (**(code **)(*extraout_ECX + 0x58))(1,0x80);
      FUN_005a5631(0x1e,unaff_EBP + -0x10,4);
      if (*(int **)(unaff_EBP + -0x10) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x68))(DAT_006f2a64);
        pvVar3 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x14) = pvVar3;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar3 == (void *)0x0) {
          piVar4 = (int *)0x0;
        }
        else {
          piVar4 = (int *)FUN_005e372a();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        extraout_ECX[0x3d] = (int)piVar4;
        (**(code **)(*piVar4 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x10),4,1);
        *(undefined1 *)(extraout_ECX[0x3d] + 0x16b) = 1;
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3d]);
      }
      uVar5 = FUN_005e74ca(0);
      FUN_005dde6d(uVar5);
      uVar2 = 1;
    }
  }
  else {
    uVar2 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

