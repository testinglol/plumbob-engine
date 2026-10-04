
void FUN_004848ae(void)

{
  int *extraout_ECX;
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  iVar2 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = 0xc;
  do {
    if (*(undefined4 **)(iVar2 + *extraout_ECX) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(iVar2 + *extraout_ECX))(1);
    }
    iVar2 = iVar2 + 4;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_006321f0(*extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004933bd();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

