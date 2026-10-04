
void FUN_0048a1d1(void)

{
  undefined4 *puVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int iVar5;
  int unaff_EBP;
  undefined4 *puVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  FUN_00634c24();
  cVar2 = FUN_00484ba0(unaff_EBP + 8);
  if (cVar2 != '\0') goto LAB_0048a2a5;
  *(undefined4 *)(extraout_ECX + 0x40) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(extraout_ECX + 0x44) = *(undefined4 *)(unaff_EBP + 0xc);
  puVar1 = *(undefined4 **)(unaff_EBP + 0x14);
  puVar6 = puVar1;
  puVar7 = (undefined4 *)(extraout_ECX + 0x48);
  for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  *(undefined1 *)(extraout_ECX + 0x5c) = 0;
  if (*(int *)(extraout_ECX + 0x30) == 0) {
LAB_0048a37d:
    iVar5 = *(int *)(extraout_ECX + 0x30);
    if ((iVar5 != 0) && ((*(int *)(iVar5 + 0x28) - *(int *)(iVar5 + 0x24)) / 0x34 != 0)) {
      if ((*(int *)(extraout_ECX + 0x3c) != 1) && (*(int *)(extraout_ECX + 0x3c) != 3)) {
        FUN_0057a7f7(s_UI_bld_dragtool_mousedown_006c5f1c,0xfffffffc);
      }
      goto LAB_0048a2a5;
    }
  }
  else {
    puVar1 = puVar1 + 3;
    FUN_0048a829(unaff_EBP + 8,unaff_EBP + -0x10,puVar1);
    uVar4 = FUN_00492b26();
    *(undefined4 *)(unaff_EBP + 0x14) = uVar4;
    *(char *)(unaff_EBP + -0x14) = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
    *(char *)(unaff_EBP + -0x13) = (char)(*(int *)(unaff_EBP + 8) >> 4);
    *(char *)(unaff_EBP + -0x12) = (char)uVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar4 = FUN_0048a777();
    *(undefined4 *)(extraout_ECX + 0x3c) = uVar4;
    FUN_0048a9df(uVar4);
    FUN_0048a909(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                 *(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + -0x10),1);
    if (*(int *)(unaff_EBP + -0x10) != 0) {
      *(undefined4 *)(extraout_ECX + 0x60) = 0;
      FUN_004864ed(0,0xffffffff);
      FUN_00493875();
      iVar5 = *(int *)(extraout_ECX + 0x3c);
      if ((iVar5 == 2) || (iVar5 == 3)) {
        cVar2 = FUN_0048aa53(unaff_EBP + 8,*(undefined4 *)(unaff_EBP + 0x14),
                             *(undefined4 *)(unaff_EBP + -0x10),*puVar1,iVar5);
        if (cVar2 != '\0') {
          bVar8 = *(int *)(extraout_ECX + 0x3c) == 3;
          goto LAB_0048a35e;
        }
        uVar3 = FUN_00493b85();
        *(undefined1 *)(unaff_EBP + 0x17) = uVar3;
        FUN_00493875();
        if (*(char *)(unaff_EBP + 0x17) != '\0') {
          *(undefined1 *)(*(int *)(extraout_ECX + 0x30) + 0x40) = 1;
        }
      }
      else {
        cVar2 = FUN_00493897(unaff_EBP + -0x14,iVar5,*(undefined4 *)(unaff_EBP + -0x10),0,
                             unaff_EBP + 0x14);
        if (cVar2 == '\0') {
          iVar5 = *(int *)(unaff_EBP + 0x14);
          if (iVar5 != 0) {
            *(int *)(extraout_ECX + 0x60) = iVar5;
            FUN_004864ed(iVar5,0xffffffff);
          }
        }
        else {
          FUN_004939fc(unaff_EBP + -0x14,*(undefined4 *)(extraout_ECX + 0x3c),
                       *(undefined4 *)(unaff_EBP + -0x10),0);
          bVar8 = *(int *)(extraout_ECX + 0x3c) == 1;
LAB_0048a35e:
          if (bVar8) {
            FUN_00492cca();
          }
          uVar4 = FUN_00492b26();
          FUN_00540a5b(uVar4);
          FUN_00540ecf(uVar4);
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      goto LAB_0048a37d;
    }
    iVar5 = FUN_00492b26();
    if (iVar5 < 2) {
      uVar4 = 6;
    }
    else {
      uVar4 = 0x22;
    }
    *(undefined4 *)(extraout_ECX + 0x60) = uVar4;
    FUN_004864ed(uVar4,0xffffffff);
  }
  FUN_00492c37();
LAB_0048a2a5:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

