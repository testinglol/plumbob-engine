
undefined4 FUN_0046b365(void)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar6;
  int iVar7;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = 0xffffff06;
  puVar6 = (undefined4 *)(unaff_EBP + -0x41c);
  iVar7 = 0x10;
  do {
    FUN_0046f824(puVar6 + 3,0,0x20);
    *puVar6 = &PTR_FUN_006666e4;
    puVar6 = puVar6 + 0xb;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  piVar4 = (int *)(extraout_ECX + 0xac);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*piVar4 != 0) {
    *(int *)(unaff_EBP + -0x1c) = unaff_EBP + -0x41c;
    *(int **)(unaff_EBP + -0x14) = piVar4;
    do {
      iVar7 = 0;
      if (0 < *(int *)(unaff_EBP + -0x10)) {
        do {
          FUN_0046f824(unaff_EBP + -0x40,0,0x20);
          *(undefined ***)(unaff_EBP + -0x4c) = &PTR_FUN_006666e4;
          FUN_0046f8e4(piVar4 + 1);
          iVar2 = FUN_0046f973(unaff_EBP + -0x4c);
          if (iVar2 == 0) goto LAB_0046b516;
          iVar7 = iVar7 + 1;
        } while (iVar7 < *(int *)(unaff_EBP + -0x10));
      }
      iVar7 = **(int **)(unaff_EBP + -0x14);
      if (iVar7 == 1) {
        pvVar3 = operator_new(0x30);
        *(void **)(unaff_EBP + -0x20) = pvVar3;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar3 == (void *)0x0) {
LAB_0046b47e:
          piVar4 = (int *)0x0;
        }
        else {
          piVar4 = (int *)FUN_00416ebe();
        }
LAB_0046b480:
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (piVar4 != (int *)0x0) {
          FUN_0046f824(unaff_EBP + -0x150,0,0x104);
          *(undefined ***)(unaff_EBP + -0x15c) = &PTR_FUN_006664e8;
          FUN_0046f8e4(*(undefined4 *)(unaff_EBP + 8));
          iVar7 = *(int *)(unaff_EBP + -0x14);
          iVar2 = -0xfa;
          cVar1 = FUN_0046b115(unaff_EBP + -0x15c,iVar7);
          if (cVar1 == '\0') {
LAB_0046b4ee:
            *(int *)(unaff_EBP + -0x18) = iVar2;
          }
          else {
            iVar2 = (**(code **)(*piVar4 + 4))(unaff_EBP + -0x15c);
            if (iVar2 != 0) goto LAB_0046b4ee;
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
            *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 0x2c;
            FUN_0046f8e4(iVar7 + 4);
          }
          (**(code **)*piVar4)(1);
          uVar5 = 0xffffffd5;
          if (*(int *)(unaff_EBP + -0x18) == -0x2b) goto LAB_0046b535;
        }
      }
      else {
        if (iVar7 == 2) {
          pvVar3 = operator_new(0x2c);
          *(void **)(unaff_EBP + -0x20) = pvVar3;
          *(undefined4 *)(unaff_EBP + -4) = 1;
          if (pvVar3 == (void *)0x0) goto LAB_0046b47e;
          piVar4 = (int *)FUN_0041c1a9();
          goto LAB_0046b480;
        }
        if (iVar7 == 3) {
          pvVar3 = operator_new(0x18);
          *(void **)(unaff_EBP + -0x20) = pvVar3;
          *(undefined4 *)(unaff_EBP + -4) = 2;
          if (pvVar3 == (void *)0x0) goto LAB_0046b47e;
          piVar4 = (int *)FUN_00465ba5();
          goto LAB_0046b480;
        }
      }
LAB_0046b516:
      piVar4 = (int *)(*(int *)(unaff_EBP + -0x14) + 0x18);
      *(int **)(unaff_EBP + -0x14) = piVar4;
    } while (*piVar4 != 0);
    if (*(int *)(unaff_EBP + -0x10) != 0) {
      uVar5 = 0;
      goto LAB_0046b535;
    }
  }
  uVar5 = *(undefined4 *)(unaff_EBP + -0x18);
LAB_0046b535:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

