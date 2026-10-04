
void FUN_004a9601(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EBP;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b048c(*(undefined4 *)(unaff_EBP + 0x10));
  uVar1 = FUN_005d51f5(s_UW__RenderPeople_006c7320,0);
  FUN_004b406a(uVar1);
  FUN_00584808(0);
  if (((DAT_006c723f != '\0') && (*(int *)(unaff_ESI + 0x1d4) != *(int *)(unaff_ESI + 0x1d8))) &&
     (iVar2 = FUN_005ce621(1), -1 < iVar2)) {
    for (puVar3 = *(undefined4 **)(unaff_ESI + 0x1d4); puVar3 != *(undefined4 **)(unaff_ESI + 0x1d8)
        ; puVar3 = puVar3 + 1) {
      FUN_004ab779(*puVar3,*(undefined4 *)(unaff_EBP + 0x10));
    }
    FUN_005ce67e();
  }
  uVar1 = FUN_005d51f5(s_UW__Dynamic_006c7314,0);
  FUN_004b406a(uVar1);
  FUN_004b038a(*(undefined4 *)(unaff_ESI + 0x70),*(undefined4 *)(unaff_EBP + 0x10));
  if (*(char *)(unaff_ESI + 0x78) != '\0') {
    *(undefined4 *)(unaff_ESI + 0x7c) = 0;
  }
  if (DAT_006c723e != '\0') {
    FUN_004aa3e7(&DAT_006f0bc0,*(undefined4 *)(unaff_EBP + 0x10));
  }
  if (*(char *)(unaff_ESI + 0x17d) != '\0') {
    for (iVar2 = *(int *)(unaff_ESI + 0x88); iVar2 != *(int *)(unaff_ESI + 0x8c);
        iVar2 = iVar2 + 0x10) {
      FUN_004b06db(iVar2,0xff00,*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 8));
    }
  }
  FUN_004acad0(&DAT_006f0bc0,*(undefined4 *)(unaff_EBP + 0x10));
  FUN_004b048c(*(undefined4 *)(unaff_EBP + 0x10));
  iVar2 = FUN_005ce621(1);
  if (-1 < iVar2) {
    if ((DAT_006c723f != '\0') &&
       (puVar3 = *(undefined4 **)(unaff_ESI + 0x1e0), puVar3 != *(undefined4 **)(unaff_ESI + 0x1e4))
       ) {
      for (; puVar3 != *(undefined4 **)(unaff_ESI + 0x1e4); puVar3 = puVar3 + 1) {
        FUN_004ab779(*puVar3,*(undefined4 *)(unaff_EBP + 0x10));
      }
    }
    FUN_00587d21(*(undefined4 *)(unaff_EBP + 0x10));
    FUN_005ce67e();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

