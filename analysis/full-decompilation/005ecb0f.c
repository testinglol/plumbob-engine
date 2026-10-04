
bool FUN_005ecb0f(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = (int *)FUN_005ef4c8();
  iVar2 = (**(code **)(*piVar1 + 0x28))(piVar1);
  if (iVar2 == 0) {
    InvalidateRect((HWND)0x0,(RECT *)0x0,0);
  }
  else {
    *(int *)(unaff_EBP + -0x14) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x10))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2 == 0;
}

