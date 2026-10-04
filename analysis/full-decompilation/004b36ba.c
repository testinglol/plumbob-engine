
void FUN_004b36ba(void)

{
  int iVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_004b04af(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x14));
  *(undefined1 *)(unaff_EBP + -4) = 7;
  iVar1 = FUN_005ce621(1);
  if (-1 < iVar1) {
    FUN_004ab936(*(undefined4 *)(unaff_EBP + 0x14));
    FUN_005ce67e();
    FUN_004b36fd();
    return;
  }
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_004b038a(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x14));
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_004ac916(&DAT_006f0bc0,*(undefined4 *)(unaff_EBP + 0x14));
  FUN_004b372f();
  return;
}

