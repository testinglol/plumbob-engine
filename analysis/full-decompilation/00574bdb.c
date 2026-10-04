
undefined4 FUN_00574bdb(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffdc;
  iVar1 = FUN_00574d13();
  if (0xf < iVar1) {
    piVar2 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 8));
    iVar3 = (**(code **)(*piVar2 + 0x88))(0x19);
    if (iVar3 == 0) {
      uVar4 = 0;
      goto LAB_00574d02;
    }
    if (0x10 < iVar1) {
      (**(code **)(*(int *)(DAT_006f6a78 + 0x128) + 4))();
      FUN_0057584f(DAT_006f6a78 + 0x2c);
      iVar1 = DAT_006f6a78;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      (**(code **)(*(int *)(iVar1 + 0x128) + 8))();
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x20);
      while (*(int *)(unaff_EBP + 8) != *(int *)(unaff_EBP + -0x18)) {
        *(undefined1 *)(unaff_EBP + -4) = 2;
        piVar2 = (int *)**(undefined4 **)(unaff_EBP + 8);
        piVar5 = (int *)(**(code **)(*piVar2 + 0xac))();
        iVar1 = (**(code **)(*piVar5 + 0xb8))();
        if (iVar1 == 3) {
          iVar1 = (**(code **)(*piVar2 + 0x88))(0x7c);
          if (iVar1 < 0x400) {
            *(int **)(unaff_EBP + -0x14) = piVar2;
          }
        }
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 4;
        *(undefined4 *)(unaff_EBP + -4) = 1;
      }
      piVar2 = *(int **)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0xac))();
        (**(code **)(*piVar2 + 0x34))();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0048c4c9();
    }
  }
  uVar4 = 1;
LAB_00574d02:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

