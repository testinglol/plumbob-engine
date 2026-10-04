
uint FUN_0055d0ab(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined1 uVar6;
  uint uVar7;
  undefined4 uVar8;
  int extraout_ECX;
  int unaff_EBP;
  
  uVar7 = FUN_00634c24();
  if (*(int **)(extraout_ECX + 0x5c) != (int *)0x0) {
    uVar7 = (**(code **)(**(int **)(extraout_ECX + 0x5c) + 0x20))(1);
    if ((char)uVar7 != '\0') {
      if (*(char *)(extraout_ECX + 0x121) == '\0') {
        FUN_0055d7e7();
        if (*(int **)(extraout_ECX + 0x13c) != (int *)0x0) {
          uVar8 = (**(code **)(**(int **)(extraout_ECX + 0x13c) + 0x1c))();
          *(undefined4 *)(unaff_EBP + -0x1c) = uVar8;
          iVar1 = **(int **)(extraout_ECX + 0x13c);
          uVar8 = FUN_005dd5e1(0x1e,0x1e,0x1e);
          (**(code **)(iVar1 + 0x20))(uVar8);
          iVar1 = **(int **)(extraout_ECX + 0x13c);
          uVar8 = FUN_005d49d6();
          uVar8 = FUN_004096c2(uVar8);
          (**(code **)(iVar1 + 0x50))(unaff_EBP + -0x44,uVar8);
          iVar1 = *(int *)(unaff_EBP + -0x38);
          iVar2 = *(int *)(extraout_ECX + 0x144);
          iVar3 = *(int *)(unaff_EBP + -0x40);
          *(int *)(unaff_EBP + -0x10) =
               (*(int *)(extraout_ECX + 0x140) -
               (*(int *)(unaff_EBP + -0x3c) - *(int *)(unaff_EBP + -0x44)) / 2) + 0x192;
          *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(extraout_ECX + 0x5c);
          iVar4 = **(int **)(extraout_ECX + 0x13c);
          *(int **)(unaff_EBP + -0x18) = *(int **)(extraout_ECX + 0x13c);
          uVar8 = FUN_005d49d6(0,0,0);
          uVar8 = FUN_004096c2(uVar8);
          (**(code **)(iVar4 + 0x78))
                    (*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x10),
                     (iVar2 - (iVar1 - iVar3) / 2) + 0xc,uVar8);
          (**(code **)(**(int **)(extraout_ECX + 0x13c) + 0x20))(*(undefined4 *)(unaff_EBP + -0x1c))
          ;
          iVar1 = *(int *)(unaff_EBP + -0x38);
          iVar2 = *(int *)(extraout_ECX + 0x144);
          iVar3 = *(int *)(unaff_EBP + -0x40);
          *(int *)(unaff_EBP + -0x1c) =
               (*(int *)(extraout_ECX + 0x140) -
               (*(int *)(unaff_EBP + -0x3c) - *(int *)(unaff_EBP + -0x44)) / 2) + 400;
          *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(extraout_ECX + 0x5c);
          iVar4 = **(int **)(extraout_ECX + 0x13c);
          *(int **)(unaff_EBP + -0x14) = *(int **)(extraout_ECX + 0x13c);
          uVar8 = FUN_005d49d6(0,0,0);
          uVar8 = FUN_004096c2(uVar8);
          (**(code **)(iVar4 + 0x78))
                    (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x1c),
                     (iVar2 - (iVar1 - iVar3) / 2) + 10,uVar8);
        }
      }
      else {
        uVar6 = FUN_0042a8d9(unaff_EBP + -0x28,10);
        (*(code *)PTR_FUN_006d7008)(uVar6);
        uVar8 = FUN_005d4956(unaff_EBP + -0x28);
        *(undefined4 *)(unaff_EBP + -0x1c) = uVar8;
        piVar5 = *(int **)(extraout_ECX + 0x13c);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        iVar1 = *piVar5;
        uVar8 = FUN_005d49d6();
        uVar8 = FUN_004096c2(uVar8);
        (**(code **)(iVar1 + 0x50))(unaff_EBP + -0x54,uVar8);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        iVar2 = *(int *)(extraout_ECX + 0x138);
        iVar1 = (*(int *)(iVar2 + 0x1c) - *(int *)(iVar2 + 0x14)) / 2 + -1 + DAT_006f5840;
        iVar2 = (*(int *)(iVar2 + 0x20) - *(int *)(iVar2 + 0x18)) / 2 + -1 + DAT_006f5844;
        FUN_005d4956(unaff_EBP + -0x28);
        *(undefined4 *)(unaff_EBP + -4) = 1;
        *(int *)(unaff_EBP + -0x1c) =
             iVar2 - (*(int *)(unaff_EBP + -0x48) - *(int *)(unaff_EBP + -0x50)) / 2;
        *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(extraout_ECX + 0x5c);
        *(int *)(unaff_EBP + -0x18) =
             iVar1 - (*(int *)(unaff_EBP + -0x4c) - *(int *)(unaff_EBP + -0x54)) / 2;
        iVar1 = **(int **)(extraout_ECX + 0x13c);
        uVar8 = FUN_005d49d6(0,0,0);
        uVar8 = FUN_004096c2(uVar8);
        (**(code **)(iVar1 + 0x78))
                  (*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x18),
                   *(undefined4 *)(unaff_EBP + -0x1c),uVar8);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
      }
      if (*(char *)(extraout_ECX + 0x100) != '\0') {
        FUN_0055df18();
      }
      if (*(int *)(extraout_ECX + 0x194) != 0) {
        FUN_0055d7e7();
      }
      uVar7 = (**(code **)(**(int **)(extraout_ECX + 0x5c) + 0x24))(1);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar7 & 0xffffff00;
}

