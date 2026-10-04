
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00417121(void)

{
  int iVar1;
  int iVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = FUN_00413003(*(undefined4 *)(unaff_EBP + 8));
  if (iVar1 == 0) {
    FUN_0041308b();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004130d2(*(undefined4 *)(unaff_EBP + 8),1);
    *(undefined4 *)(unaff_EBP + -0x10) = 0x40;
    iVar1 = FUN_00412f9f(s_IFF_FILE_1_0_TYPE_FOLLOWED_BY_SI_006c1ff0,unaff_EBP + -0x10);
    FUN_00413154();
    _DAT_006e48a8 = 1;
    iVar2 = (**(code **)(*extraout_ECX + 0xc))(*(undefined4 *)(unaff_EBP + 8),1);
    if (iVar2 == 0) {
      if ((char)extraout_ECX[10] == '\0') {
        iVar2 = extraout_ECX[6];
        extraout_ECX[6] = extraout_ECX[7];
        extraout_ECX[7] = iVar2;
        *(undefined1 *)(extraout_ECX + 10) = 1;
      }
      FUN_00416e18(extraout_ECX);
      if ((char)extraout_ECX[10] != '\0') {
        iVar2 = extraout_ECX[6];
        extraout_ECX[6] = extraout_ECX[7];
        extraout_ECX[7] = iVar2;
        *(undefined1 *)(extraout_ECX + 10) = 0;
      }
      (**(code **)(*extraout_ECX + 0x18))();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    _DAT_006e48a8 = 0;
    FUN_004130c0();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1;
}

