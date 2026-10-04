
undefined4 * FUN_0050d78c(void)

{
  undefined1 uVar1;
  short sVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  char *pcVar4;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d48d9();
  uVar1 = *(undefined1 *)(unaff_EBP + 0xc);
  extraout_ECX[0x40] = 0;
  sVar2 = *(short *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *extraout_ECX = &PTR_FUN_0066b59c;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x3a] = 0;
  extraout_ECX[0x3b] = 0;
  extraout_ECX[0x3c] = 0;
  extraout_ECX[0x3d] = 0;
  extraout_ECX[0x3f] = 0;
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x41] = 0;
  *(short *)(extraout_ECX + 0x48) = sVar2;
  *(undefined1 *)(extraout_ECX + 0x38) = uVar1;
  if ((sVar2 < 0x15) || (0x1e < sVar2)) {
    if ((sVar2 < 0x28) || (0x30 < sVar2)) {
      if ((sVar2 < 0x51) || (0x59 < sVar2)) {
        if ((sVar2 < 0x5a) || (99 < sVar2)) {
          iVar3 = FUN_0042ba25((int)sVar2);
          if (iVar3 == 0) goto LAB_0050d8cc;
          FUN_005d4bbf(s_A_Neighborhood_Lot_006cc7d4);
          pcVar4 = s_Its_a_wonderful_day_in_the_neigh_006cc7a8;
        }
        else {
          FUN_005d4bbf(s_A_Magicland_Lot_006cc814);
          pcVar4 = s_A_magic_place_to_visit_for_a_gre_006cc7e8;
        }
        goto LAB_0050d8c1;
      }
      pcVar4 = s_A_Studiotown_Lot_006cc84c;
    }
    else {
      pcVar4 = s_A_Vacation_Lot_006cc860;
    }
    FUN_005d4bbf(pcVar4);
    pcVar4 = s_A_nice_place_to_visit_for_a_grea_006cc824;
  }
  else {
    FUN_005d4bbf(s_A_Downtown_Lot_006cc89c);
    pcVar4 = s_A_nice_place_to_visit_in_beautif_006cc870;
  }
LAB_0050d8c1:
  FUN_005d4bbf(pcVar4);
LAB_0050d8cc:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

