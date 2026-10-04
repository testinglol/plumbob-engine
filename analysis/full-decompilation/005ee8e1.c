
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ee8e1(void)

{
  int iVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  EnterCriticalSection((LPCRITICAL_SECTION)(extraout_ECX + 0x4e));
  if (DAT_006e5490 < (uint)extraout_ECX[0x57]) {
    uVar2 = FUN_005d4956(*(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_004054fa(uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  else {
    FUN_005d499c(extraout_ECX + 0x13);
    uVar2 = FUN_005d4956(*(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004054fa(uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    (**(code **)(*extraout_ECX + 0x9c))(extraout_ECX[0x69]);
    iVar1 = extraout_ECX[0x69];
    FUN_0052a419(iVar1,iVar1 + 0xc);
    FUN_004734bd(0x3f800000,0,1000,DAT_006e5490);
    FUN_004734bd(0,_DAT_00666c18,1000,DAT_006e5490);
  }
  (**(code **)(*extraout_ECX + 0x168))();
  LeaveCriticalSection((LPCRITICAL_SECTION)(extraout_ECX + 0x4e));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

