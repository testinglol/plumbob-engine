
void FUN_00603c04(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int extraout_ECX;
  int *piVar6;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_LAB_00669c88;
  iVar5 = *(int *)(extraout_ECX + 0xac);
  piVar6 = (int *)(extraout_ECX + 0xac);
  *(int **)(unaff_EBP + -0x18) = piVar6;
  (**(code **)(iVar5 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 0x98) = 0;
  *(undefined4 *)(extraout_ECX + 0x90) = 0;
  *(undefined4 *)(extraout_ECX + 0x9c) = 0;
  *(undefined4 *)(extraout_ECX + 0x94) = 0;
  FUN_005772e2();
  uVar2 = *(uint *)(extraout_ECX + 0x7c);
  *(uint *)(unaff_EBP + -0x10) = uVar2;
  if (uVar2 != 0) {
    if (10 < uVar2) {
      *(undefined4 *)(unaff_EBP + -0x10) = 10;
    }
    piVar1 = (int *)(extraout_ECX + 0x84);
    FUN_00601485(unaff_EBP + -0x14,*(int *)(extraout_ECX + 0x84) + 0x10);
    iVar5 = *(int *)(unaff_EBP + -0x14);
    iVar3 = *(int *)(extraout_ECX + 0x78);
    *piVar1 = iVar5;
    if (iVar5 == iVar3) {
      *piVar1 = *(int *)(iVar3 + 8);
    }
    if (*(int *)(unaff_EBP + -0x10) != 0) {
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10);
      do {
        piVar6 = *(int **)(*piVar1 + 0x14);
        cVar4 = (**(code **)(*piVar6 + 0x24))();
        if (cVar4 == '\0') {
          iVar5 = (**(code **)(*piVar6 + 0xc0))();
          if (iVar5 < 8) {
            (**(code **)(*piVar6 + 100))();
          }
        }
        FUN_0041674f();
        iVar5 = *(int *)(extraout_ECX + 0x78);
        if (*piVar1 == iVar5) {
          *piVar1 = *(int *)(iVar5 + 8);
        }
        piVar6 = (int *)(unaff_EBP + -0x10);
        *piVar6 = *piVar6 + -1;
      } while (*piVar6 != 0);
      piVar6 = *(int **)(unaff_EBP + -0x18);
    }
  }
  iVar5 = *piVar6;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar5 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

