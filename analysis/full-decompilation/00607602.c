
undefined4 FUN_00607602(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar6;
  int iStack_48;
  int iStack_44;
  
  FUN_00634c24();
  iStack_44 = unaff_EBP + -0x24;
  iStack_48 = 0x607621;
  (**(code **)(*(int *)(extraout_ECX + 0x28) + 0x38))();
  *(undefined1 *)(extraout_ECX + 0x8d) = 1;
  do {
    if (*(char *)(extraout_ECX + 0x8c) != '\0') {
      iStack_48 = unaff_EBP + -0x38;
      (**(code **)(*(int *)(extraout_ECX + 0x28) + 0x38))();
      *(undefined1 *)(extraout_ECX + 0x8d) = 0;
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return 0;
    }
    iStack_48 = unaff_EBP + -0xe;
    FUN_006078bf();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    while ((int *)**(int **)(extraout_ECX + 4) != *(int **)(extraout_ECX + 4)) {
      if (*(char *)(extraout_ECX + 0x8c) != '\0') goto LAB_00607807;
      iStack_48 = 0x607665;
      FUN_0060790d();
      iStack_48 = 0x607670;
      (**(code **)(*(int *)(extraout_ECX + 0x44) + 4))();
      iStack_48 = 0x607678;
      uVar4 = FUN_005fd8ea();
      piVar6 = (int *)(extraout_ECX + 4);
      *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
      piVar1 = (int *)*piVar6;
      piVar2 = (int *)*piVar1;
      *(int **)(unaff_EBP + -0x14) = piVar2;
      *(int *)(unaff_EBP + -0x18) = piVar2[7];
      if (piVar2 != piVar1) {
        do {
          iStack_48 = *(int *)(unaff_EBP + -0x14) + 8;
          *(int *)(unaff_EBP + -0x24) = iStack_48;
          if (*(uint *)(*(int *)(unaff_EBP + -0x14) + 0x20) <= *(uint *)(unaff_EBP + -0x20)) {
            FUN_0060784f();
            iVar5 = *(int *)(unaff_EBP + -0x24);
            if (*(int *)(iVar5 + 4) != 0) {
              iStack_48 = 0x6076bc;
              FUN_005ed902();
              iVar5 = *(int *)(unaff_EBP + -0x24);
            }
            if (*(char *)(iVar5 + 0x10) == '\0') {
              if (*(char *)(iVar5 + 0x1c) == '\0') {
                *(int *)(iVar5 + 0x18) = *(int *)(iVar5 + 0x18) + *(int *)(iVar5 + 0x14);
              }
              else {
                *(int *)(iVar5 + 0x18) = *(int *)(iVar5 + 0x14) + *(int *)(unaff_EBP + -0x20);
              }
            }
            else {
              iStack_48 = *(int *)(unaff_EBP + -0x14);
              *(int **)(unaff_EBP + -0x28) = &iStack_48;
              FUN_0060786f(unaff_EBP + -0x2c);
              *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)*piVar6;
            }
          }
          iVar5 = *(int *)(*(int *)(unaff_EBP + -0x24) + 0x18) - *(int *)(unaff_EBP + -0x20);
          if (iVar5 < *(int *)(unaff_EBP + -0x18)) {
            *(int *)(unaff_EBP + -0x18) = iVar5;
          }
          iVar3 = **(int **)(unaff_EBP + -0x14);
          iVar5 = *piVar6;
          *(int *)(unaff_EBP + -0x14) = iVar3;
        } while (iVar3 != iVar5);
      }
      iVar5 = *(int *)(extraout_ECX + 0x44);
      *(bool *)(unaff_EBP + -0xd) = *(int **)*piVar6 == (int *)*piVar6;
      iStack_48 = 0x607728;
      (**(code **)(iVar5 + 8))();
      iVar5 = *(int *)(extraout_ECX + 0x68);
      *(int **)(unaff_EBP + -0x3c) = (int *)(extraout_ECX + 0x68);
      *(undefined ***)(unaff_EBP + -0x40) = &PTR_LAB_00669c88;
      iStack_48 = 0x60773d;
      (**(code **)(iVar5 + 4))();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      piVar6 = (int *)**(int **)(unaff_EBP + -0x1c);
      if (piVar6 != *(int **)(unaff_EBP + -0x1c)) {
        do {
          if (piVar6[3] != 0) {
            iStack_48 = 0x607756;
            iVar5 = FUN_005ed902();
            if (2 < iVar5) {
              iStack_48 = piVar6[5];
              (*(code *)piVar6[4])();
            }
            iStack_48 = 0x60776a;
            FUN_005ed911();
            iStack_48 = 0x607772;
            FUN_005ed911();
          }
          piVar6 = (int *)*piVar6;
        } while (piVar6 != (int *)*(int *)(unaff_EBP + -0x1c));
      }
      iVar5 = *(int *)(extraout_ECX + 0x68);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      *(undefined ***)(unaff_EBP + -0x40) = &PTR_LAB_00669c88;
      iStack_48 = 0x60778b;
      (**(code **)(iVar5 + 8))();
      if ((*(char *)(unaff_EBP + -0xd) == '\0') && (*(char *)(extraout_ECX + 0x8c) == '\0')) {
        iStack_48 = 0x6077aa;
        iVar5 = FUN_005fd8ea();
        iStack_48 = *(int *)(unaff_EBP + -0x18) - (iVar5 - *(int *)(unaff_EBP + -0x20));
        if (iStack_48 < 0) {
          *(undefined4 *)(unaff_EBP + -0x18) = 0;
          iStack_48 = *(int *)(unaff_EBP + -0x18);
        }
        iStack_48 = iStack_48 * 1000;
        (**(code **)(*(int *)(extraout_ECX + 0x28) + 0x18))();
        (**(code **)(*(int *)(extraout_ECX + 0x28) + 0x38))(unaff_EBP + -0x30);
      }
    }
    if (*(char *)(extraout_ECX + 0x8c) == '\0') {
      iStack_48 = unaff_EBP + -0x34;
      (**(code **)(*(int *)(extraout_ECX + 0x28) + 0x38))();
      (**(code **)(*(int *)(extraout_ECX + 0x28) + 0x10))();
      (**(code **)(*(int *)(extraout_ECX + 0x28) + 0x38))(unaff_EBP + -0x38);
    }
LAB_00607807:
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iStack_48 = 0x607813;
    FUN_006078d9();
  } while( true );
}

