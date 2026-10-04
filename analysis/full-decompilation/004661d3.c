
undefined4 FUN_004661d3(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar6;
  
  FUN_00634c24();
  FUN_005c171f(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b870f(*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 4));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if ((undefined4 *)(extraout_ECX + 0x10) == (undefined4 *)0x0) {
    piVar6 = (int *)0x0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0xffffffff;
  }
  else {
    piVar6 = *(int **)(extraout_ECX + 0x10);
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
  }
LAB_0046621b:
  if (piVar6 == (int *)0x0) goto LAB_00466223;
  iVar2 = *piVar6;
  do {
    if (iVar2 == 0) {
      FUN_005c22bb();
      pvVar4 = operator_new(0x20);
      *(void **)(unaff_EBP + -0x10) = pvVar4;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      if (pvVar4 == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_005c32ce();
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
      iVar2 = FUN_005c1b28(uVar3,*(undefined4 *)(extraout_ECX + 0xc),unaff_EBP + 8,
                           *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 4),1);
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
      uVar3 = FUN_00465fd2(uVar3,uVar5,*(undefined4 *)(unaff_EBP + 0x10));
LAB_004662ee:
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0042004f();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar3;
    }
    uVar3 = FUN_004818cc(unaff_EBP + -0x28);
    cVar1 = FUN_004317d5(uVar3);
    if (cVar1 != '\0') {
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
        uVar3 = *(undefined4 *)(iVar2 + 4);
        goto LAB_004662ee;
      }
    }
    if (piVar6 != (int *)0x0) break;
LAB_00466223:
    iVar2 = 0;
  } while( true );
  piVar6 = (int *)piVar6[1];
  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
  goto LAB_0046621b;
}

