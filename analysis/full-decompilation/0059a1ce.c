
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0059a1ce(void)

{
  int *piVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 uVar4;
  int extraout_ECX;
  undefined4 *puVar5;
  int unaff_EBP;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  FUN_00634c24();
  uVar4 = _DAT_0066745c;
  iVar6 = *(int *)(extraout_ECX + 0x44);
  iVar8 = *(int *)(extraout_ECX + 0x40);
  *(undefined4 *)(unaff_EBP + -0x4c) = _DAT_0066745c;
  *(undefined4 *)(unaff_EBP + -0x38) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x3c) = uVar4;
  iVar7 = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(int *)(unaff_EBP + -0x2c) = (iVar6 - iVar8) / 0x18;
  uVar4 = FUN_00462bc9(unaff_EBP + -0x3c,unaff_EBP + -0x38,unaff_EBP + -0x4c);
  FUN_00462be8(uVar4);
  uVar4 = _DAT_00667458;
  *(undefined4 *)(unaff_EBP + -0x34) = _DAT_00667458;
  *(undefined4 *)(unaff_EBP + -0x50) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x48) = uVar4;
  uVar4 = FUN_00462bc9(unaff_EBP + -0x48,unaff_EBP + -0x50,unaff_EBP + -0x34);
  FUN_00462be8(uVar4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  if (0 < *(int *)(unaff_EBP + -0x2c)) {
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    do {
      iVar8 = iVar7 + *(int *)(extraout_ECX + 0x40);
      iVar6 = *(int *)(*(int *)(unaff_EBP + 8) + 0x10);
      *(int *)(unaff_EBP + -0x10) = iVar7 + *(int *)(extraout_ECX + 0x70);
      *(int *)(unaff_EBP + -0x44) = iVar8;
      iVar6 = *(int *)(iVar6 + *(int *)(unaff_EBP + -0x18) * 4);
      *(int *)(unaff_EBP + -0x40) = iVar6;
      if (iVar6 == 0) {
        piVar1 = *(int **)(*(int *)(unaff_EBP + 8) + 0xc);
        if (piVar1 == (int *)0x0) goto LAB_0059a29e;
        (**(code **)(*piVar1 + 0x18))();
        FUN_005c73b0();
        *(int *)(iVar8 + 0x14) = *(int *)(iVar8 + 0x14) + 1;
      }
      else if (*(int *)(iVar8 + 0x14) != *(int *)(iVar6 + 0x130)) {
LAB_0059a29e:
        cVar3 = FUN_0059a443();
        if (cVar3 == '\0') {
          if (*(char *)(unaff_EBP + 0xc) == '\0') {
            *(int *)(unaff_EBP + -0x30) = iVar6 + 0x4c;
            *(int *)(unaff_EBP + -0x28) = iVar6 + 0xc4;
          }
          else {
            *(undefined **)(unaff_EBP + -0x30) = &DAT_006f75d0;
            *(undefined **)(unaff_EBP + -0x28) = &DAT_006722b8;
          }
          FUN_0059a42e(unaff_EBP + -0x24);
          iVar6 = *(int *)(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          puVar5 = (undefined4 *)(unaff_EBP + -0xe4);
          *(undefined4 *)(unaff_EBP + -0x10) = 8;
          do {
            uVar4 = *(undefined4 *)(iVar6 + (*(uint *)(unaff_EBP + -0x20) & 1) * 0xc);
            *(undefined4 *)(unaff_EBP + -0x70) =
                 *(undefined4 *)(iVar6 + 4 + (*(uint *)(unaff_EBP + -0x20) >> 1 & 1) * 0xc);
            uVar2 = *(undefined4 *)(iVar6 + 8 + (*(uint *)(unaff_EBP + -0x20) >> 2 & 1) * 0xc);
            puVar5[-2] = uVar4;
            *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
            *(undefined4 *)(unaff_EBP + -0x6c) = uVar2;
            puVar5[-1] = *(undefined4 *)(unaff_EBP + -0x70);
            *puVar5 = *(undefined4 *)(unaff_EBP + -0x6c);
            puVar5 = puVar5 + 3;
            piVar1 = (int *)(unaff_EBP + -0x10);
            *piVar1 = *piVar1 + -1;
          } while (*piVar1 != 0);
          FUN_005a6f40(0xc);
          FUN_005a6f60(0xc);
          FUN_005a6ef0(*(undefined4 *)(unaff_EBP + -0x28));
          FUN_005a6ec0(*(undefined4 *)(unaff_EBP + -0x30));
          FUN_005a8130(6,8,unaff_EBP + -0xec,unaff_EBP + -0x14c);
          FUN_005c74c0(8,0xc);
          *(undefined1 *)(unaff_EBP + -4) = 0;
          iVar6 = *(int *)(unaff_EBP + -0x40);
          iVar8 = *(int *)(unaff_EBP + -0x44);
        }
        uVar4 = *(undefined4 *)(iVar6 + 0x130);
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        *(undefined4 *)(iVar8 + 0x14) = uVar4;
      }
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 0x18;
      if (*(int *)(unaff_EBP + -0x2c) <= *(int *)(unaff_EBP + -0x18)) goto code_r0x0059a3cd;
      iVar7 = *(int *)(unaff_EBP + -0x1c);
    } while( true );
  }
LAB_0059a409:
  bVar9 = *(int *)(unaff_EBP + -0x14) == 0;
LAB_0059a40d:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return !bVar9;
code_r0x0059a3cd:
  bVar9 = true;
  if (*(int *)(unaff_EBP + -0x14) == 0) goto LAB_0059a40d;
  cVar3 = FUN_0059a443();
  if (cVar3 == '\0') {
    *(undefined4 *)(extraout_ECX + 0x94) = *(undefined4 *)(unaff_EBP + -0x68);
    *(undefined4 *)(extraout_ECX + 0x98) = *(undefined4 *)(unaff_EBP + -100);
    *(undefined4 *)(extraout_ECX + 0x9c) = *(undefined4 *)(unaff_EBP + -0x60);
    *(undefined4 *)(extraout_ECX + 0xa0) = *(undefined4 *)(unaff_EBP + -0x5c);
    *(undefined4 *)(extraout_ECX + 0xa4) = *(undefined4 *)(unaff_EBP + -0x58);
    *(undefined4 *)(extraout_ECX + 0xa8) = *(undefined4 *)(unaff_EBP + -0x54);
  }
  goto LAB_0059a409;
}

