
void FUN_0046c225(void)

{
  undefined4 uVar1;
  undefined1 *extraout_ECX;
  int iVar2;
  int unaff_EBP;
  uint uVar3;
  
  FUN_00634c24();
  FUN_00632b81(1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  uVar1 = DAT_00689070;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00632c55(s___SimLog_txt_006c4b64,2,uVar1);
  if (*(int *)(unaff_EBP + -0x74 + *(int *)(*(int *)(unaff_EBP + -0x7c) + 4)) == 0) {
    uVar3 = -(uint)(unaff_EBP != 0x7c) & unaff_EBP - 0x70U;
    FUN_0046bfb1(uVar3);
    for (iVar2 = *(int *)(extraout_ECX + 4); iVar2 != *(int *)(extraout_ECX + 8);
        iVar2 = iVar2 + 0x2c) {
      FUN_0046bfd7(uVar3);
    }
    FUN_005d4bbf(s_Logging_completed_and_written_to_006c4b20);
  }
  else {
    FUN_005d4bbf(s_File_SimLog_txt_in_the_Sims_dire_006c4ae4);
  }
  if (DAT_006f2a08 != 0) {
    FUN_004f6994(*(undefined4 *)(unaff_EBP + -0x18),s_Sim_Logging_006c4ad8,0,0);
  }
  FUN_0046c3fb(*(undefined4 *)(extraout_ECX + 4),*(undefined4 *)(extraout_ECX + 8));
  FUN_0046c445(*(undefined4 *)(extraout_ECX + 0x10),*(undefined4 *)(extraout_ECX + 0x14));
  *extraout_ECX = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00632c42();
  FUN_00632b08();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

