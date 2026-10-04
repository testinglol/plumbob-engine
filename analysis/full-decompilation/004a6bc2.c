
void FUN_004a6bc2(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined2 extraout_var;
  int *piVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005d48d9();
  iVar3 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  bVar1 = -0x4e21 < iVar3;
  if (!bVar1) {
    iVar3 = -20000 - iVar3;
  }
  bVar2 = -0x2711 < iVar3;
  if (!bVar2) {
    iVar3 = -10000 - iVar3;
  }
  if ((DAT_006f2a08 != 0) && (*(int *)(DAT_006f2a08 + 0x84) != 0)) {
    if (bVar1) {
      if (bVar2) {
        piVar4 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
        (**(code **)(*piVar4 + 0x7c))(iVar3,iVar3 >> 0x1f,unaff_EBP + -0x18);
        FUN_004d3696(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18));
      }
      else {
        FUN_005d5156(unaff_EBP + -0x18,&DAT_006c08e4,iVar3);
        iVar3 = *(int *)(unaff_EBP + 8);
        FUN_0057a7f7(s_sting_char_winner_006c7224,
                     CONCAT22(extraout_var,*(undefined2 *)(iVar3 + 0xf0)));
        FUN_004d36b5(iVar3,*(undefined4 *)(unaff_EBP + -0x18));
      }
    }
    else {
      FUN_005d5156(unaff_EBP + -0x18,&DAT_006c08e4,iVar3);
      FUN_004d3709(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18));
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

