
void FUN_004fb49a(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (((char)DAT_006fe8bc[0x4f] != '\0') && (*(int *)(extraout_ECX + 0x128) == 0)) {
    piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x14))();
    uVar2 = FUN_00412a04(unaff_EBP + -0x24,extraout_ECX + 0xcc,
                         s_Music_modes_load_loadloop_wav_006cbfbc);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005b86bd(uVar2);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_00401729();
    uVar2 = (**(code **)(*piVar1 + 0x5c))(unaff_EBP + -0x18,0);
    *(undefined4 *)(extraout_ECX + 0x128) = uVar2;
    iVar3 = FUN_004e609e();
    if (iVar3 != 0) {
      iVar3 = FUN_004e62e0();
      if ((iVar3 != 0) && (*(int *)(&DAT_006697bc + iVar3 * 4) != 0)) {
        (**(code **)(**(int **)(extraout_ECX + 0x128) + 0x20))
                  (*(int *)(&DAT_006697bc + iVar3 * 4),1,1);
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

