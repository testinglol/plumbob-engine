
uint FUN_0057348c(void)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  bool bVar4;
  char cVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int iVar9;
  
  FUN_00634c24();
  bVar3 = DAT_006f635c & 1;
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  if (bVar3 == 0) {
    DAT_006f635c = DAT_006f635c | 1;
    FUN_005d4956(&DAT_006cf034);
    FUN_00635543(&LAB_00573761);
  }
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  uVar6 = FUN_005d4c15(unaff_EBP + -0x38,3);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar5 = FUN_005d49dc(uVar6);
  if (cVar5 == '\0') {
    uVar6 = FUN_005d4be4(unaff_EBP + -0x44,3);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    cVar5 = FUN_005d49dc(uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    bVar4 = false;
    if (cVar5 != '\0') goto LAB_00573516;
  }
  else {
LAB_00573516:
    bVar4 = true;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  if (bVar4) {
    FUN_00570d5f();
    uVar7 = FUN_00570fb5(*(undefined4 *)(unaff_EBP + 0xc),0);
    if (uVar7 != 1000) goto LAB_00573544;
LAB_005736a4:
    uVar7 = uVar7 & 0xffffff00;
  }
  else {
LAB_00573544:
    FUN_005b86bd(uVar1);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_00575bc0(unaff_EBP + -0x18,unaff_EBP + -0x68);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      FUN_005b86bd(uVar1);
      *(undefined4 *)(unaff_EBP + -4) = 3;
      FUN_005b86bd(uVar1);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005b86bd(uVar1);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005d4b3c(&DAT_006c0f98,1);
      FUN_005d4b3c(&DAT_006c0f9c,1);
      FUN_005d4b3c(&DAT_006cf030,1);
      iVar8 = FUN_005733e9(unaff_EBP + -0x44);
      if (iVar8 != 0) {
LAB_0057360a:
        FUN_00570d5f();
        iVar8 = FUN_00570fb5(*(undefined4 *)(unaff_EBP + 0xc),0);
        if (iVar8 == 0) {
          iVar8 = unaff_EBP + -0x44;
LAB_00573622:
          FUN_005d499c(iVar8);
LAB_00573646:
          FUN_005b86bd(uVar1);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_00575bc0(unaff_EBP + -0x20,unaff_EBP + -0x68);
          *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x20);
          *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x1c);
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_005b8770();
          if (*(int *)(unaff_EBP + -0x18) != 0) goto LAB_005736ab;
        }
        else {
          if (iVar8 == 1) {
            iVar8 = unaff_EBP + -0x38;
            goto LAB_00573622;
          }
          if (iVar8 == 2) {
            iVar8 = unaff_EBP + -0x2c;
            goto LAB_00573622;
          }
          if (iVar8 != 1000) goto LAB_00573646;
        }
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_005b8770();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        uVar7 = FUN_005b8770();
        goto LAB_005736a4;
      }
      iVar8 = FUN_005733e9(unaff_EBP + -0x38);
      if (iVar8 != 0) goto LAB_0057360a;
      iVar8 = FUN_005733e9(unaff_EBP + -0x2c);
      if (iVar8 != 0) goto LAB_0057360a;
LAB_005736ab:
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    FUN_005b86bd(uVar1);
    *(undefined4 *)(unaff_EBP + -4) = 7;
    FUN_00575bc0(unaff_EBP + -0x20,unaff_EBP + -0x68);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x1c);
    FUN_005b8770();
    iVar8 = *(int *)(unaff_EBP + -0x18);
    if ((iVar8 == 0) || (iVar2 = *(int *)(iVar8 + 0x10), iVar2 == 0)) {
      uVar7 = CONCAT31((int3)((uint)iVar8 >> 8),1);
    }
    else {
      iVar9 = *(int *)(iVar8 + 0x18);
      if (iVar9 == 0) {
        iVar9 = *(int *)(unaff_EBP + 0xc);
      }
      if (*(int *)(iVar8 + 0x1c) != 0) {
        *(int *)(unaff_EBP + 0x10) = *(int *)(iVar8 + 0x1c);
      }
      if (*(int *)(iVar8 + 0x20) != 0) {
        *(int *)(unaff_EBP + 0x14) = *(int *)(iVar8 + 0x20);
      }
      iVar8 = FUN_0057376b(iVar2,*(undefined4 *)(iVar8 + 0x14),iVar9,
                           *(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14));
      uVar7 = (uint)(iVar8 == 0);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar7;
}

