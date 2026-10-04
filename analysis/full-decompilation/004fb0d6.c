
void FUN_004fb0d6(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  piVar2 = *(int **)(extraout_ECX + 0xf0);
  *(int **)(unaff_EBP + -0x10) = piVar2;
  (**(code **)(*piVar2 + 4))();
  cVar1 = *(char *)(extraout_ECX + 0xf6);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (cVar1 == '\0') {
    DAT_006f29f0 = GetCurrentThreadId();
    if (DAT_006c9f58 != '\0') {
      *(undefined1 *)(extraout_ECX + 0xf6) = 1;
      iVar3 = FUN_00637dbd(0,0,FUN_004fb5a1,extraout_ECX,0,extraout_ECX + 0x124);
      *(int *)(extraout_ECX + 0x120) = iVar3;
      if ((iVar3 != 0) && (iVar3 != -1)) goto LAB_004fb158;
      DAT_006c9f58 = '\0';
    }
    FUN_004fb5a1(extraout_ECX);
  }
LAB_004fb158:
  iVar3 = *piVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar3 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

