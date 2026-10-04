
void FUN_0050e1eb(void)

{
  short sVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  char *pcVar3;
  
  FUN_00634c24();
  FUN_0046f824(unaff_EBP + -0x188,0,0x104);
  *(undefined ***)(unaff_EBP + -0x194) = &PTR_FUN_006664e8;
  FUN_00425531(unaff_EBP + -0x194);
  sVar1 = *(short *)(extraout_ECX + 0x120);
  if ((sVar1 < 0x15) || (0x1e < sVar1)) {
    if ((sVar1 < 0x28) || (0x30 < sVar1)) {
      if ((sVar1 < 0x51) || (0x59 < sVar1)) {
        if ((sVar1 < 0x5a) || (99 < sVar1)) {
          iVar2 = FUN_0042ba25((int)sVar1);
          if (iVar2 == 0) goto LAB_0050e2b9;
          pcVar3 = s_Houses_NeighborhoodDesc_iff_006c268c;
        }
        else {
          pcVar3 = s_Houses_MTDesc_iff_006c2664;
        }
      }
      else {
        pcVar3 = s_Houses_STDesc_iff_006c2678;
      }
    }
    else {
      pcVar3 = s_Houses_VIDesc_iff_006c26a8;
    }
  }
  else {
    pcVar3 = s_Houses_DTDesc_iff_006c26bc;
  }
  FUN_0046f847(pcVar3,0xffffffff);
LAB_0050e2b9:
  FUN_0046f5cd();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = FUN_0046f71c(unaff_EBP + -0x194,0);
  FUN_004706f0();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (iVar2 == 0) {
    iVar2 = FUN_00470d31(unaff_EBP + -0x3d8,*(short *)(extraout_ECX + 0x120) + 2000,1);
    if (iVar2 == 0) {
      iVar2 = FUN_00471509(1,0xffffffff);
      if (iVar2 != 0) {
        FUN_005d4bbf(iVar2);
      }
      iVar2 = FUN_00471509(2,0xffffffff);
      if (iVar2 != 0) {
        FUN_005d4bbf(iVar2);
      }
    }
    FUN_0046b7ee();
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004712d0();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046b2e6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

