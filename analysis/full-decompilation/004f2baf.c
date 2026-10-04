
void FUN_004f2baf(void)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  iVar1 = extraout_ECX + 0xb4;
  if (*(int *)(extraout_ECX + 0xb8) == *(int *)(extraout_ECX + 0xb4)) {
    FUN_005d4bbf(&DAT_006c5bc4);
    FUN_005b86bd(iVar1);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    sVar2 = _strlen(s_GameData_Scenario_tds_006cac84);
    FUN_00412d8a(s_GameData_Scenario_tds_006cac84,s_GameData_Scenario_tds_006cac84 + sVar2);
    iVar3 = FUN_00635845(*(undefined4 *)(unaff_EBP + -0x18),&DAT_006c7590);
    if (iVar3 != 0) {
      FUN_0063558d(iVar3);
      FUN_005d499c(iVar1);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      goto LAB_004f2c5f;
    }
    MessageBoxA((HWND)0x0,DAT_006f27d0,DAT_006f27c0,0);
    FUN_00637cca(0xffffffff);
  }
  FUN_005d499c(iVar1);
LAB_004f2c5f:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

