
void FUN_0057b268(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005d4956(s_EventMappingEquate_006cf450);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0057b37e(unaff_EBP + -0x18,&LAB_0057b12f,extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  FUN_005d4956(s_Patch_006cf448);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0057b37e(unaff_EBP + -0x18,&LAB_0057b0e3,extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  FUN_005d4956(s_Track_006cf440);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_0057b37e(unaff_EBP + -0x18,&LAB_0057b0f6,extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  FUN_005d4956(s_TrackData_006cf434);
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_0057b37e(unaff_EBP + -0x18,&LAB_0057b109,extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  FUN_005d4956(s_GlobalHitList_006cf424);
  *(undefined4 *)(unaff_EBP + -4) = 4;
  FUN_0057b37e(unaff_EBP + -0x24,&LAB_0057b11c,extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  FUN_0057b3ed();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

