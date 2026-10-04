
void FUN_005d5d90(void)

{
  char cVar1;
  int *piVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar2 = (int *)(**(code **)(*extraout_ECX + 0x38))();
  cVar1 = (**(code **)(*piVar2 + 0x14))();
  if (cVar1 == '\0') {
    FUN_005d4956(s_Error_shutting_down_available_se_006d6ef4);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005b86bd(unaff_EBP + -0x18);
    *(undefined ***)(unaff_EBP + -0x28) = &PTR_FUN_00673898;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(unaff_EBP + -0x28,&DAT_006b93f8);
  }
  if (extraout_ECX[0x4e] != 0) {
    (*(code *)**(undefined4 **)(extraout_ECX[0x4e] + 0xc))(1);
    extraout_ECX[0x4e] = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

