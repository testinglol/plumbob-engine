
void FUN_004b3d0e(void)

{
  int iVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_004b04af(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x18));
  *(undefined1 *)(unaff_EBP + -4) = 6;
  iVar1 = FUN_005ce621(1);
  if (-1 < iVar1) {
    FUN_004ab936(*(undefined4 *)(unaff_EBP + 0x18));
    FUN_005ce67e();
    FUN_004b3d55();
    return;
  }
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_004b038a(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x18));
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_004ac916(&DAT_006f0bc0,*(undefined4 *)(unaff_EBP + 0x18));
  FUN_004b3d8b();
  return;
}

