
undefined4 FUN_0046b693(void)

{
  undefined4 *puVar1;
  char cVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 uVar5;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = 0xffffff06;
  (**(code **)(*extraout_ECX + 0x18))();
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  piVar4 = extraout_ECX + 0x2b;
  if (extraout_ECX[0x2b] != 0) {
    *(int **)(unaff_EBP + -0x14) = piVar4;
    do {
      iVar6 = *piVar4;
      if (iVar6 == 1) {
        pvVar3 = operator_new(0x30);
        *(void **)(unaff_EBP + -0x1c) = pvVar3;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar3 == (void *)0x0) {
LAB_0046b737:
          piVar4 = (int *)0x0;
        }
        else {
          piVar4 = (int *)FUN_00416ebe();
        }
LAB_0046b739:
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (piVar4 != (int *)0x0) {
          FUN_0046f824(unaff_EBP + -0x120,0,0x104);
          *(undefined ***)(unaff_EBP + -300) = &PTR_FUN_006664e8;
          FUN_0046f8e4(*(undefined4 *)(unaff_EBP + 8));
          iVar6 = -0xfa;
          cVar2 = FUN_0046b115(unaff_EBP + -300,*(undefined4 *)(unaff_EBP + -0x14));
          if (cVar2 != '\0') {
            iVar6 = (**(code **)(*piVar4 + 0xc))(unaff_EBP + -300,*(undefined4 *)(unaff_EBP + 0xc));
            if (iVar6 == 0) {
              FUN_00406635(piVar4);
              *(undefined1 *)(unaff_EBP + -0xd) = 1;
              goto LAB_0046b7be;
            }
          }
          puVar1 = (undefined4 *)*piVar4;
          *(int *)(unaff_EBP + -0x18) = iVar6;
          (*(code *)*puVar1)(1);
        }
      }
      else {
        if (iVar6 == 2) {
          pvVar3 = operator_new(0x2c);
          *(void **)(unaff_EBP + -0x1c) = pvVar3;
          *(undefined4 *)(unaff_EBP + -4) = 1;
          if (pvVar3 == (void *)0x0) goto LAB_0046b737;
          piVar4 = (int *)FUN_0041c1a9();
          goto LAB_0046b739;
        }
        if (iVar6 == 3) {
          pvVar3 = operator_new(0x18);
          *(void **)(unaff_EBP + -0x1c) = pvVar3;
          *(undefined4 *)(unaff_EBP + -4) = 2;
          if (pvVar3 == (void *)0x0) goto LAB_0046b737;
          piVar4 = (int *)FUN_00465ba5();
          goto LAB_0046b739;
        }
      }
LAB_0046b7be:
      piVar4 = (int *)(*(int *)(unaff_EBP + -0x14) + 0x18);
      *(int **)(unaff_EBP + -0x14) = piVar4;
    } while (*piVar4 != 0);
    if (*(char *)(unaff_EBP + -0xd) != '\0') {
      uVar5 = 0;
      goto LAB_0046b7df;
    }
  }
  uVar5 = *(undefined4 *)(unaff_EBP + -0x18);
LAB_0046b7df:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar5;
}

