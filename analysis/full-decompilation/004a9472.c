
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a9472(void)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int extraout_ECX;
  undefined2 *puVar6;
  int unaff_EBP;
  undefined2 *puVar7;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffcc;
  *(int *)(unaff_EBP + -0x24) = extraout_ECX;
  uVar2 = FUN_005d51f5(s_UW__Static_006c734c,0);
  FUN_004b406a(uVar2);
  FUN_004ad0c7(*(undefined4 *)(unaff_EBP + 0x10),0);
  if (((DAT_006e4870 == '\0') && (*(int *)(extraout_ECX + 0x68) != 0)) &&
     (*(int *)(extraout_ECX + 0x6c) != 0)) {
    uVar2 = FUN_005d51f5(s_UW__ClearComposition_006c7334,0);
    FUN_004b406a(uVar2);
    cVar1 = FUN_004b465e();
    if (cVar1 == '\0') {
      puVar6 = *(undefined2 **)(unaff_EBP + 8);
    }
    else {
      iVar5 = extraout_ECX + 0x88;
      FUN_005cf10c(iVar5);
      FUN_005cdecb(iVar5);
      puVar6 = *(undefined2 **)(unaff_EBP + 8);
      puVar7 = puVar6;
      FUN_005cf10c(puVar6);
      FUN_005cce4d(puVar7);
    }
    piVar3 = (int *)FUN_005cf10c();
    if (0 < (int)(piVar3[1] - *piVar3 & 0xfffffff0U)) {
      puVar4 = (undefined4 *)FUN_005cf10c();
      iVar5 = puVar4[1];
      *(undefined4 *)(unaff_EBP + -0x14) = *puVar4;
      puVar4 = (undefined4 *)FUN_005cf10c();
      FUN_004b0597(*puVar4,iVar5 - *(int *)(unaff_EBP + -0x14) >> 4,
                   *(undefined4 *)(unaff_EBP + 0x10));
    }
  }
  else {
    uVar2 = FUN_005d51f5(s_UW__ClearComposition_006c7334,0);
    FUN_004b406a(uVar2);
    puVar6 = *(undefined2 **)(unaff_EBP + 8);
  }
  puVar4 = *(undefined4 **)(unaff_EBP + 0xc);
  *(undefined2 *)(unaff_EBP + -0x18) = puVar6[2];
  *(undefined2 *)(unaff_EBP + -0x14) = puVar6[6];
  uVar2 = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined2 *)(unaff_EBP + -0x16) = *puVar6;
  *(undefined2 *)(unaff_EBP + -0x12) = puVar6[4];
  _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x18);
  _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x14);
  *puVar4 = _DAT_006f0bc0;
  puVar4[1] = _DAT_006f0bc4;
  FUN_004b038a(*(undefined4 *)(extraout_ECX + 0x70),uVar2);
  if (*(char *)(extraout_ECX + 0x78) != '\0') {
    *(undefined4 *)(extraout_ECX + 0x7c) = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b0e8f(*(undefined4 *)(unaff_EBP + 0x10));
  if (*(char *)(extraout_ECX + 0x4c0) == '\0') {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004b048c(*(undefined4 *)(unaff_EBP + 0x10));
    uVar2 = FUN_005d51f5(s_UW__RenderPeople_006c7320,0);
    FUN_004b406a(uVar2);
    FUN_00584808(0);
    if (((DAT_006c723f != '\0') &&
        (*(int *)(extraout_ECX + 0x1d4) != *(int *)(extraout_ECX + 0x1d8))) &&
       (iVar5 = FUN_005ce621(1), -1 < iVar5)) {
      for (puVar4 = *(undefined4 **)(extraout_ECX + 0x1d4);
          puVar4 != *(undefined4 **)(extraout_ECX + 0x1d8); puVar4 = puVar4 + 1) {
        FUN_004ab779(*puVar4,*(undefined4 *)(unaff_EBP + 0x10));
      }
      FUN_005ce67e();
    }
    uVar2 = FUN_005d51f5(s_UW__Dynamic_006c7314,0);
    FUN_004b406a(uVar2);
    FUN_004b038a(*(undefined4 *)(extraout_ECX + 0x70),*(undefined4 *)(unaff_EBP + 0x10));
    if (*(char *)(extraout_ECX + 0x78) != '\0') {
      *(undefined4 *)(extraout_ECX + 0x7c) = 0;
    }
    if (DAT_006c723e != '\0') {
      FUN_004aa3e7(&DAT_006f0bc0,*(undefined4 *)(unaff_EBP + 0x10));
    }
    if (*(char *)(extraout_ECX + 0x17d) != '\0') {
      for (iVar5 = *(int *)(extraout_ECX + 0x88); iVar5 != *(int *)(extraout_ECX + 0x8c);
          iVar5 = iVar5 + 0x10) {
        FUN_004b06db(iVar5,0xff00,*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 8));
      }
    }
    FUN_004acad0(&DAT_006f0bc0,*(undefined4 *)(unaff_EBP + 0x10));
    FUN_004b048c(*(undefined4 *)(unaff_EBP + 0x10));
    iVar5 = FUN_005ce621(1);
    if (-1 < iVar5) {
      if ((DAT_006c723f != '\0') &&
         (puVar4 = *(undefined4 **)(extraout_ECX + 0x1e0),
         puVar4 != *(undefined4 **)(extraout_ECX + 0x1e4))) {
        for (; puVar4 != *(undefined4 **)(extraout_ECX + 0x1e4); puVar4 = puVar4 + 1) {
          FUN_004ab779(*puVar4,*(undefined4 *)(unaff_EBP + 0x10));
        }
      }
      FUN_00587d21(*(undefined4 *)(unaff_EBP + 0x10));
      FUN_005ce67e();
    }
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return;
  }
  FUN_004b1779(*(undefined4 *)(unaff_EBP + 0x10));
  FUN_004a9601();
  return;
}

