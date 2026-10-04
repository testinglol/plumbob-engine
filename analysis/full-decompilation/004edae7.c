
undefined4 FUN_004edae7(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int extraout_ECX;
  int *piVar4;
  int *piVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(extraout_ECX + 8);
  piVar5 = (int *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  if (iVar1 - *piVar5 >> 2 != 0) {
    do {
      iVar1 = *(int *)(*piVar5 + *(int *)(unaff_EBP + -0x14) * 4);
      *(int *)(unaff_EBP + -0x10) = iVar1;
      if (iVar1 != 0) {
        FUN_004ed447();
        FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x10));
      }
      iVar1 = *(int *)(extraout_ECX + 8);
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
    } while (*(uint *)(unaff_EBP + -0x14) < (uint)(iVar1 - *piVar5 >> 2));
  }
  FUN_0052ea87(*piVar5,*(undefined4 *)(extraout_ECX + 8));
  FUN_0046f8e4(*(undefined4 *)(unaff_EBP + 8));
  FUN_0046f8e4(*(undefined4 *)(unaff_EBP + 0xc));
  FUN_004de865(*(undefined4 *)(unaff_EBP + 8),&DAT_006c9f50);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0046f824(unaff_EBP + -0x13c,0,0x104);
  *(undefined ***)(unaff_EBP + -0x148) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x24c,0,0x104);
  *(undefined ***)(unaff_EBP + -600) = &PTR_FUN_006664e8;
  FUN_00410947(unaff_EBP + -600);
  FUN_0046f8e4(extraout_ECX + 0x1c);
  FUN_0046f917(unaff_EBP + -600,0xffffffff);
  while( true ) {
    iVar1 = FUN_004deaa1();
    if (iVar1 == 0) break;
    uVar2 = FUN_004deaa1();
    iVar1 = FUN_0046f990(uVar2,*(undefined2 *)(unaff_EBP + -0x140));
    if (iVar1 == 0) {
      iVar1 = (*(code *)PTR_FUN_006d7060)(uVar2,s__thumb_jpg_006c83cc);
      if (iVar1 == 0) {
        FUN_005d4956(uVar2);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_004054fa(unaff_EBP + -0x38);
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_005b8770();
        uVar2 = FUN_004ede68(uVar2);
        *(undefined4 *)(unaff_EBP + 8) = uVar2;
        FUN_0042eab4(unaff_EBP + 8);
        iVar1 = *(int *)(unaff_EBP + 8) + 1;
        piVar5 = (int *)(extraout_ECX + 0x18);
        *(int *)(unaff_EBP + -0x10) = iVar1;
        piVar4 = (int *)(unaff_EBP + -0x10);
        if (iVar1 <= *piVar5) {
          piVar4 = piVar5;
        }
        *piVar5 = *piVar4;
      }
    }
    FUN_004de998();
  }
  FUN_004de865(*(undefined4 *)(unaff_EBP + 0xc),&PTR_LAB_006c9f4c);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  do {
    iVar1 = FUN_004deaa1();
    if (iVar1 == 0) {
      *(undefined4 *)(extraout_ECX + 0x10) = 0;
      *(undefined4 *)(extraout_ECX + 0x23c) = *(undefined4 *)(extraout_ECX + 0x18);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_004de981();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0048c4c9();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_004054b4();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004de981();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return 1;
    }
    uVar2 = FUN_004deaa1();
    *(undefined4 *)(unaff_EBP + 0xc) = uVar2;
    iVar1 = FUN_0046f990(uVar2,*(undefined2 *)(unaff_EBP + -0x140));
    if (iVar1 == 0) {
      iVar1 = FUN_004ede68(*(undefined4 *)(unaff_EBP + 0xc));
      piVar5 = *(int **)(unaff_EBP + -0x20);
      *(int *)(unaff_EBP + -0x10) = iVar1;
      if (piVar5 != *(int **)(unaff_EBP + -0x1c)) {
        do {
          if (*piVar5 == iVar1) break;
          piVar5 = piVar5 + 1;
        } while (piVar5 != *(int **)(unaff_EBP + -0x1c));
        if (piVar5 != *(int **)(unaff_EBP + -0x1c)) {
          pvVar3 = operator_new(0x34c);
          *(void **)(unaff_EBP + -0x14) = pvVar3;
          *(undefined1 *)(unaff_EBP + -4) = 5;
          if (pvVar3 == (void *)0x0) {
            iVar1 = 0;
          }
          else {
            iVar1 = FUN_004ed274();
          }
          *(undefined1 *)(unaff_EBP + -4) = 4;
          *(int *)(unaff_EBP + 8) = iVar1;
          if (iVar1 != 0) {
            FUN_0046f8cb(*(undefined4 *)
                          (*(int *)(unaff_EBP + -0x2c) +
                          ((int)piVar5 - *(int *)(unaff_EBP + -0x20) >> 2) * 0xc));
            FUN_0046f8cb(*(undefined4 *)(unaff_EBP + 0xc));
            uVar2 = *(undefined4 *)(unaff_EBP + -0x10);
            **(undefined4 **)(unaff_EBP + 8) = 2;
            *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x348) = uVar2;
            FUN_004ee1ee(unaff_EBP + 8);
          }
        }
      }
    }
    FUN_004de998();
  } while( true );
}

