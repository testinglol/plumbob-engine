
undefined4 FUN_00595963(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int extraout_ECX;
  int iVar4;
  int unaff_EBP;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  cVar1 = FUN_005b90c2(unaff_EBP + -300,0x100);
  iVar4 = 0;
  if (cVar1 != '\0') {
    uVar2 = FUN_005b870f(unaff_EBP + -300);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00595f2a(uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    cVar1 = FUN_005b90c2(unaff_EBP + -300,0x100);
    if (cVar1 != '\0') {
      uVar2 = FUN_005b870f(unaff_EBP + -300);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_005d499c(uVar2);
      *(int *)(extraout_ECX + 0x130) = *(int *)(extraout_ECX + 0x130) + 1;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      cVar1 = FUN_005b9095(unaff_EBP + -0x14);
      if (cVar1 != '\0') {
        FUN_00595f04(0);
        if (*(int *)(unaff_EBP + -0x14) != 0) {
          puVar3 = operator_new(0x10);
          if (puVar3 == (undefined4 *)0x0) {
            puVar3 = (undefined4 *)0x0;
          }
          else {
            *puVar3 = 0;
            puVar3[1] = 0;
            puVar3[2] = 0;
            puVar3[3] = 0;
          }
          cVar1 = FUN_0059411c(*(undefined4 *)(unaff_EBP + 8));
          if (cVar1 == '\0') {
            if (puVar3 != (undefined4 *)0x0) {
              FUN_00594235();
              FUN_006321f0(puVar3);
            }
            goto LAB_00595afb;
          }
          FUN_00595f04(puVar3);
        }
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
        iVar5 = extraout_ECX + 0x30;
        do {
          cVar1 = FUN_005b9095(iVar5);
          if (cVar1 == '\0') goto LAB_00595afb;
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
          iVar5 = iVar5 + 4;
        } while (*(int *)(unaff_EBP + -0x10) < 3);
        iVar5 = extraout_ECX + 0x3c;
        do {
          cVar1 = FUN_005b9095(iVar5);
          if (cVar1 == '\0') goto LAB_00595afb;
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 + 4;
        } while (iVar4 < 4);
        cVar1 = FUN_005b9095(extraout_ECX + 0x6c);
        if (cVar1 != '\0') {
          cVar1 = FUN_005b9095(extraout_ECX + 0x70);
          if (cVar1 != '\0') {
            cVar1 = FUN_005b9095(extraout_ECX + 0x74);
            if (cVar1 != '\0') {
              cVar1 = FUN_005b9095(extraout_ECX + 0x78);
              if (cVar1 != '\0') {
                cVar1 = FUN_005b9095(extraout_ECX + 0x7c);
                if (cVar1 != '\0') {
                  FUN_00595c10();
                  *(int *)(extraout_ECX + 0x130) = *(int *)(extraout_ECX + 0x130) + 1;
                  uVar2 = 1;
                  goto LAB_00595b0e;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_00595afb:
  uVar2 = 0;
LAB_00595b0e:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

