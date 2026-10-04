
void FUN_0050e386(void)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  char *pcVar4;
  undefined4 uVar5;
  
  FUN_00634c24();
  FUN_005d4bbf(*(undefined4 *)(*(int *)(extraout_ECX + 0xe8) + 0xe4));
  FUN_005d4bbf(*(undefined4 *)(*(int *)(extraout_ECX + 0xe4) + 0xe4));
  FUN_0046f824(unaff_EBP + -0x18c,0,0x104);
  *(undefined ***)(unaff_EBP + -0x198) = &PTR_FUN_006664e8;
  FUN_00425531(unaff_EBP + -0x198);
  sVar1 = *(short *)(extraout_ECX + 0x120);
  if ((sVar1 < 0x15) || (0x1e < sVar1)) {
    if ((sVar1 < 0x28) || (0x30 < sVar1)) {
      if ((sVar1 < 0x51) || (0x59 < sVar1)) {
        if ((sVar1 < 0x5a) || (99 < sVar1)) {
          iVar2 = FUN_0042ba25((int)sVar1);
          if (iVar2 == 0) goto LAB_0050e489;
          pcVar4 = s_Houses_NeighborhoodDesc_iff_006c268c;
        }
        else {
          pcVar4 = s_Houses_MTDesc_iff_006c2664;
        }
      }
      else {
        pcVar4 = s_Houses_STDesc_iff_006c2678;
      }
    }
    else {
      pcVar4 = s_Houses_VIDesc_iff_006c26a8;
    }
  }
  else {
    pcVar4 = s_Houses_DTDesc_iff_006c26bc;
  }
  FUN_0046f847(pcVar4,0xffffffff);
LAB_0050e489:
  FUN_0046f5cd();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = FUN_0046f71c(unaff_EBP + -0x198,1);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
  FUN_004706f0();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (*(int *)(unaff_EBP + -0x10) == 0) {
    FUN_00470d31(unaff_EBP + -0x3dc,*(short *)(extraout_ECX + 0x120) + 2000,1);
    uVar5 = 0xffffffff;
    uVar3 = FUN_004096c2(0xffffffff);
    FUN_0047132c(1,uVar3,uVar5);
    uVar5 = 0xffffffff;
    uVar3 = FUN_004096c2(0xffffffff);
    FUN_0047132c(2,uVar3,uVar5);
    FUN_0047078e();
    FUN_0046b7ee();
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004712d0();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046b2e6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

