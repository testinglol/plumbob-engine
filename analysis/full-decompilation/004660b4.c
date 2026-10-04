
undefined4 FUN_004660b4(void)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar6;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005c171f(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((undefined4 *)(extraout_ECX + 0x10) == (undefined4 *)0x0) {
    piVar6 = (int *)0x0;
    *(undefined4 *)(unaff_EBP + -0x18) = 0xffffffff;
  }
  else {
    piVar6 = *(int **)(extraout_ECX + 0x10);
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
  }
LAB_004660ea:
  if (piVar6 == (int *)0x0) goto LAB_004660f2;
  iVar2 = *piVar6;
  do {
    if (iVar2 == 0) {
      FUN_005c22bb();
      pvVar3 = operator_new(0x20);
      *(void **)(unaff_EBP + -0x14) = pvVar3;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (pvVar3 == (void *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = FUN_005c32ce();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      iVar2 = FUN_005c1c7f(uVar4,*(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc),unaff_EBP + 8,
                           (int)*(short *)(unaff_EBP + 0xc));
      if (iVar2 == 0) {
        uVar5 = 0;
      }
      else if (iVar2 == 5) {
        uVar5 = 0xffffff9e;
      }
      else if (iVar2 == 6) {
        uVar5 = 0xffffff38;
      }
      else {
        uVar5 = 0xffffffff;
      }
      uVar4 = FUN_00465fd2(uVar4,uVar5,*(undefined4 *)(unaff_EBP + 0x10));
LAB_004661b5:
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0042004f();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar4;
    }
    iVar2 = FUN_0060b844();
    if (iVar2 == *(short *)(unaff_EBP + 0xc)) {
      iVar2 = unaff_EBP + 8;
      FUN_005c3383(iVar2);
      cVar1 = FUN_005c17a6(iVar2);
      if (cVar1 != '\0') {
        if (piVar6 == (int *)0x0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *piVar6;
        }
        uVar4 = *(undefined4 *)(iVar2 + 4);
        goto LAB_004661b5;
      }
    }
    if (piVar6 != (int *)0x0) break;
LAB_004660f2:
    iVar2 = 0;
  } while( true );
  piVar6 = (int *)piVar6[1];
  *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
  goto LAB_004660ea;
}

