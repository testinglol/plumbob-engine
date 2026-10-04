
void FUN_004d393d(void)

{
  int *piVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = *(int **)(extraout_ECX + 0x1164);
  iVar2 = *piVar1;
  if (*(char *)(unaff_EBP + 8) == '\0') {
    (**(code **)(iVar2 + 0x98))();
    FUN_005ddfdc(0);
    FUN_005d4956(s_Event_Log_006c7cdc);
    iVar2 = *piVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    (**(code **)(iVar2 + 0x9c))(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  else {
    (**(code **)(iVar2 + 0x94))();
    FUN_005ddfdc(1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

