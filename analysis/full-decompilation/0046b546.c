
undefined4 FUN_0046b546(void)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  piVar3 = (int *)(extraout_ECX + 0xac);
  iVar5 = *piVar3;
  *(undefined4 *)(unaff_EBP + -0x14) = 0xffffff06;
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  if (iVar5 != 0) {
    *(int **)(unaff_EBP + -0x18) = piVar3;
    do {
      iVar5 = *piVar3;
      if (iVar5 == 1) {
        pvVar2 = operator_new(0x30);
        *(void **)(unaff_EBP + -0x1c) = pvVar2;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar2 == (void *)0x0) {
LAB_0046b5de:
          piVar3 = (int *)0x0;
        }
        else {
          piVar3 = (int *)FUN_00416ebe();
        }
LAB_0046b5e0:
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (piVar3 != (int *)0x0) {
          FUN_0046f824(unaff_EBP + -0x120,0,0x104);
          *(undefined ***)(unaff_EBP + -300) = &PTR_FUN_006664e8;
          FUN_0046f8e4(*(undefined4 *)(unaff_EBP + 8));
          iVar5 = -0xfa;
          cVar1 = FUN_0046b115(unaff_EBP + -300,*(undefined4 *)(unaff_EBP + -0x18));
          if (cVar1 == '\0') {
LAB_0046b648:
            *(int *)(unaff_EBP + -0x14) = iVar5;
          }
          else {
            iVar5 = (**(code **)(*piVar3 + 8))(unaff_EBP + -300);
            if (iVar5 != 0) goto LAB_0046b648;
            *(undefined1 *)(unaff_EBP + -0xd) = 1;
          }
          (**(code **)*piVar3)(1);
          if ((*(int *)(unaff_EBP + -0x14) == -0x5e) || (*(int *)(unaff_EBP + -0x14) == -0x2d))
          goto LAB_0046b67f;
        }
      }
      else {
        if (iVar5 == 2) {
          pvVar2 = operator_new(0x2c);
          *(void **)(unaff_EBP + -0x1c) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 1;
          if (pvVar2 == (void *)0x0) goto LAB_0046b5de;
          piVar3 = (int *)FUN_0041c1a9();
          goto LAB_0046b5e0;
        }
        if (iVar5 == 3) {
          pvVar2 = operator_new(0x18);
          *(void **)(unaff_EBP + -0x1c) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 2;
          if (pvVar2 == (void *)0x0) goto LAB_0046b5de;
          piVar3 = (int *)FUN_00465ba5();
          goto LAB_0046b5e0;
        }
      }
      piVar3 = (int *)(*(int *)(unaff_EBP + -0x18) + 0x18);
      *(int **)(unaff_EBP + -0x18) = piVar3;
    } while (*piVar3 != 0);
    if (*(char *)(unaff_EBP + -0xd) != '\0') {
      uVar4 = 0;
      goto LAB_0046b682;
    }
  }
LAB_0046b67f:
  uVar4 = *(undefined4 *)(unaff_EBP + -0x14);
LAB_0046b682:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

